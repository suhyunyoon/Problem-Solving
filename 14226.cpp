#include<iostream>
using namespace std;

const int MAX = 1000;
int cnt[1001] = {0,};

int update(int n){
    // 배열이 바뀌었는 지 체크
    bool flag = false;
    // 배수 먼저
    for(int i=2; i<=MAX; i++){
        for(int j=2; j<=i; j++){
            if(i % j == 0 && cnt[i] > cnt[i/j] + j){
                //cout<<n<<' '<<cnt[i]<<' '<<cnt[i/j] + j<<'\n';
                cnt[i] = cnt[i/j] + j;
                flag = true;
            }
        }
    }
    // 소수는 그것보다 큰 수들 중 가장 가깝게 갈 수 있는 것
    int d = 1, pivot = MAX;
    for(int i=MAX-1; i>=5; i--){
        if(cnt[i] > cnt[pivot] + d){
            //cout<<n<<' '<<cnt[i]<<' '<<cnt[pivot] + d<<'\n';
            cnt[i] = cnt[pivot] + d;
            flag = true;
        }
        else{
            pivot = i;
            d = 0;
        }
        d++;
    }
    
    return flag;
}

int main(){
    // init
    for(int i=2; i<=MAX; i++) cnt[i] = MAX;

    int n = 1;
    while(update(n)){n++;}

    int s;
    cin>>s;
    cout<<cnt[s]<<"\n";
    return 0;
}