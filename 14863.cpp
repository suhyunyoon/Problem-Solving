#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Point{
	public:
	int wtime;
	int wmoney;
	int btime;
	int bmoney;
	Point(int wt, int wm, int bt, int bm){
		wtime = wt; wmoney = wm;
		btime = bt; bmoney = bm;
	}
};
int dp[101][100001];
vector<Point> arr;
int n, k;
int dfs(int i, int minLeft){
	if(i >= n) return 0;
	if(minLeft <= 0) return -2;
	int &ret = dp[i][minLeft];
	if(ret != -1) return ret;
	
	ret = -2;
	if(minLeft >= arr[i].wtime && dfs(i+1, minLeft - arr[i].wtime) != -2)
		ret = max(ret, dfs(i+1, minLeft - arr[i].wtime) + arr[i].wmoney);
	if(minLeft >= arr[i].btime && dfs(i+1, minLeft - arr[i].btime) != -2)
		ret = max(ret, dfs(i+1, minLeft - arr[i].btime) + arr[i].bmoney);
	return ret;
}

int main(){
	int wt, wm, bt, bm;
	// input
	cin>>n>>k;
	for(int i=0; i<n; i++)
		for(int j=0; j<=k; j++)
			dp[i][j] = -1;
	for(int i=0; i<n; i++){
		cin>>wt>>wm>>bt>>bm;
		arr.push_back(Point(wt,wm,bt,bm));
	}
	cout<<dfs(0,k)<<'\n';
	return 0;
}