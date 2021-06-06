#include<iostream>
#include<vector>
using namespace std;

int availablePos(int x1, int y1, int r1, int x2, int y2, int r2){
    int distSQ, sumSQ, subSQ;
	distSQ = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	sumSQ = (r1+r2)*(r1+r2); subSQ = r1 > r2 ? (r1-r2)*(r1-r2) : (r2-r1)*(r2-r1);
	if(distSQ == sumSQ || distSQ == subSQ){
		if(x1 == x2 && y1 == y2) return -1;
		else return 1;
	}
	else if (distSQ < sumSQ && distSQ > subSQ) return 2;
	else return 0;
}

int main(){
    int N, temp;
    vector<int> arr;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<6; j++){
            cin>>temp;
            arr.push_back(temp);
        }
        cout<<availablePos(arr[i*6 + 0],arr[i*6 + 1],arr[i*6 + 2],arr[i*6 + 3],arr[i*6 + 4],arr[i*6 + 5])<<"\n";
    }
    
}
