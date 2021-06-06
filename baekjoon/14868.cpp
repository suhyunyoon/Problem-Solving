#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
	public:
	int i, j, date;
	Node(int i, int j, int d){ this->i = i; this->j = j; this->date = d; }
};
vector<vector<int>> arr;
vector<int> par;
queue<Node> bfs;
int n, k, K;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int find(int v){
	if(v == par[v]) return v;
	return par[v] = find(par[v]);
}

bool merge(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return true;
	par[u] = v;
	return false;
}

int main(){
	int x,y, date;
	// input
	cin>>n>>k;
	arr = vector<vector<int>>(n,vector<int>(n, -1));
	K = k;
	for(int i=0; i<k; i++){
		cin>>x>>y;
		arr[x-1][y-1] = i;
		// init
		bfs.push(Node(x-1,y-1,0));
		par.push_back(i);
	}
	// bfs
	date = 0;
	while(bfs.size()){
		Node &temp = bfs.front();
		// 먼저 문명 겹치는지 만나는지 체크
		for(int j=0; j<4; j++){
			if(temp.i+di[j] >= 0 && temp.i+di[j] <= n-1 && temp.j+dj[j] >= 0 && temp.j+dj[j] <= n-1 && arr[temp.i+di[j]][temp.j+dj[j]] != -1){
				if(!merge(arr[temp.i][temp.j], arr[temp.i+di[j]][temp.j+dj[j]])){
					K--;
					if(K == 1){
						cout<<date<<'\n';
						return 0;
					}
				}
			}
		}
		// 4방위
		for(int i=0; i<4; i++){
			if(temp.i+di[i] >= 0 && temp.i+di[i] <= n-1 && temp.j+dj[i] >= 0 && temp.j+dj[i] <= n-1){
				// 새로 개척
				if(arr[temp.i+di[i]][temp.j+dj[i]] == -1){
					arr[temp.i+di[i]][temp.j+dj[i]] = arr[temp.i][temp.j];
					// 새 노드 큐에 삽입
					bfs.push(Node(temp.i+di[i], temp.j+dj[i], temp.date+1));
					if(temp.date >= date) date++;
				}
				// 문명 합병 시도
				else if(!merge(arr[temp.i][temp.j], arr[temp.i+di[i]][temp.j+dj[i]])){
					K--;
					if(K == 1){
						cout<<date<<'\n';
						return 0;
					}
				}
			}
		}
		bfs.pop();
	}
	return 0;
}