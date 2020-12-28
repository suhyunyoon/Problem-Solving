#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> arr;
	int n, k, t, sum = 0, max;
	int i;
	cin>>n>>k;
	// 첫 k일간의 합 계산
	for(i=0; i<k; i++){
		cin>>t;
		arr.push_back(t);
		sum += t;
	}
	max = sum;
	// 하나 받고 하나 빼면서 최댓값 갱신
	for(; i<n; i++){
		cin>>t;
		arr.push_back(t);
		sum += t - arr[i-k];
		if(max < sum) max = sum;
	}
	cout<<max<<'\n';
	return 0;
}