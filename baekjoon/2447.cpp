#include<iostream>
using namespace std;

const int POW = 3;

bool checkSpace(int i, int j, int n){
	int temp;
	while(n > 1){
		temp = n / 3;
		if(i % n >= temp && i % n < temp*2 && j % n >= temp && j % n < temp*2) return false;
		n /= POW;
	}
	return true;
}

int main(){
	int N;
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<< (checkSpace(i,j,N) ? '*' : ' ');
		}
		cout<<endl;
	}
}