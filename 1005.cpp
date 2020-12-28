#include<iostream>
#include<vector>

using namespace std;

// 부모: (idx-1)/2	자식 left: idx*2 + 1	right: idx*2 + 2
// BottomUp
int insertNode(vector< pair<int, int> >& buildingHeap, vector< pair<int , vector<int> > >& buildings, int id, int time){
	int pivot;
	buildingHeap.push_back(make_pair(id, time));
	pivot = buildingHeap.size()-1;
	while(pivot){
		if(buildingHeap[pivot].second < buildingHeap[(pivot-1)/2].second){
			swap(buildingHeap[pivot], buildingHeap[(pivot-1)/2]);
			pivot = (pivot-1)/2;	
		}
		else break;
	}	
	return time;
}

// TopDown
int deleteNode(vector< pair<int, int> >& buildingHeap, vector< pair<int , vector<int> > >& buildings){
	int reducedTime, nextPivot, pivot = 0;
	swap(buildingHeap.front(), buildingHeap.back());
	reducedTime = buildingHeap.back().second;
	buildingHeap.pop_back();
	while(pivot*2 + 1 < buildingHeap.size()){
		// left만 있을 때
		if(buildingHeap.size() == pivot*2 + 2)
			nextPivot = pivot*2 + 1;
		// 왼쪽이 더 작을 때
		else if(buildingHeap[pivot*2 + 1].second <= buildingHeap[pivot*2 + 2].second)
			nextPivot = pivot*2 + 1;
		// 오른쪽이 더 작을 때
		else
			nextPivot = pivot*2 + 2;
		// swap
		if(buildingHeap[pivot].second > buildingHeap[nextPivot].second)
			swap(buildingHeap[pivot], buildingHeap[nextPivot]);
		else break;
	}
	vector< pair<int, int> >::size_type N = buildingHeap.size();
	for(vector< pair<int, int> >::size_type i=0; i<N; i++)
		buildingHeap[i].second -= reducedTime;
	return reducedTime;
}

int calcMinTime(){
	int N, K, timeSum = 0;
	int tempa, tempb, finalBuilding;
	// id, time
	vector< pair<int, int> > buildingHeap;
	// time, prevBuildings
	vector< pair<int, vector<int> > > buildings;
	vector<vector<int> > requiredBuildings;
	// isBuilt
	vector<bool> isBuilt;
	// input
	cin>>N>>K;
	for(int i=0; i<N; i++){
		cin>>tempa;
		buildings.push_back( make_pair(tempa, vector<int>()) );
		requiredBuildings.push_back(vector<int>());
		isBuilt.push_back(false);
	}
	for(int i=0; i<K; i++){
		cin>>tempa>>tempb;
		buildings[tempa-1].second.push_back(tempb-1);
		requiredBuildings[tempb-1].push_back(tempa-1);
		isBuilt[tempb-1] = true;
	}
	cin>>finalBuilding;
	finalBuilding--;
	
	// isBuilt == false 이면 insert
	vector<bool>::size_type len = isBuilt.size();
	for(vector<bool>::size_type i=0; i<len; i++)
		if(!isBuilt[i])
			insertNode(buildingHeap, buildings, i, buildings[(vector< pair<int, vector<int> > >::size_type)i].first);
	
	// insert 다하고 isBuilt 전부 false로 만들어주기
	for(vector<bool>::size_type i=0; i<len; i++)
		isBuilt[i] = false;
	// heap이 빌 때까지
	while(buildingHeap.size() > 0){
		int deletedID = buildingHeap.front().first;
		int nextLen;
		// 제거한 노드의 시간만큼 추가
		timeSum += deleteNode(buildingHeap, buildings);
		isBuilt[(vector<bool>::size_type)deletedID] = true;
		// run ends when final building constructed
		if(deletedID == finalBuilding)
			return timeSum;
		
		nextLen = buildings[deletedID].second.size();
		for(vector<int>::size_type i=0; i<nextLen; i++)
			if(!isBuilt[buildings[deletedID].second[i]]){
				bool buildable = true;
				vector<int>::size_type requiredLen = requiredBuildings[buildings[deletedID].second[i]].size();
				for(vector<int>::size_type j=0; j<requiredLen; j++)
					if(!isBuilt[requiredBuildings[buildings[deletedID].second[i]][j]]){
						buildable = false;
						break;
					}
				if(buildable)insertNode(buildingHeap, buildings, buildings[deletedID].second[i], buildings[(vector< pair<int, vector<int> > >::size_type)buildings[deletedID].second[i]].first);
			}
	}
	return timeSum;
}
int winACMCraft(int t){
	int T;
	// input
	if(t) T = t;
	else cin>>T;
	for(int i=0; i<T; i++){
		cout<<calcMinTime()<<endl;
	}
	return 0;
}
int main(){
	winACMCraft(0);
	return 0;
}