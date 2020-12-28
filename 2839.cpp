#include<stdio.h>
#include<queue>
using namespace std;

queue<pair<int, int>> q;
int visit[50001];

int main(){
	int n;
	scanf("%d", &n);
	
	q.push(make_pair(n, 0));
	visit[n]=1;
	
	while(!q.empty()){
		int remain=q.front().first;
		int cnt=q.front().second;
		q.pop();
		
		if(remain==0){
			printf("%d", cnt);
			return 0;
		}
		
		if(remain >= 5 && visit[remain-5] == 0){
			q.push(make_pair(remain-5, cnt+1));
			visit[remain-5] = 1;
		}
		if(remain >= 3 && visit[remain-3] == 0){
			q.push(make_pair(remain-3, cnt+1));
		}
	}
	printf("-1\n");
	return 0;
}