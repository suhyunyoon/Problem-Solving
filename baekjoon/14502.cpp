#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int ans = 0;

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void print_(vector<vector<int>> arr){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int bfs(vector<vector<int>> arr, queue<vector<int>> virus, int safe){
    while(virus.size()){
        vector<int> coord = virus.front();
        if(arr[coord[0]][coord[1]] != 2){
            arr[coord[0]][coord[1]] = 2;
            safe--;
        }
        //print_(arr);
        // 4방향 중 갈 수 있는 공간 수 체크
        for(int i=0; i<4; i++){
            if(coord[0]+di[i] >= 0 && coord[0]+di[i] < n && 
                coord[1]+dj[i] >= 0 && coord[1]+dj[i] < m && !arr[coord[0]+di[i]][coord[1]+dj[i]]){
                vector<int> temp;
                temp.push_back(coord[0]+di[i]); temp.push_back(coord[1]+dj[i]);
                virus.push(temp);
            }
        }
        if(safe <= ans){
            //print_(arr);
            return 0;
        }
        virus.pop();
    }
    
    if(safe > ans){
        ans = safe;
        //cout<<safe<<endl;
    }
    return 0;
}

int main(){
    // init
    int safe = 0;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    queue<vector<int>> virus;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 2){
                vector<int> temp;
                temp.push_back(i); temp.push_back(j);
                virus.push(temp);
                safe--;
            }
            if(arr[i][j] != 1) safe++;
        }
    }
    // 벽 칠 수 있는 모든 경우의 수
    safe -= 3;
    int i1, j1, i2, j2, i3, j3;
    for(int i=0; i<n*m-2; i++){
        i1 = i/m; j1 = i%m;
        if(arr[i1][j1]) continue;
        arr[i1][j1] = 1;
        for(int j=i+1; j<n*m-1; j++){
            i2 = j/m; j2 = j%m;
            if(arr[i2][j2]) continue;
            arr[i2][j2] = 1;
            for(int k=j+1; k<n*m; k++){
                i3 = k/m; j3 = k%m;
                if(arr[i3][j3]) continue;
                arr[i3][j3] = 1;

                //cout<<i1<<','<<j1<<" / "<<i2<<','<<j2<<" / "<<i3<<','<<j3<<" / "<<endl;

                bfs(arr, virus, safe);
                arr[i3][j3] = 0;
            }
            arr[i2][j2] = 0;
        }
        arr[i1][j1] = 0;
    }

    cout<<ans<<'\n';
}