#include<iostream>
#include<vector>
using namespace std;

const int SIZE = 10;
int globalmin = 100;

bool post(vector<vector<int>> &arr, int ipos, int jpos, int n){
	for(int i=ipos; i<ipos+n; i++)
		for(int j=jpos; j<jpos+n; j++)
			if(i>=SIZE || j>=SIZE || arr[i][j]==0) return false;
	return true;
}

int f(vector<vector<int>> arr, vector<int> qtt, int ipos, int jpos, int n, int min){
	if(min > globalmin) return -1;
	for(int i=ipos; i<ipos+n; i++)
		for(int j=jpos; j<jpos+n; j++)
			arr[i][j] = 0;
	if(n) qtt[n-1]--;
	//cout<<ipos<<' '<<jpos<<' '<<n<<' '<<min<<endl;
	for(int i=ipos; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			if(arr[i][j]){
				int temp, tempmin = 100;
				for(int k=5; k>0; k--){
					if(qtt[k-1] && post(arr,i,j,k)){
						temp = f(arr, qtt, i, j, k, min+1);
						if(tempmin > temp && temp != -1){
							tempmin = temp;
							if(globalmin > tempmin) globalmin = tempmin;
						}
					}
				}
				if(tempmin == 100) return -1;
				else return tempmin;
			}
		}
	}
	return min;
}

int main(){
	vector<vector<int>> arr(10, vector<int>(10, 0));
	vector<int> qtt(5,5);
	int ans;
	for(int i=0; i<SIZE; i++)
		for(int j=0; j<SIZE; j++)
			cin>>arr[i][j];
	ans = f(arr,qtt,0,0,0,0);
	
	cout<<ans<<'\n';
	return 0;
}