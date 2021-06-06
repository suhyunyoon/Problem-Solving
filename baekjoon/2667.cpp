#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> map;
vector<int> cnt;
int n;

int dfs(int i, int j, int index){
	map[i][j] = index;
	cnt[index-2]++;

	if(i > 0 && map[i-1][j] == 1) dfs(i-1, j, index);
	if(i < n-1 && map[i+1][j] == 1) dfs(i+1, j, index);
	if(j > 0 && map[i][j-1] == 1) dfs(i, j-1, index);
	if(j < n-1 && map[i][j+1] == 1) dfs(i, j+1, index);
	
	return 0;
}

int main(){
	char ch;
	// input
	cin>>n;
	map = vector<vector<int>>(n, vector<int>(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			cin>>ch;
			map[i][j] = (int)(ch - '0');
		}
	// dfs & edge따로 저장
	int index = 2;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 1){
				cnt.push_back(0);
				dfs(i, j, index);
				index++;
			}
		}
	}
	sort(cnt.begin(), cnt.end());
	cout<<cnt.size()<<'\n';
	for(int i=0; i<cnt.size(); i++)
		cout<<cnt[i]<<'\n';
	return 0;
}