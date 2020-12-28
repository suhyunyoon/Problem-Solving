#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
	int n,t;
	cin>>n;
	vector<int> arr;
	for(int i=0; i<n; i++){
		cin>>t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	cout<< arr[0] * arr[arr.size()-1] <<endl;
	return 0;
}