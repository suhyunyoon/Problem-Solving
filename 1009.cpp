#include<iostream>
#include<vector>
using namespace std;

int powMod(int, int);

int main(){
	int N, a, b;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>a>>b;
		cout<<powMod(a,b)<<endl;
	}
	return 0;
}

int powMod(int a, int b){
	vector<int> modList;
	int mul = 1;
	for(int cnt=0; cnt<b; cnt++){
		mul = (mul*a) % 10;
		for(int i = 0 ; i<modList.size(); i++)
			if(mul == modList[i]){
				int temp = modList[(b-1) % modList.size()];
				return temp != 0 ? temp : 10;
			}
		modList.push_back(mul);
		//cout<<mul<<endl;
	}
	return mul != 0 ? mul : 10;
}