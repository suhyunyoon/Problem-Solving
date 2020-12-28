#include<iostream>
using namespace std;

// minimum time
int ans = 100000;

void f(int src, int dst, int cnt){
    if(src < dst){
        if(dst - src + cnt < ans)
            ans = dst - src + cnt;
        return;
    }
    if(cnt + src - dst < ans)
        ans = cnt + src - dst;
    
    if(src == 1 || src == dst) return;

    if(src % 2 == 1){
        f(src/2, dst, cnt+2);
        f(src/2 + 1, dst, cnt+2);
    }
    else{
        f(src/2, dst, cnt+1);
    }

}

int main(){
    int n, k;
    cin>>n>>k;
    
    f(k, n, 0);
    
    cout<<ans<<'\n';
    return 0;
}