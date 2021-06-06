#include<iostream>
using namespace std;

int main(){
	int N, cnt;
	cin>>N;
	for(int i=0; i<4*N-3; i++){
		for(int j=0; j<4*N-3; j++){
			cout<< ((i%2 == 0 && j >= i && j<=4*N-4-i) 
					|| (i%2 == 0 && j >= 4*N-4-i && j<=i)
					|| (j%2 == 0 && i >= j && i<=4*N-4-j)
					|| (j%2 == 0 && i >= 4*N-4-j && i<=j) ? "*" : " ");
		}
		cout<<endl;
	}
	return 0;
}