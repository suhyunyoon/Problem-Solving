#include<iostream>
#include<vector>
using namespace std;

class Std{
public:
	int cls;
	int status;
	Std(int c = -1, int s = -1){
		this->cls = c;
		this->status = s;
	}
};

int insertHeap(vector<Std>& arr, int cls, int status){
	Std temp;
	int pos;
	arr.push_back(Std(cls, status));
	pos = arr.size() - 1;
	while(pos != 0 && arr[pos].status < arr[(pos-1)/2].status){
		// change std
		temp = arr[pos];
		arr[pos] = arr[(pos-1)/2];
		arr[(pos-1)/2] = temp;
		pos = (pos-1)/2;
	}
	return 0;
}

Std deleteHeap(vector<Std>& arr){
	int pos = 0, last = arr.size()-1;
	Std temp, ret = arr[0];
	arr[0] = arr[last--];
	arr.pop_back();
	while(pos*2 <= last){
		// choose 
		if(pos*2+2 > last || (arr[pos*2+1].status < arr[pos*2+2].status && arr[pos].status > arr[pos*2+1].status))
			pos = pos*2+1;
		else if(arr[pos].status > arr[pos*2+2].status) pos = pos*2+2;
		else break;
		// change std
		temp = arr[pos];
		arr[pos] = arr[(pos-1)/2];
		arr[(pos-1)/2] = temp;
	}
	return ret;
}

int bsearch(vector<int>& arr, int v){
	int pos, s = 0, d = arr.size()-1;
	while(s <= d){
		pos = (s+d)/2;
		if(arr[pos] == v) return pos;
		else if(arr[pos] < v) s = pos+1;
		else d = pos-1;
	}
	return -1;
}

int main(){
	int n,m,temp;
	vector<Std> input, arr;
	vector<int> window, lastPos;
	// input
	cin>>n>>m;
	for(int i=0; i<n; i++){
		lastPos.push_back(-1);
		for(int j=0; j<m; j++){
			cin>>temp;
			// heap sort(insert)
			insertHeap(input,i,temp);
		}
	}
	// heap sort(delete)
	Std tempstd;
	while(input.size()) {
		tempstd = deleteHeap(input);
		insertHeap(arr, tempstd.cls, tempstd.status);
	}
	// make window
	int wlen, pos, min = 1000000001, len = arr.size();	
	for(int i=0; i<len; i++){
		// 새 데이터랑 중복되는 반 있으면 지움
		if(lastPos[arr[i].cls] != -1){
			pos = bsearch(window, lastPos[arr[i].cls]);
			if(pos > -1) window.erase(window.begin() + pos);
		}
		lastPos[arr[i].cls] = arr[i].status;
		window.push_back(arr[i].status);
		wlen = window.size();
		// 최솟값 검사
		if(wlen == n){
			if(window[wlen-1] - window[0] < min) min = window[wlen-1] - window[0];
		}
	}
	cout<<min<<'\n';
	return 0;
}