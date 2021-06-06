#include<iostream>
using namespace std;

int pow(int a, int b){
	int mul = 1;
	while(b--) mul *= a;
	return mul;
}

char triangle(int i, int j, int n, int row, int col, bool flag){
	int _row = 0, _col = 0, _prerow, _precol;
	
	while(n--){
		if(i >= _row && i < row && j >= _col && j < col){
			// 역삼각형
			if(flag){
				if(i == _row || j == _col+i-_row || j == col-i+_row-1) return '*';
			}
			// 정삼각형
			else{
				if(i == row-1 || j == _col+row-i-1 || j == col-row+i) return '*';
			}
		}
		_precol = _col;
		_prerow = _row;
		
		_row += (flag ? 1 : (row-_prerow)/2); 
		_col += (row-_prerow)/2 + 1;
		col -= (row-_prerow)/2 + 1;
		row -= (flag ? (row-_prerow)/2 : 1);
		flag = !flag;
	}
	return ' ';
}

int main(){
	int N, row, col, len;
	// true: 짝수
	bool flag;
	cin>>N;
	row = pow(2, N) - 1; col = row * 2 - 1; flag = N%2 == 0;
	
	// 밑변
	for(int i=0; i<row; i++){
		len = (flag ? col-i : row+i);
		for(int j=0; j<len; j++)cout<<triangle(i,j,N,row,col,flag);
		cout<<endl;
	}
	
	return 0;
}