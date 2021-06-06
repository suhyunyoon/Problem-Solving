#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int dfs(vector<vector<int>> &tree, vector<int> &parent, vector<pair<int, int>> &dp, int index){
	dp[index].first = 0;
	dp[index].second = 1;
	//cout<<index<<'\n';
	for(int i=0; i<tree[index].size(); i++){
		if(tree[index][i] != parent[index]){
			parent[tree[index][i]] = index;
			dfs(tree, parent, dp, tree[index][i]);
			dp[index].first += dp[tree[index][i]].second;
			dp[index].second += (dp[tree[index][i]].first < dp[tree[index][i]].second ? dp[tree[index][i]].first : dp[tree[index][i]].second);
		}
	}
	return 0;
}

int main(){
	int n, u, v, first = 0;
	cin>>n;
	vector<vector<int>> tree(n, vector<int>());
	vector<int> parent(n, -1);
	vector<pair<int,int>> dp(n, make_pair(0,0));
	// input
	for(int i=0; i<n-1; i++){
		cin>>u>>v;
		tree[u-1].push_back(v-1);
		tree[v-1].push_back(u-1);
	}
	// set first node
	while(!tree[first].size()){ first++; }
	dfs(tree, parent, dp, first);
	int ans = (dp[first].first < dp[first].second ? dp[first].first : dp[first].second);
	cout<<ans<<'\n';
	return 0;
}
