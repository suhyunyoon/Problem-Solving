#include<iostream>
#include<vector>
using namespace std;

class Coord{
	public:
	int i, j;
	Coord(int i, int j){this->i = i; this->j = j;}
};

vector<vector<char>> arr;
vector<vector<Coord>> flooded;
int n, m;
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void flood(int i, int j, int index){
	int cnt, itmp, jtmp;
	// 8방향에 남아있는게 안무너질지 검사
	for(int k=0; k<8; k++){
		cnt = 0;
		if(i+di[k] >= 0 && i+di[k] <= n-1 && j+dj[k] >= 0 && j+dj[k] <= m-1 && arr[i+di[k]][j+dj[k]] >= '1' && arr[i+di[k]][j+dj[k]] <= '9'){
			itmp = i+di[k]; jtmp = j+dj[k];
			for(int d=0; d<8; d++){
				// .갯수 파악
				if(itmp+di[d] >= 0 && itmp+di[d] <= n-1 && jtmp+dj[d] >= 0 && jtmp+dj[d] <= m-1 && arr[itmp+di[d]][jtmp+dj[d]] == '.')
					cnt++;
			}
			// 수장(0은 나중에 한번에 .으로 바꿔줌)
			if(arr[itmp][jtmp] - '0' <= cnt){
				arr[itmp][jtmp] = '0';
				flooded[index].push_back(Coord(itmp, jtmp));
			}
		}
	}
}

int main(){
	// input
	cin>>n>>m;
	arr = vector<vector<char>>(n, vector<char>(m, 0));
	flooded = vector<vector<Coord>>(2, vector<Coord>());
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
			if(arr[i][j] == '.') flooded[0].push_back(Coord(i, j));
		}
	}
	// 
	int len, cnt = -1;
	// 다음에 새로 처리할 .이 없을 때까지 loop
	do{
		cnt++;
		// 이번
		len = flooded[cnt%2].size();
		// 수장되는 좌표 찾기
		for(int i=0; i<len; i++)
			flood(flooded[cnt%2][i].i, flooded[cnt%2][i].j, (cnt+1)%2);
		// 수장된 좌표 .으로 바꿔주기
		flooded[cnt%2].clear();
		len = flooded[(cnt+1)%2].size();
		for(int i=0; i<len; i++){
			arr[flooded[(cnt+1)%2][i].i][flooded[(cnt+1)%2][i].j] = '.';
		}
	} while(len);
	cout<<cnt<<'\n';
	return 0;
}