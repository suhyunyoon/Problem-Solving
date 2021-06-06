#include<iostream>
using namespace std;

char checkStar(int i, int j, int row, int col){
	int _i = i/2;
	int _j = j/2;
	if(i%2==1 && ((i-1 < j && col-i+1 > j) || (col-i+1 < j && i-1 > j))){
		return ' ';
	}
	if(j%2==1 && ((j-1 < i && row-j > i) || (row-j-2 < i && j+3 > i))){
		// 여기 할 차례
		return ' ';
	}
	
	return '*';
}

int main(){
	int N, row, col;
	cin>>N;
	if(N==1){
		cout<<"*"<<endl;
		return 0;
	}
	row = 4*N-1; col = 4*N-3;
	for(int j=0; j<col; j++)cout<<'*';
	cout<<endl<<'*'<<endl;
	for(int i=2; i<row-1; i++){
		cout<<"*";
		
		for(int j=1; j<col-1; j++){
			cout<<checkStar(i,j,row,col);
		}
		
		
		cout<<"*"<<endl;
	}
	for(int j=0; j<col; j++)cout<<'*';
	cout<<endl;
	return 0;
}