#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> arr;
	vector<int> sorted;
	int N, temp;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>temp;
		arr.push_back(temp);
	}
	sorted = vector<int>(arr);
	sort(sorted.begin(), sorted.end());
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i] == sorted[j]){
				cout<<j<<' ';
				sorted[j] = -1;
				break;
			}
		}
	}
	cout<<endl;	
	return 0;
}