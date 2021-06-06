#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> pcs;
vector<bool> infected;
queue<int> bfs;

int main(){
	int n, k, u, v, cnt = 0;
	cin>>n>>k;
	pcs = vector<vector<int>>(n,vector<int>());
	infected = vector<bool>(n, false);
	for(int i=0; i<k; i++){
		cin>>u>>v;
		u--; v--;
		pcs[u].push_back(v);
		pcs[v].push_back(u);
	}
	//
	bfs.push(0); infected[0] = true;
	while(bfs.size()){
		int temp = bfs.front();
		for(int i=0; i<pcs[temp].size(); i++){
			if(!infected[pcs[temp][i]]){
				infected[pcs[temp][i]] = true;
				cnt++;
				bfs.push(pcs[temp][i]);
			}
		}
		
		bfs.pop();
	}
	cout<<cnt<<'\n';
	return 0;
}

// ans

int find(int x){
	if(x == parent[x]){
		return x;
	}else
		return parent[x] = find(parent[x]);
}
void union(int x, inty){
	x = find(x);
	y = find(y);
	if(x!=y){
		parent[y] = x;
	}
}

int main_ans(){
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		parent[i] = i;
	while(m--){
		int x,y;
		cin>>x>>y;
		union(x,y);
	}
	int ans = 0;
	for(int i=2; i<=n; i++){
		if(find(1) == find(i)){
			ans += 1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}