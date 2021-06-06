#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

vector<vector<int>> arr;
int n, m;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

bool check_exists(vector<int> &list, int num){
    int len = list.size();
    for(int i=0; i<len; i++){
        if(list[i] == num) return true;
    }
    return false;
}

int main(){
    // input
    string temp;
    cin>>n>>m;
    arr = vector<vector<int>>(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        cin>>temp;
        for(int j=0; j<m; j++)
            arr[i][j] = (int)(temp[j] - '0');
    }
    vector<int> coord;
    coord.push_back(0); coord.push_back(0);

    // 빈칸들 그룹으로 묶음
    vector<vector<int>> group(n, vector<int>(m, -1));
    vector<int> cnt;
    int group_num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!arr[i][j]){
                queue<vector<int>> bfs;
                coord[0] = i; coord[1] = j;
                bfs.push(coord);
                cnt.push_back(0);
                while(bfs.size()){
                    vector<int> c = bfs.front();
                    if(!arr[c[0]][c[1]]){
                        arr[c[0]][c[1]] = -1;
                        group[c[0]][c[1]] = group_num;
                        cnt[group_num]++;
                        for(int k=0; k<4; k++){
                            if(c[0]+di[k] >= 0 && c[0]+di[k] < n && c[1]+dj[k] >= 0 && c[1]+dj[k] < m){
                                coord[0] = c[0]+di[k]; coord[1] = c[1]+dj[k];
                                bfs.push(coord);
                            }
                        }
                    }
                    bfs.pop();
                }
                group_num++;
            }
        }
    }

    // 벽 마다 상하좌우 그룹 있는지 검사, 출력
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp = 0;
            if(arr[i][j] == 1){
                temp++;
                vector<int> list;
                for(int k=0; k<4; k++){
                    if(i+di[k] >= 0 && i+di[k] < n && j+dj[k] >= 0 && j+dj[k] < m
                            && group[i+di[k]][j+dj[k]] != -1 && !check_exists(list, group[i+di[k]][j+dj[k]])){
                        list.push_back(group[i+di[k]][j+dj[k]]);
                        temp += cnt[group[i+di[k]][j+dj[k]]];
                    }
                }
            }
            cout<<(temp%10);
        }
        cout<<'\n';
    }

    return 0;
}