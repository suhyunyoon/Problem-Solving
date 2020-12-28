#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> ti;
vector<int> pi;

int f(int d, int sum){
    if(d == n) return sum;
    else if(d > n) return 0;
    int temp1, temp2, max;
    temp1 = f(d + ti[d], sum + pi[d]);
    temp2 = f(d + 1, sum);
    max = temp1 > temp2 ? temp1 : temp2;
    return max;
}

int main(){
    int t, p, ans;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t>>p;
        ti.push_back(t); pi.push_back(p);
    }
    ans = f(0,0);
    cout<<ans<<'\n';
    return 0;
}