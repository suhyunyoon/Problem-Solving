#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
vector<pair<int, int>> p;
vector<int> X;
vector<int> Y;

vector<int> cntY;
vector<int> cntX;

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		p.push_back(make_pair(x,y));
		X.push_back(x);
		Y.push_back(y);
	}
	p.push_back(*p.begin());
	
	sort(X.begin(), X.end());
	sort(Y.begin(). Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	
	cntX.resize(X.size());
	cntY.resize(Y.size());
	for(int i=0; i<n; i++){
		int j= i+1;
		if(p[i].first == p[j].first){
			int y1 = p[i].second;
			int y2 = p[j].second;
			if(y1 > y2) swap(y1, y2);
			
			int pos1 = lower_bound(Y.begin(), Y.end(), y1) -Y.begin();
			int pos2 = lower_bound(Y.begin(), Y.end(), y2) -Y.begin();
			cntY[pos1]++;
			cntY[pos2]--;
		}
		else{
			int x1 = p[i].first;
			int x2 = p[j].first;
			if(x1 > x2) swap(x1, x2);
			
			int pos1 = lower_bound(X.begin(), X.end(), x1) -X.begin();
			int pos2 = lower_bound(X.begin(), X.end(), x2) -X.begin();
			cntX[pos1]++;
			cntX[pos2]--;
		}
	}
	for(int i=1; i<cntX.size(); i++){
		cntX[i] += cntX[i-1];
	}
	for(int i=1; i<cntY.size(); i++){
		cntY[i] += cntY[i-1];
	}
	int ans = max(*max_element(cntX.begin(), cntX.end()), *max_element(cntY.begin(), cntY.end()));
	cout<<ans<<'\n';
}