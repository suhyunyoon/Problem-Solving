#include<iostream>
#include<queue>
using namespace std;





int main_ans(){
	for(int i=1; i<=n; i++){
		int cnt;
		for(k=0; j<cnt; j++){
			int x;
			scanf("%d", &x);
			a[x].push_back(i);
			ind[i] += 1;
		}
	}
	queue<int> q;
	for(i=1; i<n; i++){
		if(ind[i] == 0){
			q.push(i);
			d[i] = time[i];
		}
	}
	for(int k=0; k<n; k++){
		int x = q.front();
		q.pop();
		for(int i=0; i<a[x].size(); i++){
			int y = a[x][i];
			ind[y] -= 1;
			
			if(d[y] < d[x]+time[y]){
				d[y] = d[x]+time[y];
			}
			if(ind[y] == 0){
				q.push(y);
			}
		}
	}
	int ans = 0;
	for(int i=1; i<n; i++){
		if(ans < d[i]){
			ans = d[i];
		}
	}
	cout<<ans<<'\n';
}