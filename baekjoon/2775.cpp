#include<iostream>
using namespace std;

long long combination(int a, int b){
	long long mul=1, div=1;
	int limit = b < a-b ? b : a-b;
	for(int i=1; i<=limit; i++){
		mul *= a-i+1; div *= i;
	}
	return mul/div;
}

int dp(int a, int b){
	int arr[15][15] = {0,};
	for(int i=0; i<=b; i++) arr[0][i] = i;
	for(int i=1; i<=a; i++)
		for(int j=1; j<=b; j++) arr[i][j] = arr[i-1][j] + arr[i][j-1];
	return arr[a][b];
}

int main(){
	int a,b,n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        cout<<(a>=12 && b>=12 ? (combination(a+b-1,a-2) + combination(a+b-1,a-1)) : combination(a+b,a-1))<<endl;
        //cout<<dp(a,b)<<endl;
    }
    return 0;
}