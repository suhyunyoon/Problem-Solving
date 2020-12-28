#include<iostream>
#include<map>
using namespace std;
int main(){
	int n, temp;
	int arr[3000];
	map<int, int> pos;
	long long dp[300][300] = {0,};
	bool check[300][300] = {false,};
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		pos[arr[i]] = i;
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(2*j - i >= 0){
				dp[i][j] = dp[j][pos[2*j-i]] + arr[i];
				check[i][j] = true;
			}
			else 
				dp[i][j] = arr[j] + arr[i];
		}
	}
	long long max = 0;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			cout<<dp[i][j]<<' ';
			if(check[i][j] && max < dp[i][j]) max = dp[i][j];
		}cout<<'\n';
	}
	cout<<max<<'\n';
	return 0;
}