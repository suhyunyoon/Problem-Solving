#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr, index;
vector<int> segtree;
int n, t, leaf, size;
long long ans;

bool cmp(int a, int b){
	if(arr[a] == arr[b])
		return a < b;
	return arr[a] < arr[b];
}

int findIndex(int p){
	int pos = size/2 + p;
	int ret = 0;
	while(pos > 0){
		ret += segtree[pos];
		pos = (pos-1)/2;
	}
	return ret;
}

void pullIndex(int p){
	int pos = size/2 + p;
	while(pos > 0){
		// 홀수면 다음 index 꺼 땡김
		if(pos%2) segtree[pos+1] -= 1;
		pos = (pos-1)/2;
	}
}

int main(){
	// input
	cin>>n;
	// tree 만들기
	leaf = 1; size = 1;
	while(leaf < n){
		leaf *= 2;
		size += leaf;
	}
	segtree = vector<int>(size, 0);
	// arr input
	for(int i=0; i<n; i++){
		cin>>t;
		arr.push_back(t);
		index.push_back(i);
		segtree[size/2 + i] = i;
	}
	// sort
	sort(index.begin(), index.end(), cmp);
	// 뒤부터 몇번 옮겨가야하는지 카운트
	for(int i=n-1; i>=0; i--){
		// 몇번 바꿔야하는지
		ans += i - findIndex(index[i]);
		// 바꾸고 오른쪽에 있는 segment들 값 -1
		pullIndex(index[i]);
	}
	cout<<ans<<'\n';
	return 0;
}