#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> road;
int n, l;

int pass(int i, int j, int inext, int jnext){
	// false: 내리막길 중
	bool flag = true;
	// 현재 몇번 째 평지인지
	int floor = 1;
	i+=inext; j+=jnext;
	while(i < n && j < n){
		// 전꺼랑 비교
		if(road[i][j] == road[i-inext][j-jnext]) floor++;
		// 오르막길
		else if(flag && road[i][j] - road[i-inext][j-jnext] == 1){
			if(floor >= l) floor = 1;
			else return 0;
		}
		// 내리막길
		else if(flag && road[i][j] - road[i-inext][j-jnext] == -1){
			floor = 1;
			flag = false;
		}
		// 급경사
		else return 0;
		// 내리막길 다 내려왔는지 체크
		if(!flag && floor >= l){
			floor = 0;
			flag = true;
		}
		i+=inext; j+=jnext;
	}
	// 다 안내려왔으면 false
	if(!flag) return 0;
	return 1;
}

int main(){
	int cnt = 0;
	// input
	cin>>n>>l;
	road = vector<vector<int>>(n,vector<int>(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>road[i][j];
	// check road
	for(int i=0; i<n; i++){
		cnt += pass(i, 0, 0, 1);
		cnt += pass(0, i, 1, 0);
	}
	// print
	cout<<cnt<<'\n';
	return 0;
}