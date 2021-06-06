#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> nonself;
	for(int i=1; i<10000; i++){
		int temp = i, sum = i;
		while(temp){
			sum += temp%10;
			temp /= 10;
		}
		nonself.push_back(sum);
	}
	sort(nonself.begin(), nonself.end());
	nonself.erase(unique(nonself.begin(), nonself.end()), nonself.end());
	//
	int index = 0;
	for(int i=1; i<=10000; i++){
		if(nonself[index] < i)index++;
		if(nonself[index] == i) continue;
		else cout<<i<<'\n';
	}
	return 0;
}