#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int t=0; t<T; t++){
		int n, ans = 1;
		string temp, type;
		map<string, int> typeCnt;
		vector<string> types;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>temp>>type;
			if(typeCnt[type] == 0){
				types.push_back(type);
			}
			typeCnt[type]++;
		}
		for(int i=0; i<types.size(); i++){
			ans *= typeCnt[types[i]] + 1;
		}
		cout<<ans-1<<'\n';
	}
	return 0;
}