#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
int arr[10][10];
vector<int> selected_i;
vector<int> selected_j;

bool checkValid(int ipos, int jpos){
    int len = selected_i.size();
    for(int a=0; a<len; a++){
        if((ipos == selected_i[a] && jpos == selected_j[a] + 1) ||
            (ipos == selected_i[a] + 1 && jpos == selected_j[a]))
            return false;
    }
    return true;
}

int f(int K, int max, int ipos, int jpos){
    if(K <= 0) return max;
    int originMax = max;
    max = -10000000;
    for(int j=jpos; j<m; j++){
        if(checkValid(ipos, j)){
            selected_i.push_back(ipos); selected_j.push_back(j);
            int temp = f(K-1, originMax+arr[ipos][j], ipos, j+2);
            selected_i.pop_back(); selected_j.pop_back();
            if(max < temp) max = temp;
        }
    }
    for(int i=ipos+1; i<n; i++){
        for(int j=0; j<m; j++){
            if(checkValid(i, j)){
                selected_i.push_back(i); selected_j.push_back(j);
                int temp = f(K-1, originMax+arr[i][j], i, j+2);
                selected_i.pop_back(); selected_j.pop_back();
                if(max < temp) max = temp;
            }
        }
    }
    return max;
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>arr[i][j];

    int ans = f(k, 0, 0, 0);
    cout<<ans<<"\n";
    return 0;
}