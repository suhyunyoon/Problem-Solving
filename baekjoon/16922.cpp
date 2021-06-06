#include<iostream>
using namespace std;

bool check[1001] = {false,};
int nums[4] = {1, 5, 10, 50};
int n;

void f(int num, int idx, int sum){
    if(num == n){
        check[sum] = true;
        return;
    }
    for(int i=idx; i<4; i++)
        f(num+1, i, sum + nums[i]);
}

int main(){
    cin>>n;
    f(0, 0, 0);
    int cnt=0;
    for(int i=1; i<=1000; i++)
        if(check[i]) cnt++;
    cout<<cnt<<'\n';
    return 0;
}