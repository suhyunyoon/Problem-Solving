#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
char arr[22][22] = {0, };
bool visited[22][22][22][22] = {false, };
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

bool cmp(vector<int> a, vector<int> b){
    int len = 4;
    for(int i=0; i<len; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main(){
    // init & input
    int cnt = 0;
    cin>>n>>m;
    // 1i, 1j, 2i, 2j, count
    vector<int> coord(5, 0);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'o'){
                coord[cnt*2] = i; coord[cnt*2 + 1] = j;
                cnt++;
                arr[i][j] = '.';
            }
        }
    }
    // bfs
    queue<vector<int>> bfs;
    bfs.push(coord);
    while(bfs.size()){
        vector<int> f = bfs.front();
        bfs.pop();
        // check count, visited
        if(f[4] < 10 && !visited[f[0]][f[1]][f[2]][f[3]]){
            vector<int> c(f);
            c[4]++;
            // four direction
            for(int i=0; i<4; i++){
                c[0] = f[0] + di[i]; c[1] = f[1] + dj[i];
                c[2] = f[2] + di[i]; c[3] = f[3] + dj[i];
                // consider wall
                if(arr[c[0]][c[1]] == '#'){
                    c[0] -= di[i]; c[1] -= dj[i];
                }
                if(arr[c[2]][c[3]] == '#'){
                    c[2] -= di[i]; c[3] -= dj[i];
                }
                // least one coin moved
                if(cmp(c, f)) continue;
                bool flag1 = c[0] <= 0 || c[0] > n || c[1] <= 0 || c[1] > m;
                bool flag2 = c[2] <= 0 || c[2] > n || c[3] <= 0 || c[3] > m;
                // only one coin dropped = answer
                if(flag1 != flag2){
                    cout<<c[4]<<'\n';
                    return 0;
                }
                // no coin dropped
                else if(!flag1 && !flag2){
                    bfs.push(c);
                }
            }
        }
    }
    cout<<-1<<'\n';
    return 0;
}