#include<iostream>
using namespace std;

int arr[1002][1002] = {0,};

int main(){
	int n, k;
	cin>>n>>k;
	n; k;
	for(int i=0; i<=n; i++){
		arr[i][0] = 1;
		for(int j=1; j<=i; j++){
			arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % 10007;
		}
	}
	cout<<arr[n][k]<<endl;
}