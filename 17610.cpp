#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int check(map<int,bool> &checkmap, vector<int> &g, int index, int s, int &cnt){
	if(index >= (int)g.size()){
		if(s > 0 && !checkmap[s]){
			cnt--;
			checkmap[s] = true;		 
		}
		return 0;
	}
	check(checkmap, g, index+1, s, cnt);
	check(checkmap, g, index+1, s+g[index], cnt);
	check(checkmap, g, index+1, s-g[index], cnt);
	return 0;
}

int main(){
	int n,t,sum = 0;
	vector<int> g;
	map<int,bool> checkmap;
	//input
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>t;
		g.push_back(t);
		sum += t;
	}
	int cnt = sum;
	check(checkmap, g, -1, 0, cnt);
	cout<<cnt<<'\n';
	return 0;
}