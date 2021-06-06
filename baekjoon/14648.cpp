#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF=INT_MAX;

vector<ll> arr;
vector<ll> seg;

void printTree(int h){
	int idx = 1, temp;
	for(int i=0; i<=h; i++){
		for(int j=0; j<(1<<i); j++){
			temp = seg[idx++];
			if(temp==INF)
				printf("FF ");
			else
				printf("%d ", temp);
		}
		printf("\n");
	}
	printf("\n");
}

ll update(int pos, int val, int node, int x, int y){
	if (y < pos || pos < x)
		return seg[node];
	if (x == y)
		return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}

ll query(int lo, int hi, int node, int x, int y){
	if(y < lo || hi < x)
		return 0;
	if(lo <= x && y <= hi)
		return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main(){
	int n, q;
	cin>>n>>q;
	
	arr.resize(n+1);
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	
	int h=(int)ceil(log2(n));
	int treeSize=(1<<(1+h));
	seg.resize(treeSize, 0);
	
	for(int i=1; i<=n; i++)
		update(i, arr[i], 1,1,n);
	
	printTree(3);
	
	while(q--){
		int option, a, b, c, d;
		cin>> option;
		if(option == 1){
			cin>>a>>b;
			cout<<query(a,b,1,1,n) << '\n';
			swap(arr[a], arr[b]);
			update(a, arr[a], 1,1,n);
			update(b, arr[b], 1, 1, n);
		}
		else {
			cin>>a>>b>>c>>d;
			cout<<query(a, b, 1, 1, n) - query(c, d, 1, 1, n)<<'\n';
		}
	}
	return 0;
}