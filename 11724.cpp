#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> graph;
vector<int> group;
int cnt;

int dfs(int node){
	int len = graph[node].size();
	for(int i=0; i<len; i++)
		if(!group[graph[node][i]]){
			group[graph[node][i]] = group[node];
			dfs(graph[node][i]);
		}
	return 0;
}

int main(){
	int n, m, x, y;
	// init&input
	cin>>n>>m;
	graph = vector<vector<int>>(n, vector<int>());
	group = vector<int>(n, 0);
	for(int i=0; i<m; i++){
		cin>>x>>y;
		// 0-base
		x--; y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	// dfs
	cnt = 1;
	for(int i=0; i<n; i++){
		// group[i]가 0이면 dfs함
		if(!group[i]){
			group[i] = cnt++;
			dfs(i);
		}
	}
	cout<<cnt-1<<'\n';
	return 0;
}