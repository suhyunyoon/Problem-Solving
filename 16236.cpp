#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;
int dx[] = {-1, 0,0,1};
int dy[] ={0,-1,1,0};

int n,ans,sx, sy;
int map[20][20];
int check[20][20];

struct Shark{
	int x,y;
	int size;
	int eat;
	int time;
};

bool cmp(const Shark &u, const Shark &v){
	if(u.time < v.time)
		return true;
	else if(u.time==v.time){
		if(u.x<v.x)
			return true;
		else if(u.x == v.x){
			return u.y<v.y;
		}
		else
			return false;
	}
	else{
		return false;
	}
}
int main(){
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] ==9){
				sx = i;
				sy = j;
				map[i][j] = 0;
			}
		}
	}
	Shark a={sx, sy, 2,0,0};
	vector<Shark> v;
	queue<Shark> q;
	
	while(1){
		v.clear();
		queue<Shark> empty;
		swap(q, empty);
		memset(check, 0, sizeof(check));
		check[a.x][a.y]=1;
		
		q.push(a);
		
		int found=-1;
		while(!q.empty()){
			int x=q.front().x;
			int y=q.front().y;
			int size=q.front().size;
			int eat=q.front().eat;
			int time=q.front().time;
			q.pop();
			
			if(found==time)
				break;
			
			for(int k=0; k<4; k++){
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(nx>=0 && nx<n && ny>=0 && ny<n && !check[nx][ny]){
					if(map[nx][ny] == 0 || map[nx][ny] == size){
						q.push((Shark){nx, ny, size, eat, time+1});
						check[nx][ny] = 1;
					}
					else if(map[nx][ny] <size){
						v.push_back((Shark){nx, ny, size, eat+1, time+1});
						check[nx][ny] = 1;
						found = time+1;
					}
				}
			}
		}
		if(v.size()==0)
			break;
		
		sort(v.begin(), v.end(), cmp);
		
		if(v[0].size == v[0].eat){
			v[0].size++;
			v[0].eat=0;
		}
		map[v[0].x][v[0].y] = 0;
		
		ans=ans+v[0].time;
		
		a=(Shark){v[0].x, v[0].y, v[0].size, v[0].eat, 0};
	}
	printf("%d", ans);
	return 0;
}