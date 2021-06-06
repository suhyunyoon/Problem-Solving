#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector<vector<int>> map;
int n, m;

int dfs(int i, int j, int index){
	map[i][j] = index;
	
	if(i > 0 && map[i-1][j] == 1) dfs(i-1, j, index);
	if(i < m-1 && map[i+1][j] == 1) dfs(i+1, j, index);
	if(j > 0 && map[i][j-1] == 1) dfs(i, j-1, index);
	if(j < n-1 && map[i][j+1] == 1) dfs(i, j+1, index);
	if(i > 0 && j > 0 && map[i-1][j-1] == 1) dfs(i-1, j-1, index);
	if(i > 0 && j < n-1 && map[i-1][j+1] == 1) dfs(i-1, j+1, index);
	if(i < m-1 && j > 0 && map[i+1][j-1] == 1) dfs(i+1, j-1, index);
	if(i < m-1 && j < n-1 && map[i+1][j+1] == 1) dfs(i+1, j+1, index);
	
	return 0;
}

int main(){
	// input
	while(true){
		cin>>n>>m;
		if(n==0 && m==0) break;
		map = vector<vector<int>>(m, vector<int>(n,0));
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				cin>>map[i][j];
		// dfs & edge따로 저장
		int index = 2;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(map[i][j] == 1){
					dfs(i, j, index);
					index++;
				}
			}
		}
	    cout<<(index-2)<<'\n';
	    map.clear();
	}
	return 0;
}