#include<iostream>
using namespace std;

int main(){
	long long a, b, n, c2 = 0, c5 = 0, ans;
	cin>>a>>b;
	for(unsigned int i=a; i>a-b; i--){
		n = i;
		while(n%2 == 0 && n > 0){
			c2++;
			n/=2;
		}
		while(n%5 == 0 && n > 0){
			c5++;
			n/=5;
		}
	}
	for(unsigned int i=2; i<=b; i++){
		n = i;
		while(n%2 == 0 && n > 0){
			c2--;
			n/=2;
		}
		while(n%5 == 0 && n > 0){
			c5--;
			n/=5;
		}
	}
	ans = c2 > c5 ? c5 : c2;
	cout<<ans<<endl;
	return 0;
}
