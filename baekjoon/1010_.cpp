#include<iostream>
#include<algorithm>
using namespace std;
struct w{
	public:
	int a;
	int b;
} d[100001];
int n;
bool cmp(w x, w y){
	return x.a<y.a;
}
int max(int p, int q){
	return p>q ? p:q;
}
int solve(int k){
	int i,count=1;
	for(i = k-1; i>=1; i--)
		if(d[k].b > d[i].b)
			count = max(count, solve(i)+1);
			return count;
}
int main(){
	int i, t, m=0;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>d[i].a>>d[i].b;

	sort(d+1, d+n+1,cmp);
	for(i=1; i<=n; i++){
		t=solve(i);
		if(m<t)
			m = t;
	}
	cout<<n-m<<'\n';
	return 0;
}