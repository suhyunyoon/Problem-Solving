#include<iostream>
#include<vector>
using namespace std;

int arr[20][20];
int n;

int f(int num, vector<int> t1, vector<int> t2){
    if(num >= n){
        int t1sum = 0, t2sum = 0;
        int t1len = t1.size(), t2len = t2.size();
        if(t1len != t2len)
            return 100000000;
        for(int i=0; i<t1len; i++)
            for(int j=0; j<t1len; j++)
                t1sum += arr[t1[i]][t1[j]];
        for(int i=0; i<t2len; i++)
            for(int j=0; j<t2len; j++)
                t2sum += arr[t2[i]][t2[j]];    
        return t1sum > t2sum ? t1sum - t2sum : t2sum - t1sum;
    }
    int temp1, temp2;
    t1.push_back(num);
    temp1 = f(num+1, t1, t2);
    t1.pop_back();
    t2.push_back(num);
    temp2 = f(num+1, t1, t2);
    t2.pop_back();
    return temp1 > temp2 ? temp2 : temp1;
}

int main(){
    int ans;
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    ans = f(1, vector<int>(1, 0), vector<int>());
    cout<<ans<<'\n';
    return 0;
}