#include<iostream>
using namespace std;
int n, a, b, origin, cnt = 0;
int main(){
    cin>>n;
    origin = n;
    while(true){
        a = n/10;
        b = n%10;
        n = b*10 + (a+b)%10;
        cnt++;
        if(n == origin) break;
    }
    cout<<cnt<<'\n';
    return 0;
}