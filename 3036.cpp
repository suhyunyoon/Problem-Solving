#include<iostream>
using namespace std;

void f(int a, int b){
	int factor = 2, t = a > b ? b : a;
	while(factor <= t){
		if(a % factor == 0 && b % factor == 0){
			a /= factor;
			b /= factor;
		}
		else factor++;
	}
	cout<<a<<'/'<<b<<'\n';
}

int main(){
	int n, t, temp;
	cin>>n>>t;
	for(int i=1; i<n; i++){
		cin>>temp;
		f(t, temp);
	}
	return 0;
}