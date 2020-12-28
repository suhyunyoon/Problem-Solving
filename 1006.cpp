#include<iostream>
#include<vector>
using namespace std;

int swat(){
	int N, W, temp;
	vector<int> sector;
	// input
	cin>>N>>W;
	N*=2;
	for(int i=0; i<N; i++){
		cin>>temp;
		sector.push_back(temp);
	}
	return 0;
}

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		swat();
	}
	return 0;
}