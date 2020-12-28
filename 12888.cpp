#include<iostream>
using namespace std;
int main(){
	int n;
	long long sum, pow2;
	cin>>n;
	if(n==0){
		cout<<1<<'\n';
		return 0;
	}
	if(n%2 == 0){
		sum = 3; pow2 = 8; n-=2;
		while(n > 0){
			sum += pow2;
			pow2 *= 4;
			n-=2;
		}
	}
	else{
		sum = 1; pow2 = 4; n--;
		while(n > 0){
			sum += pow2;
			pow2 *= 4;
			n-=2;
		}
	}
	cout<<sum<<'\n';
	return 0;
}