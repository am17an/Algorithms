#include <iostream>
#include <cstdio>

using namespace std;

//Complexity - O(K+N) depending on bad the string is 

void fillFailureFunction(const string & pattern, int * F){
	F[0]=F[1] =0;
	int m = pattern.size();
	for(int i = 2; i <= m ; ++i){

		int j = F[i-1];

		for(;;){

			if(pattern[j] == pattern[i-1]){
				F[i]=j+1;
				break;
			}
			// if we can't do anything else now
			if(j==0){
				F[i] = 0;
				break;
			}
			// let's try the prefix of the prefix
			j = F[j];
		}
	}

}

bool KMP(const string & text, const string & pattern){
	
	int n=text.size(), m = pattern.size();
	int *F = new int[m+2];
	
	fillFailureFunction(pattern,F);

	int i = 0; // current position in string
	int j = 0; // current state of automaton
	
	bool flag = false;
	for(;;){

		if(i==n){ break;}
		if(text[i] == pattern[j]){
			// we can move ahead
			i++;
			j++;

			if(j==m){ flag = true; break;} 
		}

		else if(j>0) j = F[j];
	       	else i++; 
	}
	delete F;
	if(flag) return true;
	else return false;
}

int main(){
	if(KMP("aUeCfDelF","UeC")) cout <<" Pattern has been found" << endl;
}
