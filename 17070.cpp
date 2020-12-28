#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> arr;

// type: 0:- 1:\ 2:|
int f(int i, int j, int type){
	if(i==n-1 && j==n-1) return 1;
	int ans = 0;
	// 아래
	if(i<n-1 && !arr[i+1][j] && type != 0){
		arr[i+1][j] = 1;
		ans += f(i+1, j, 2);
		arr[i+1][j] = 0;
	}
	// 오른쪽
	if(j<n-1 && !arr[i][j+1] && type != 2){
		arr[i][j+1] = 1;
		ans += f(i, j+1, 0);
		arr[i][j+1] = 0;
	}
	// 대각선
	if(i<n-1 && j<n-1 && !(arr[i+1][j+1]+arr[i+1][j]+arr[i][j+1])){
		arr[i+1][j+1] = 1; arr[i+1][j] = 1; arr[i][j+1] = 1;
		ans += f(i+1, j+1, 1);
		arr[i+1][j+1] = 0; arr[i+1][j] = 0; arr[i][j+1] = 0;
	}
	return ans;
}

int main(){
	cin>>n;
	arr = vector<vector<int>>(n, vector<int>(n, 0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>arr[i][j];
	arr[0][0] = 1; arr[0][1] = 1;
	cout<<f(0,1,0)<<'\n';
	return 0;
}