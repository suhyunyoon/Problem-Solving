#include<iostream>
using namespace std;

const int POW = 2;

bool checkSpace(int i, int j, int n){
	while(n>3){
		if(i%n >= n/2 && i%n < n && 2*(i%(n/2)) < j%(2*n) && j%(2*n) < n)return false;
		n /= POW;
	}
	if(i%3 == 1 && j%3 == 1) return false;
	return true;
}

int main(){
	int N;
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=N-i-1; j>0; j--) cout<<' ';
		for(int j=0; j<1+2*i; j++) cout<< (checkSpace(i,j,N) ? '*' : ' ');
		for(int j=N-i-1; j>=0; j--) cout<<' ';
		cout<<endl;
	}
	return 0;
}