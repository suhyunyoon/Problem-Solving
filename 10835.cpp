

// ans
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> Left;
vector<int> Right;
vector<vector<int>> d;
 int solve(int i, int j){
	 if(i>=n || j>=n)
		 return 0;
	 if(d[i][j] != -1)
		 return d[i][j];
	 
	 int ret = 0;
	 ret=  max(ret, solve(i+1, j));
	 ret = max(ret, solve(i+1, j+1));
	 if(Left[i] > Right[j])
		 ret=max(ret, solve(i, j+1)+Right[j]);
	 
	 d[i][j] = ret;
	 return ret;
 }

int solve_dp(){
	d[0][0] = 0;
	for(int i=0; in; i++)
		for(int j=0; j<n; j++){
			if(d[i][j]<0) break;
			d[i+1][j]= max(d[i+1][j], d[i][j]);
			d[i+1][j+1]=max(d[i+1][j+1], d[i][j]);
			if(Left[i]>Right[j])
				d[i][j+1]=max(d[i][j+1], d[i][j]+Right[j]);
			
		}
	int ret= 0;
	for(int i=0; i<n; i++){
		ret = max(ret,d[i][j]);
		ret = max(ret,d[n][i]);
	}
	return ret;
}

int main(){
	cin>>n;
	d = vector<vector<int>>(n, vector<int>(n, -1));
	int temp;
	for(int i=0; i<n; i++){cin>>temp; Left.push_back(temp);}
	for(int i=0; i<n; i++){cin>>temp; Right.push_back(temp);}
	
	cout<<solve(0,0);
}