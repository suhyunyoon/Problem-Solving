#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> sum;
	int n, t;
	// input
	cin>>n;
	sum.push_back(0);
	for(int i=0; i<n; i++){
		cin>>t;
		sum.push_back(sum[i] + t);
	}
	// dp
	int min = 0;
	vector<int> dp;
	for(int i=1; i<=n; i++){
		dp.push_back(sum[i] - min);
		
		if(min > sum[i]) min = sum[i];
	}
	int max = -1000000000;
	for(int i=0; i<n; i++){
		if(max < dp[i]) max = dp[i];
	}
	cout<<max<<'\n';
	return 0;
}

int var(){
	int n;
	int a[100000];
	int d[100000];
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++){
		d[i] = a[i];
		if(i==0)
			continue;
		if(d[i-1] > 0)
			d[i] = d[i-1] + a[i];
		
	}
	int ans = d[0];
	for(int i=1; i<n; i++){
		if(ans < d[i])
			ans =d[i];
	}
	cout<<ans<<'\n';
	return 0;
}