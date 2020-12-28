#include<iostream>
#include<vector>

using namespace std;

int bachuSnail();
int bfs(int [50][50], int, int, int, int, int);

int print(int field[50][50], int m, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<field[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++)
		cout<<bachuSnail()<<endl;
	return 0;
}

int bachuSnail(){
	int field[50][50] = {0,};
	int m, n, k, tempX, tempY, num = 1;
	cin>>m>>n>>k;
	for(int i=0; i<k; i++){
		cin>>tempX>>tempY;
		field[tempY][tempX] = -1;
	}
	
	//print(field, m, n);
	// m이 가로(j), n이 세로(i)
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(field[i][j] == -1){
				bfs(field, m, n, i, j, num);
				num++;
			}
	
	//cout<<"-----------------------------"<<endl;
	//print(field, m, n);
	return num-1;
}

// 확인안한데는 -1, 확인하는 순서부터 영역의 num 증가
int bfs(int field[50][50], int m, int n, int i, int j, int num){
	field[i][j] = num;
	if(i>0 && field[i-1][j] == -1) bfs(field, m, n, i-1, j, num);
	if(i<n-1 && field[i+1][j] == -1) bfs(field, m, n, i+1, j, num);
	if(j>0 && field[i][j-1] == -1) bfs(field, m, n, i, j-1, num);
	if(j<m-1 && field[i][j+1] == -1) bfs(field, m, n, i, j+1, num);
	return 0;
}