#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n){
	if(((n%2) & (n%3) & (n%5) & (n%7)) == 0) return false;
	for(int i = 11; i*i <= n; i++){
		if(n % (i*i) == 0)return false;
	}
	return true;
}

// 에라토스테네스의 체
int main(){
	long long min, max, cnt = 0;
	long long pow;
	int arr[1000001];
	vector<int> powList;
	for(int i=0; i<1000001; i++)
		arr[i] = 1;
	cin>>min>>max;
	
	for(int i=2; i*i <= max; i++){
		if(isPrime(i)) powList.push_back(i);
	}
	/*
	for(int i=2; i*i <= max; i++){
		int len = powList.size();
		bool flag = true;
		for(int j=0; j<len; j++){
			if(i % powList[j] == 0){
				flag = false;
				break;
			}
		}
		if(flag) powList.push_back(i);
	}*/
	cout<<"make powList Done"<<endl;
	int len = powList.size();
	for(int index = 0; index<len; index++){
		long long i, powSq = (long long)powList[index]*powList[index];
		for(long long j=min; j<=max; j++){
			if(j % powSq == 0){
				i = j;
				break;
			}
		}
		for(; i<=max; i+=powSq){
			if(arr[i-min] == 0) continue;
			else if(i % (powList[index]*powList[index]) == 0){
				arr[i-min] = 0;
			}
		}
	}
	for(int i=0; i<=max-min; i++){
		//cout<<arr[i]<<' ';
		cnt += arr[i];
	}//cout<<endl;
	cout<<cnt<<endl;
	cout<<powList.size()<<endl;
	return 0;
}