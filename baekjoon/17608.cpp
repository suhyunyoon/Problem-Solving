#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> arr;
	int n, t;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>t;
		arr.push_back(t);
	}
	int max = arr[arr.size()-1];
	int cnt = 1;
	for(int i=arr.size()-2; i>=0; i--)
		if(arr[i] > max){
			max = arr[i];
			cnt++;
		}
	cout<<cnt<<'\n';
	return 0;
}