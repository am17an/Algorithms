#include <iostream>
#include <cstdio>
#include <cassert>
#define DEBUG_ON
#ifdef DEBUG_ON
#define DEBUG(x) \
  std::cout << x << std::endl
#else
#define DEBUG(x) do{}while(0);
#endif

// TODO : extend this to support both min and max heap through templates
// TODO : test edge cases
// TODO : measure perf compared to priority_queue<int, vector<int> > 

class Heap{ 

public:  
  Heap(size_t size)
    : arr(new int[size])
    , nElements(0)
    , freePos(0)
  {}

  void add(int data){
    arr[freePos] = data;
    ++ nElements;
    if(freePos && arr[freePos] > arr[parent(freePos)]){
      siftUp(freePos);
    }
    ++ freePos;
  }

  int top() const{
    return arr[0];
  }

  void pop(){
    if(!isEmpty()){
      arr[0] = arr[freePos-1]; // This could be a dirty value
      -- nElements;
      -- freePos;
      // swap with larger child
      if(arr[0] < arr[1] || arr[0] < arr[2]){
        int swapWith = 1;
        if(arr[2] > arr[1] ) swapWith = 2;

        std::swap(arr[0], arr[swapWith]);

        siftDown(swapWith);
      }
    }
  }

  bool isEmpty() const{
    return 0 == nElements;
  }

  size_t size() const{
    return nElements;
  }

  void prettyPrint() const {
    for(int i = 0 ; i < nElements ; ++i){
      std:: cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }

  int * testInspect(){
    return arr;
  }

private:
  int * arr;
  size_t nElements;
  int freePos;

  int left(int idx) const{
    return (idx<<1) + 1;
  }

  int right(int idx) const{
    return (idx<<1) + 2;
  }

  int parent(int idx) const{
    return (idx-1)>>1;
  }

  void siftUp(int idx){
    if(idx!= 0 && (arr[idx] > arr[parent(idx)])){
      std::swap(arr[idx], arr[parent(idx)]);
      siftUp(parent(idx));
    }
    return;
  }

  void siftDown(int idx){
    if(arr[idx] < arr[left(idx)] || arr[idx] < arr[right(idx)]){
      // swap with larger child
      int swapWith = arr[left(idx)];

      if(arr[swapWith] < arr[right(idx)]) swapWith = right(idx);

      std::swap(arr[idx], arr[swapWith]);

      siftDown(swapWith);
    }
  }
};

#define SIZE(a) \
  sizeof(a)/sizeof(int) \

void arrayEqual(int a[], int b[],size_t size){
  for(int i = 0 ; i < size ; ++i)
    assert(a[i] == b[i]);
}

int main(){
  Heap * heap = new Heap(100);
  
  int a[] = {9,6,4,3}; 
  heap->add(3);
  heap->add(4);
  heap->add(9);
  heap->add(6);
  DEBUG("Array Equal Test...");
  arrayEqual(heap->testInspect(), a, 4);

  DEBUG("Top test...");
  heap->add(10000);
  assert(heap->top() ==  10000);

  DEBUG("Pop test.. ");
  heap->add(0xffff);
  heap->add(0xfffe);
  heap->pop();
  assert(heap->top() == 0xfffe);

  DEBUG("All tests passed");
}
