#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0; i<N-1; i++){
		for(int j=0; j<N-i-1; j++)
			cout<<' ';
		cout<<'*';
		for(int j=0; j<2*i-1; j++)
			cout<<' ';
		if(i)
			cout<<'*';
		cout<<endl;
	}
	for(int i=0; i<N*2 - 1; i++)
		cout<<'*';
	cout<<endl;
	return 0;
}