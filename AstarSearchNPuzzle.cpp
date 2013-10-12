#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#define MAXN 500
#define INF 1e+9

using namespace std;


const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
string direction[] = { "UP","LEFT","RIGHT","DOWN"};
typedef vector<vector<int> > state;

map<state , int > dist;
map<state, int > fScore;

map<state , int > visited;

state goal,initial;

int K,initx,inity;

void prepare(){
	cin >> K;
	initial = state(K);
	for(int i = 0 ; i < K ; ++i)
		for(int j = 0 ; j < K ; ++j){
			int x;
			cin >> x;
			if(x==0){
				initx=i,inity=j;
			}
			initial[i].push_back(x);
		}
	goal = state(3);
	for(int i = 0 ; i < K ; ++i)
		for(int j = 0 ; j < K ; ++j) goal[i].push_back(i*K+j);
			
}

void debug(state s){
	for(int i = 0 ; i < K ; ++i){
		for(int j = 0 ; j < K ; ++j)
			cout << s[i][j] << " " ;
		cout << endl;
	}
}

int heuristic(state f){
	int r = 0;
	for(int i = 0 ; i < K ; ++i){
		for(int j = 0 ; j < K ; ++j){
			r += abs(i - f[i][j]/K) + abs(j-f[i][j]%K);
		}
	}
	return r;
}



struct node{
	state s;
	int f_score;
	int fx,fy;
	inline bool operator>(const node & rhs) const{
		return f_score > rhs.f_score;
	}
	node(state _s, int _f_score,int _fx, int _fy):s(_s),f_score(_f_score),fx(_fx),fy(_fy){}
	bool operator==(const node & other){
		for(int i = 0 ; i < K ; ++i)
			for(int j =0 ; j < K ; ++j)
				if(s[i][j]!=other.s[i][j])
					return false;
		return true;
	}
};

map<state , state> PREV;
map<state , string> PREVstring;
void construct_path(state current){
	vector<string> dirs;

	while(PREVstring[current]!="Fin"){
		//debug(current);
		//cout << endl;
		dirs.push_back(PREVstring[current]);
		current = PREV[current];
	}
	reverse(dirs.begin(),dirs.end());	
	cout << dirs.size() << endl;
	for(int i = 0 ; i < dirs.size() ; ++i){
		cout << dirs[i] << endl;
	}

}

bool ok(int x,int y){
	if(x>=0 and x<K and y>=0 and y <K)
		return true;
	return false;
}

void aStar(){
    priority_queue<node ,vector<node> , greater< node> > Q;
    dist[initial] = fScore[initial] = 0;
    PREVstring[initial] = "Fin";
    Q.push(node(initial,0,initx,inity));

    while(!Q.empty()){
    	node current = Q.top();
    	if(current.s == goal){
    		construct_path(current.s);
    		return;
    	}	
    	state orig = current.s;
    	visited[current.s] = 1;
    	Q.pop();
    	for(int i = 0 ; i < 4 ; ++i){
    		if(ok(current.fx+dx[i],current.fy+dy[i])){
    			int rx = current.fx+dx[i],ry= current.fy+dy[i];
    			swap(current.s[current.fx][current.fy],current.s[rx][ry]);

    			int g_score = 1+dist[orig];
    			int f_score = g_score + heuristic(current.s);

    			if(visited[current.s]!=0 && f_score >= fScore[current.s]){
    				swap(current.s[rx][ry],current.s[current.fx][current.fy]);
    				continue;
    			}

    			if(visited[current.s]==0 || f_score < fScore[current.s]){
    				PREV[current.s] = orig;
    				PREVstring[current.s] = direction[i];
    				dist[current.s] = g_score;
    				fScore[current.s] = f_score;
    				Q.push(node(current.s,f_score,rx,ry));
    			}
    			swap(current.s[rx][ry],current.s[current.fx][current.fy]);
    		}
    	}
    }
    cout <<"A star failed" << endl;
}






int main(){
	freopen("in.txt","r",stdin);
	prepare();
	aStar();

}
