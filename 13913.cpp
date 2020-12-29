#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> back(vector<int> track, int cnt, int k){
    // 순간이동 불가능할 때 or n==k
    if(k <= n){
        for(int i=k+1; i<=n; i++) track.push_back(i);
        return track;
    }
    // 무한루프 방지
    if(k == 1 && n == 0){
        track.push_back(0);
        return track;
    }
    vector<int> ans;
    int len = 100000;
    // k: 홀수, +1, -1 나눠서 작은 값이 ans
    if(k % 2){
        vector<int> ans1 = track, ans2 = track;
        ans1.push_back(k-1); ans1.push_back((k-1)/2);
        ans2.push_back(k+1); ans2.push_back((k+1)/2);
        ans1 = back(ans1, cnt+2, (k-1)/2);
        ans2 = back(ans2, cnt+2, (k+1)/2);

        ans = ans1.size() < ans2.size() ? ans1 : ans2;
        len = ans.size();
    }
    // k: 짝수
    else{
        ans = track;
        ans.push_back(k/2);
        ans = back(ans, cnt+1, k/2);
        len = ans.size();
    }
    if(k - n + cnt < len){
        ans = track;
        for(int i=k-1; i>=n; i--) ans.push_back(i);
    }
    return ans;
}

int main(){
    int k;
    cin>>n>>k;
    int m = 100000, cnt=0;
    vector<int> ans, track;
    track.push_back(k);

    ans = back(track, 0, k);

    int len = ans.size();
    cout<<len-1<<'\n';
    for(int i=len-1; i>=0; i--)
        cout<<ans[i]<<' ';

    return 0;
}