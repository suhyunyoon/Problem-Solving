#include<iostream>
#include<queue>
using namespace std;

int cnt[100];
int to[100];
const int MAX = 100;

class Set{
public:
    int s, c;
    Set(int s, int c){
        this->s = s; this->c = c;
    }
};

int main(){
    int n, m, u, v, s, c;
    queue<Set> q;
    // init
    for(int i=0; i<MAX; i++){
        cnt[i] = 1000;
        to[i] = i;
    }
    // input
    cin>>n>>m;
    for(int i=0; i<n+m; i++){
        cin>>u>>v;
        to[u-1] = v-1;
    }
    // bfs
    q.push(Set(0, 0));
    while(!q.empty()){
        s = q.front().s; c = q.front().c;
        // update
        if(cnt[s] > c) cnt[s] = c;
        // ladder or snake
        if(to[s] != s){
            s = to[s];
            if(cnt[s] > c) cnt[s] = c;
        }
        // dice 6 to 1
        for(int i=s+6; i>s; i--){
            if(i < MAX && cnt[i] > c+1)
                q.push(Set(i, c+1));
        }
        q.pop();
    }
    cout<<cnt[MAX-1]<<'\n';
    return 0;
}