#include<iostream>
using namespace std;

int main(){
	int N; 
	cin>>N;
	for(int i=0; i<N*2; i++){
		cout<<(i%2==0 ? "" : " ");
		for(int j=0; j<(N+(i+1)%2)/2; j++)cout<<"* ";
		
		cout<<endl;
	}
	return 0;
}