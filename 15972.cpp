#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Coord{
public:
	int i;
	int j;
	int pi;
	int pj;
	Coord(int i, int j, int pi, int pj){
		this->i = i;
		this->j = j;
		this->pi = pi;
		this->pj = pj;
	}
	int waterflow(vector<vector<int>> &hor, vector<vector<int>> &ver, vector<vector<int>> &place){
		int border, after;
		// 가로
		if(i == pi) border = ver[i][(pj > j ? pj : j)];
		// 세로
		else if(j == pj) border = hor[(pi > i ? pi : i)][j];
		// 변화 체크
		after = place[pi][pj] > border ? place[pi][pj] : border;
		if(place[i][j] > after){
			place[i][j] = after;
			return 1;
		}
		// 변화없으면 0 return
		return 0;
	}
};

int main(){
	int n,m,h, temp;
	vector<Coord> c;
	queue<Coord> bfs;
	// input
	cin>>n>>m>>h;
	vector<vector<int>> place = vector<vector<int>>(n, vector<int>(m,h));
	vector<vector<int>> hor = vector<vector<int>>(n+1, vector<int>(m, 0));
	vector<vector<int>> ver = vector<vector<int>>(n, vector<int>(m+1, 0));
	for(int i=0; i<n+1; i++){
		for(int j=0; j<m; j++){
			cin>>hor[i][j];
			if((i==0 || i==n) && hor[i][j] != -1) c.push_back(Coord(i - (int)(i==n),j,-1,-1));
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m+1; j++){
			cin>>ver[i][j];
			if((j==0 || j==m) && ver[i][j] != -1) c.push_back(Coord(i,j - (int)(j==m),-1,-1));
		}
	}
	/* _ans
	while(pq.size()
	{
		auto state = pq.top();
		pq.pop();
		int x = state.x;
		int y = state.y;
		int sx = state.start_x;
		int sy = state.start_y;
		int h = state.h;
		if(visit[x][y] == false){
			visit[x][y] = true;
			height[x][u] = min(height[x][u], max(h, height[sx][sy]));
			
			for(auto eg:edges[x][y]){
				if(visit[eg.x][eg.y] == false){
					pq.push({eg.x, eg.y, x, y,eg.h});
				}
			}
		}
	}	
	*/
	// bfs
	int len = c.size();
	bool flag;
	for(int i=0; i<len; i++){
		// 첫칸 갱신
		if(c[i].i == 0 && hor[c[i].i][c[i].j] != -1 && place[c[i].i][c[i].j] > hor[c[i].i][c[i].j])
			place[c[i].i][c[i].j] = hor[c[i].i][c[i].j];
		else if(c[i].i == n-1 && hor[c[i].i+1][c[i].j] != -1 && place[c[i].i][c[i].j] > hor[c[i].i+1][c[i].j])
			place[c[i].i][c[i].j] = hor[c[i].i+1][c[i].j];
		if(c[i].j == 0 && ver[c[i].i][c[i].j] != -1 && place[c[i].i][c[i].j] > ver[c[i].i][c[i].j])
			place[c[i].i][c[i].j] = ver[c[i].i][c[i].j];
		else if(c[i].j == m-1 && ver[c[i].i][c[i].j+1] != -1 && place[c[i].i][c[i].j] > ver[c[i].i][c[i].j+1])
			place[c[i].i][c[i].j] = ver[c[i].i][c[i].j+1];
		// 위 아래 왼 오른
		if(c[i].i > 0 && hor[c[i].i][c[i].j] != -1) bfs.push(Coord(c[i].i - 1, c[i].j, c[i].i, c[i].j));
		if(c[i].i < n-1 && hor[c[i].i + 1][c[i].j] != -1) bfs.push(Coord(c[i].i + 1, c[i].j, c[i].i, c[i].j));
		if(c[i].j > 0 && ver[c[i].i][c[i].j] != -1) bfs.push(Coord(c[i].i, c[i].j - 1, c[i].i, c[i].j));
		if(c[i].j < m-1 && ver[c[i].i][c[i].j + 1] != -1) bfs.push(Coord(c[i].i, c[i].j + 1, c[i].i, c[i].j));
		while(bfs.size()){
			flag = bfs.front().waterflow(hor, ver, place);
			// 변화 있을 경우에만 계속함
			if(flag){
				// 위 아래 왼 오른
				if(bfs.front().i > 0 && hor[bfs.front().i][bfs.front().j] != -1 && bfs.front().i - 1 != bfs.front().pi)
					bfs.push(Coord(bfs.front().i - 1, bfs.front().j, bfs.front().i, bfs.front().j));
				if(bfs.front().i < n-1 && hor[bfs.front().i + 1][bfs.front().j] != -1 && bfs.front().i + 1 != bfs.front().pi)
					bfs.push(Coord(bfs.front().i + 1, bfs.front().j, bfs.front().i, bfs.front().j));
				if(bfs.front().j > 0 && ver[bfs.front().i][bfs.front().j] != -1 && bfs.front().j - 1 != bfs.front().pj)
					bfs.push(Coord(bfs.front().i, bfs.front().j - 1, bfs.front().i, bfs.front().j));
				if(bfs.front().j < m-1 && ver[bfs.front().i][bfs.front().j + 1] != -1 && bfs.front().j + 1 != bfs.front().pj)
					bfs.push(Coord(bfs.front().i, bfs.front().j + 1, bfs.front().i, bfs.front().j));
			}
			bfs.pop();
		}
	}
	
	// output
	int sum = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			sum += place[i][j];
			//cout<<place[i][j]<<' ';
		}
		//cout<<'\n';
	}
	cout<<sum<<'\n';
	return 0;
}