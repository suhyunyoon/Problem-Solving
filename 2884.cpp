#include<iostream>
using namespace std;
int main(){
    int a,b;
    int time;
    cin>>a>>b;
    time = a*60 + b - 45;
    if(time < 0) time+=60*24;
    cout<<time/60<<' '<<time%60<<endl;
    return 0;
}