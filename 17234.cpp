#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int d[501][501][52];
int n, a,b;
int f(int k, int t, int s){
	if(k>=n)
		return (k<n+a?0:(1<<29));
	if(d[k][t][s] >= 0)
		return d[k][t][s];
	
	int ret = min(f(k+a, t+1, s), f(k+b, t+1, s)) + 1;
	
	if(10 * (s+1) <= t+1)
		ret = min(ret, f(2*k, t+1, s+1) + 1);
	
	return d[k][t][s] = ret;
}
int main(){
	memset(d, -1, sizeof(d));
	scanf("%d %d %d", &n, &a, &b);
	printf("%d\n", f(0,0,0));
	return 0;
}