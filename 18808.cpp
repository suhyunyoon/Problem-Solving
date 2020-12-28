#include<iostream>
#include<vector>
using namespace std;

int arr[40][40] = {0,};
vector<vector<vector<int>>> stickers;
int n, m, k;

int main(){
	int t1,t2;
	// input
	cin>>n>>m>>k;
	stickers = vector<vector<vector<int>>>(vector<vector<int>>(), k);
	for(int t=0; t<k; t++){
		cin>>t1>>t2;
		stickers[t] = vector<vector<int>>(vector<int>(0, t2), t1);
		for(int i=0; i<t1; i++){
			for(int j=0; j<t2; j++){
				cin>>stickers[t][i][j];
			}
		}
	}
	// 
	for(int i=0; i<stickers.size(); i++){
		
	}
	return 0;
}