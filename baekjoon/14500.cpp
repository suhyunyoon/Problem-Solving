#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> paper;

int fit(int i, int j){
	int maxsum = 0;
	// ㄱ*4, ㅡ*2, ㄴㄱ*2, ㅓ*4, ㅁ*1 총 13개
	int ilen = paper.size();
	int jlen = paper[i].size();
	// 3*2 8종
	if(ilen - i >= 3 && jlen - j >= 2){
		// 연산을 간략화 할 수 있지만 가독성을 위해..
		maxsum = max(maxsum, paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i+2][j+1]); 		// ㄴ
		maxsum = max(maxsum, paper[i][j]+paper[i][j+1]+paper[i+1][j+1]+paper[i+2][j+1]);	// ㄱ
		maxsum = max(maxsum, paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i][j+1]); 		// ㅣ-
		maxsum = max(maxsum, paper[i+2][j]+paper[i][j+1]+paper[i+1][j+1]+paper[i+2][j+1]);	// _ㅣ
		maxsum = max(maxsum, paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i+1][j+1]); 		// ㅏ
		maxsum = max(maxsum, paper[i+1][j]+paper[i][j+1]+paper[i+1][j+1]+paper[i+2][j+1]); 	// ㅓ
		maxsum = max(maxsum, paper[i][j]+paper[i+1][j]+paper[i+1][j+1]+paper[i+2][j+1]); 	// ㄴㄱ
		maxsum = max(maxsum, paper[i+2][j]+paper[i+1][j]+paper[i+1][j+1]+paper[i][j+1]); 	// ㅣ-ㅣ
	}
	// 2*3 8종
	if(ilen - i >= 2 && jlen - j >= 3){
		// 연산을 간략화 할 수 있지만 가독성을 위해..
		maxsum = max(maxsum, paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j]); 		// ㅣ--
		maxsum = max(maxsum, paper[i+1][j]+paper[i+1][j+1]+paper[i+1][j+2]+paper[i][j+2]);	// __ㅣ
		maxsum = max(maxsum, paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j+2]); 		// --ㅣ
		maxsum = max(maxsum, paper[i][j]+paper[i+1][j]+paper[i+1][j+1]+paper[i+1][j+2]);	// ㅣ__
		maxsum = max(maxsum, paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i+1][j+1]); 		// ㅜ
		maxsum = max(maxsum, paper[i][j+1]+paper[i+1][j]+paper[i+1][j+1]+paper[i+1][j+2]); 	// ㅗ
		maxsum = max(maxsum, paper[i+1][j]+paper[i+1][j+1]+paper[i][j+1]+paper[i][j+2]); 	// _ㅣ-
		maxsum = max(maxsum, paper[i][j]+paper[i][j+1]+paper[i+1][j+1]+paper[i+1][j+2]); 	// -ㅣ_
	}
	if(ilen - i >= 4){
		maxsum = max(maxsum, paper[i][j]+paper[i+1][j]+paper[i+2][j]+paper[i+3][j]); 		// ㅡ
	}
	if(jlen - j >= 4){
		// ㅣ
		maxsum = max(maxsum, paper[i][j]+paper[i][j+1]+paper[i][j+2]+paper[i][j+3]);		// ㅣ
	}
	if(ilen - i >= 2 && jlen - j >= 2){
		maxsum = max(maxsum, paper[i][j]+paper[i][j+1]+paper[i+1][j]+paper[i+1][j+1]);		// ㅁ
	}
	return maxsum;
}

int main(){
	int n, m, maxsum = 0;
	// init&input
	cin>>n>>m;
	paper = vector<vector<int>>(n, vector<int>(m, 0));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>paper[i][j];
	// find
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int temp = fit(i,j);
			maxsum = max(maxsum, temp);
		}
	}
	cout<<maxsum<<'\n';
	return 0;
}