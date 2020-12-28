#include<iostream>

using namespace std;

int rewriteChessBoard(int, int);
int findMinRewrite(char[51][51], int, int, int, int);

int main(){
	int n, m;
	cin>>n>>m;
	cout<<rewriteChessBoard(n,m)<<endl;
	return 0;
}

int rewriteChessBoard(int n, int m){
	char board[51][51];
	int temp, min = 2500;
	for(int i=0; i<n; i++)
		cin>>board[i];
	for(int i=0; i<=n-8; i++){
		for(int j=0; j<=m-8; j++){
			temp = findMinRewrite(board, n, m, i, j);
			if(temp < min) min = temp;
		}
	}
	return min;
}

int findMinRewrite(char board[51][51], int n, int m, int i_pos, int j_pos){
	int cnt[2] = {0,0};
	char color[2] = {'W', 'B'};
	for(int i=i_pos; i<i_pos+8; i++){
		for(int j=j_pos; j<j_pos+8; j++){
			cnt[0] += (board[i][j] == color[(i+j) % 2] ? 1 : 0);
			cnt[1] += (board[i][j] == color[(i+j+1) % 2] ? 1 : 0);
		}
	}
	return cnt[0] < cnt[1] ? cnt[0] : cnt[1];
}