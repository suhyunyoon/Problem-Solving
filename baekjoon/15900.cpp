#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
	public:
	int num;
	int parent;
	int depth;
	Node(int n, int p, int d){num = n; parent = p; depth = d;}
};

int main(){
	vector<vector<int>> tree;
	queue<Node> bfs;
	int n, u, v, sum = 0;
	// input
	cin>>n;
	tree = vector<vector<int>>(n, vector<int>());
	for(int i=0; i<n-1; i++){
		cin>>u>>v;
		// 0-base
		tree[u-1].push_back(v-1);
		tree[v-1].push_back(u-1);
	}
	// bfs
	bfs.push(Node(0,-1,0));
	while(bfs.size()){
		Node &temp = bfs.front();
		int len = tree[temp.num].size();
		// leaf 일때
		if(len == 1) sum += temp.depth;
		// leaf 아닐때
		for(int i=0; i<len; i++){
			if(tree[temp.num][i] != temp.parent){
				bfs.push(Node(tree[temp.num][i], temp.num, temp.depth+1));
			}
		}
		bfs.pop();
	}
	// 홀수면 이김
	if(sum%2) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}