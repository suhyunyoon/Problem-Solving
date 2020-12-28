#include<iostream>
using namespace std;
int N;

int f(int num){
    if(num == 0){
        return 1;
    }
    else if(num == 2){
        // 1+1, 2
        return 2;
    }
    else if(num == 1){
        // 1
        return 1;
    }
    else{
        return f(num-3) + f(num-2) + f(num-1);
    }
}

int main(){
    int n, ans;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>n;
        ans = f(n);
        cout<<ans<<'\n';
    }
}