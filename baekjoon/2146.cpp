#include<iostream>
#include<vector>
#include<utility>

using namespace std;

class Point{
	public:
	int i;
	int j;
	Point(int i, int j){
		this->i = i;
		this->j = j;
	}
};

vector<vector<int>> map;
vector<vector<Point>> edge;
int n;

int dfs(int i, int j, int index){
	
	map[i][j] = index;
	if((i > 0 && map[i-1][j] == 0) || (i < n-1 && map[i+1][j] == 0) || (j > 0 && map[i][j-1] == 0) || (j < n-1 && map[i][j+1] == 0) )
		edge.back().push_back(Point(i,j));
	
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
				edge.push_back(vector<Point>());
				dfs(i, j, index);
				index++;
			}
		}
	}
	// edge 끼리 거리계산
	int edgeSize = edge.size();
	int min = 1000000000;
	for(int i=1; i<edgeSize; i++){
		int len = edge[i].size();
		for(int x=0; x<len; x++){
			// 다른 edge
			for(int j=0; j<i; j++){
				int len2 = edge[j].size();
				for(int y=0; y<len2; y++){
					int idist = edge[i][x].i - edge[j][y].i;
					int jdist = edge[i][x].j - edge[j][y].j;
					// 절댓값
					idist *= (idist < 0 ? -1 : 1); 
					jdist *= (jdist < 0 ? -1 : 1);
					// 최솟값
					if(min > idist+jdist-1) min = idist+jdist-1;
				}
			}
		}
	}
	cout<<min<<'\n';
	return 0;
}