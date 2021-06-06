#include<iostream>
#include<utility>
#include<vector>
using namespace std;

#define _CONNECTED 16
#define _UP 8
#define _DOWN 4
#define _LEFT 2
#define _RIGHT 1

int findMinLen(vector< pair< pair<int, int>, int> >, int, int, int, int);
int checkBoard(vector< pair< pair<int, int>, int> >&, int);
int main(){
	// ans : 연결된 core 수 * -1000 + 길이 총 합
    int T, n, ans, temp;
    // <<i, j>, bitarr(up down left right)>
    vector< pair< pair<int, int>, int> > core;
    cin>>T;
    for(int t=1; t<=T; t++){
    	cin>>n;
        ans = 100000;
		core.clear();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>temp;
				if(temp) core.push_back(make_pair(make_pair(i,j), _CONNECTED * !(i>0 && i<n-1 && j>0 && j<n-1)));
            }
        }
        checkBoard(core, n);
        ans = findMinLen(core, n, -1, 0, ans);
		cout<<"#"<<t<<" "<<(ans%1000)<<'\n';
    }
    return 0;
}


int findMinLen(vector< pair< pair<int, int>, int> > core, int n, int index, int status, int ans){
	// 추가한 선 방향에 따라 업데이트
	//cout<<"index: "<<index<<" status: "<<status<<" ans: "<<ans<<'\n';
	if(status){
		core[index].second = status | _CONNECTED;
		if(status == _UP) ans += core[index].first.first;
		else if(status == _DOWN) ans += n - core[index].first.first - 1;
		else if(status == _LEFT) ans += core[index].first.second;
		else if(status == _RIGHT) ans += n - core[index].first.second - 1;
		ans -= 1000;
		
		for(int i=0; i<core.size(); i++){
			if(i != index && !(core[i].second & _CONNECTED)){
				switch(status){
					case _UP:
						if(core[index].first.first > core[i].first.first)
							core[i].second = core[i].second | (core[index].first.second < core[i].first.second ? _LEFT : _RIGHT);
						break;
					case _DOWN:
						if(core[index].first.first < core[i].first.first)
							core[i].second = core[i].second | (core[index].first.second < core[i].first.second ? _LEFT : _RIGHT);
						break;
					case _LEFT:
						if(core[index].first.second > core[i].first.second)
							core[i].second = core[i].second | (core[index].first.first < core[i].first.first ? _UP : _DOWN);
						break;
					case _RIGHT:
						if(core[index].first.second < core[i].first.second)
							core[i].second = core[i].second | (core[index].first.first < core[i].first.first ? _UP : _DOWN);
						break;
				}
			}
		}
	}
	// 다했으면 리턴
    if(index >= n-1) return ans;
	else index++;
    
	int temp, min = 100000;
	// 연결 안하는 방법
	temp = findMinLen(core, n, index, 0, ans);
	if(temp < min) min = temp;
	if(!(core[index].second & _CONNECTED)){
		if(!(core[index].second & _UP)){
			temp = findMinLen(core, n, index, _UP, ans);
			if(temp < min) min = temp;
		}
		if(!(core[index].second & _DOWN)){
			temp = findMinLen(core, n, index, _DOWN, ans);
			if(temp < min) min = temp;
		}
		if(!(core[index].second & _LEFT)){
			temp = findMinLen(core, n, index, _LEFT, ans);
			if(temp < min) min = temp;
		}
		if(!(core[index].second & _RIGHT)){
			temp = findMinLen(core, n, index, _RIGHT, ans);
			if(temp < min) min = temp;
		}
	}
	//
    return min;
}


int checkBoard(vector< pair< pair<int, int>, int> > &core, int n){
    for(int i=0; i<core.size(); i++){
    	for(int j=0; j<core.size(); j++){
            if(i != j && !(core[i].second & _CONNECTED)){
            	if(core[i].first.first == core[j].first.first){
                	if(core[i].first.second < core[j].first.second){
                    	core[i].second = core[i].second | _RIGHT;
                        if(!(core[j].second & _CONNECTED)) core[j].second = core[j].second | _LEFT;
                    }
                    else{
                    	core[i].second = core[i].second | _LEFT;
                        if(!(core[j].second & _CONNECTED)) core[j].second = core[j].second | _RIGHT;
                    }
                }
                else if(core[i].first.second == core[j].first.second){
                	if(core[i].first.first > core[j].first.first){
                    	core[i].second = core[i].second | _UP;
                        if(!(core[j].second & _CONNECTED)) core[j].second = core[j].second | _DOWN;
                    }
                    else{
                    	core[i].second = core[i].second | _DOWN;
                        if(!(core[j].second & _CONNECTED)) core[j].second = core[j].second | _UP;
                    }
                }
			}
		}
	}
	return 0;
}