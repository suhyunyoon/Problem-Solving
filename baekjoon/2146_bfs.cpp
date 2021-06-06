#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Point{
	public:
	int i;
	int j;
	int dist;
	Point(int i, int j, int d){
		this->i = i;
		this->j = j;
		this->dist = d;
	}
};

vector<vector<int>> map;
vector<queue<Point>> edge;
int n;

int dfs(int i, int j, int index){
	
	map[i][j] = index;
	if((i > 0 && map[i-1][j] == 0) || (i < n-1 && map[i+1][j] == 0) || (j > 0 && map[i][j-1] == 0) || (j < n-1 && map[i][j+1] == 0) )
		edge.back().push(Point(i,j,0));
	
	if(i > 0 && map[i-1][j] == 1) dfs(i-1, j, index);
	if(i < n-1 && map[i+1][j] == 1) dfs(i+1, j, index);
	if(j > 0 && map[i][j-1] == 1) dfs(i, j-1, index);
	if(j < n-1 && map[i][j+1] == 1) dfs(i, j+1, index);
	
	return 0;
}

int main(){
	// input
	cin>>n;
	map = vector<vector<int>>(n, vector<int>(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>map[i][j];
	// dfs & edge따로 저장
	int index = 2;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j] == 1){
				edge.push_back(queue<Point>());
				dfs(i, j, index);
				index++;
			}
		}
	}
	// edge 끼리 거리계산
	int edgeSize = edge.size();
	int minDist = 1000000000;
	// 모든 섬에 대해
	for(int i=0; i<edgeSize; i++){
		while(edge[i].size()){
			Point &p = edge[i].front();
			// check
			if(map[p.i][p.j] != i+2){
				cout<<map[p.i][p.j]<<'\n';
				minDist = min(minDist, p.dist-1);
				// 큐 초기화 후 탈출
				queue<Point> empty;
				swap(edge[i], empty);
				break;
			}
			else{
				map[p.i][p.j] = p.dist * -1;
			}
			// bfs
			if(p.i > 0 && map[p.i-1][p.j] >= 0 && map[p.i-1][p.j] != map[p.i][p.j]) edge[i].push(Point(p.i-1, p.j, p.dist+1));
			if(p.i < n-1 && map[p.i+1][p.j] >= 0 && map[p.i+1][p.j] != map[p.i][p.j]) edge[i].push(Point(p.i+1, p.j, p.dist+1));
			if(p.j > 0 && map[p.i][p.j-1] >= 0 && map[p.i][p.j-1] != map[p.i][p.j]) edge[i].push(Point(p.i, p.j-1, p.dist+1));
			if(p.j < n-1 && map[p.i][p.j+1] >= 0 && map[p.i][p.j+1] != map[p.i][p.j]) edge[i].push(Point(p.i, p.j+1, p.dist+1));
			
			edge[i].pop();
		}
		// 초기화
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(map[i][j] < 0) map[i][j] = 0;
	}
	
	cout<<minDist<<'\n';
	return 0;
}



/*
void dfsss(int x, int y, int cnt){
	visit[x][y] = 1;
	a[x][y]=cnt;
	
	for(int i=0; i<4; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0 && nx<n && ny>=0 && ny<n && a[nx][ny] && visit[nx][ny] == 0){
			dfs(nx,ny,cnt);
		}
	}
}
int bs(int no){
	queue<pair<int, int>> q;
	for(int i=0; i<n; i++){
		for(int i=0; i<n; i++){
			if(a[i][j]==no){
				visit[i][j]=0;
				q.push(make_pair(i,j));
			}
		}
	}
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>=0 && nx<n && ny>0 && ny<n){
				if(a[nx][ny] && a[nx][ny]!=no)
					return visit[x][y];
				
				else if(a[nx][ny]==0 && visit[nx][ny]==-1){
					visit[nx][ny]=visit[x][y]+1;
				}
			}
		}
	}



*/