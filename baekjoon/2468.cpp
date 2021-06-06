#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Heights{
public:
	int h;
	vector<int> arr;
	Heights(int h){this->h = h;}
	// 내림차순
	bool operator<(Heights other){ return h > other.h; }
};

int n;
vector<int> arr;
vector<Heights> h;
// 실제 index값 +1을 저장
map<int, int> index;

int find(int x){
	if(x == arr[x]) return x;
	return arr[x] = find(arr[x]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b)
		arr[a] = b;
}

int main(){
	int temp;
	cin>>n;
	int len = n*n;
	arr = vector<int>(len, -1);
	for(int i=0; i<len; i++){
		cin>>temp;
		if(!index[temp]){
			h.push_back(Heights(temp));
			index[temp] = h.size();
		}
		h[index[temp]-1].arr.push_back(i);
	}
	
	sort(h.begin(), h.end());
	
	int a, b;
	len = h.size();
	int max = 0, last = 0;
	for(int i=0; i<len; i++){
		int jlen = h[i].arr.size();
		temp = last;
		for(int j=0; j<jlen; j++){
			int k = h[i].arr[j];
			arr[k] = k;
			temp++;
			// 4dir union-find
			if(k % n > 0 && arr[k-1] != -1){
				a = find(k); b = find(k-1);
				if(a != b){
					join(k, k-1);
					temp--;
				}
			}
			if(k % n < n-1 && arr[k+1] != -1){
				a = find(k); b = find(k+1);
				if(a != b){
					join(k, k+1);
					temp--;
				}
			}
			if(k / n > 0 && arr[k-n] != -1){
				a = find(k); b = find(k-n);
				if(a != b){
					join(k, k-n);
					temp--;
				}
			}
			if(k / n < n-1 && arr[k+n] != -1){
				a = find(k); b = find(k+n);
				if(a != b){
					join(k, k+n);
					temp--;
				}
			}
		}
		// update
		if(max < temp) max = temp;
		last = temp;
		//cout<<temp<<endl;
	}
	cout<<max<<endl;
	return 0;
}