#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

// 방 N개에 간선 N-1개, 두 방을 연결하는 간선이 하나뿐이므로 Cycle이 없음. => Tree형태임
// s에서 d까지 가는 경로는 하나밖에 없으므로
// 두 로봇이 하나의 간선만 사이에 두게 이동하려면 그 사이에 둔 간선이 경로중에 가장 가중치가 큰 간선이어야 함
// -> 경로를 찾고, 경로의 총 길이 - 경로에서 가장 큰 길이 뺌

// 2차원 벡터 link[노드 번호][다음 노드 번호]
// queue에 두개의 pair가 있지만(클래스로 만들걸) 들어가는건 (노드 번호 / 해당 노드의 부모 / 현재까지 경로의 최대 간선 / 현재까지 경로의 합)
// 먼저 s == d일때 예외처리
// bfs로 경로를 찾은 후 경로 합 - 최대간선 출력
int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	// index, parent, max weight, total len
	queue<pair<pair<int,int>, pair<int,int>>> myQueue;
	int n, u, v, w, s, d;
	cin>>n>>s>>d;
	// 0-addressing
	s--; d--;
	if(s == d){
		cout<<0<<'\n';
		return 0;
	}
	vector<vector<pair<int,int>>> link(n, vector<pair<int,int>>(0));
	for(int i=1; i<n; i++){
		cin>>u>>v>>w;
		link[u-1].push_back(make_pair(v-1, w));
		link[v-1].push_back(make_pair(u-1, w));
	}
	//for(int i=0; i<link[s].size(); i++)
//		myQueue.push(make_pair(make_pair(link[s][i].first, s),make_pair(link[s][i].second, link[s][i].second)));
	myQueue.push(make_pair(make_pair(s, -1),make_pair(0,0)));
	while(myQueue.size()){
		//cout<<myQueue.front().first.first<<'\n';
		for(int i=0; i<link[myQueue.front().first.first].size(); i++){
			// d에 도착했는지 검사
			if(link[myQueue.front().first.first][i].first == d){
				w = max(link[myQueue.front().first.first][i].second, myQueue.front().second.first);
				w = myQueue.front().second.second+link[myQueue.front().first.first][i].second - w;
				cout<<w<<'\n';
				return 0;
			}
			// 다음 경로를 queue에 push해줌
			else if(myQueue.front().first.second != link[myQueue.front().first.first][i].first){
				myQueue.push(make_pair(make_pair(link[myQueue.front().first.first][i].first, myQueue.front().first.first),
					make_pair(max(link[myQueue.front().first.first][i].second, myQueue.front().second.first),
						myQueue.front().second.second+link[myQueue.front().first.first][i].second)));
			}	
		}
		myQueue.pop();
	}
	cout<<0<<'\n';
	return 0;
}