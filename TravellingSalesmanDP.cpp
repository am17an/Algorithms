#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#define mp make_pair
#define FOR(i,n) for(int i = 0 ; i< (int) n;i++)
using namespace std;

float dist[27][27];

map<pair<int,int>, float> next;
map<pair<int,int>, float> curr;

struct Point
{
    float x;
    float y;
};


float eucl_dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (b.y-a.y)*(b.y-a.y));
}

vector<int> subsets[30];



Point Points[27];

int main()
{
    int n;
    cin >> n;
    float INF = 100000000;

    FOR(i,n)
    {
        float x1,x2;
        cin >> x1 >> x2;
        Points[i].x = x1, Points[i].y = x2;
    }
    
    FOR(i,n)
    FOR(j,n)
    {
        dist[i][j] = eucl_dist(Points[i],Points[j]);
    }


    
    //Getting The Cardinatily of Sets.
    FOR(mask,(1<<n))
    {
        subsets[__builtin_popcount(mask)].push_back(mask);
    }
    
    for(int i = 1; i < n ; i++) curr[mp(1<<(i-1),i)]=dist[0][i];
  
    
    for(int m = 2; m < n ; m++)
    {
        for(int i = 0 ; i < subsets[m].size(); i++)
        {
            int set = subsets[m][i];

            for(int j = 1 ; j < n ; j++)
            {


                if((set & (1<<(j-1)))!=0)
                {
                    next[mp(set,j)]=INF;
                    for(int k = 1 ; k < n ; k++)
                    {
                        if((set & (1<<(k-1)))!=0 and j!=k){
                             next[mp(set,j)]= min(next[mp(set,j)],curr[mp(set & ~(1<<(j-1)),k)] + dist[k][j]);
                            
                        }
                    }

                   

            }
        }
        curr = next;
        next.clear();
    }
    float ans = INF;
    for(int i = 1; i < n ; i++) ans = min(ans,curr[mp((1<<(n-1))-1,i)] + dist[0][i]);
    cout << ans << endl;
}

