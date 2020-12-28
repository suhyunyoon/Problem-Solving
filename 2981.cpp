#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
int n;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	int t;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	
	int j, div, len = arr.size();
	t = arr[1] - arr[0];
	for(int i=2; i<len; i++)
		t = gcd(arr[i] - arr[i-1], t);
	
	vector<int> d;
	d.push_back(t);
	for(int i=2; i<t; i++){
		if(t%i == 0){
			if(i < t/i){
				d.push_back(t/i);
			}
			else {
				if(i == t/i) cout<<i<<' ';
				break;
			}
			cout<<i<<' ';
		}
	}
	len = d.size();
	for(int i=len-1; i>=0; i--)
		cout<<d[i]<<' ';
	cout<<endl;
	return 0;
}