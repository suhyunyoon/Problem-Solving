#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,t ;
	vector<int> arr;
	vector<int> dp;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>t;
		arr.push_back(t);
	}
	dp = vector<int>(n, 0);
	int max = 0; dp[0] = arr[0];
	for(int i=1; i<n; i++){
		max = 0;
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j] && dp[j] > max) max = dp[j];
		}
		dp[i] = max + arr[i];
	}
	max = 0;
	for(int i=0; i<n; i++) if(dp[i] > max) max = dp[i];
	cout<<max<<'\n';
	return 0;
}