#include<iostream>
#include<vector>
using namespace std;

const int SIZE=9;
int n;
vector<vector<int>> arr;

int play(vector<int> &order){
	int index = 0, score=0;
	for(int i=0; i<n; i++){
		int out = 0;
		bool plate[4] = {false,};
		while(out < 3){
			plate[0] = true;
			if(arr[i][order[index]]){
				for(int k=3; k>=0; k--){
					if(plate[k]){
						if(k+arr[i][order[index]] >= 4){
							plate[k] = false;
							score++;
						}
						else{
							plate[k+arr[i][order[index]]] = true;
							plate[k] = false;
						}
					}
				}
			}
			else
				out++;
			index = (index+1) % SIZE;
		}
	}
	return score;
}

bool findElm(vector<int> &order, int num){
	for(int i=0; i<SIZE; i++)
		if(order[i] == num) return true;
	return false;
}

int inning(int num, vector<int> order, int player){
	if(num >= 0) order[num] = player;
	if(num >= SIZE-1){
		return play(order);
	}
	
	int temp, max = 0;
	// 4번
	if(num==2) max = inning(num+1, order, 0);
	else {
		for(int i=1; i<SIZE; i++)
			if(!findElm(order,i)){
				temp = inning(num+1, order, i);
				if(max < temp) max = temp;
			}
	}
	return max;
}

int main(){
	int ans;
	cin>>n;
	arr = vector<vector<int>>(n, vector<int>(SIZE, 0));
	vector<int> order(SIZE, 0);
	for(int i=0; i<n; i++)
		for(int j=0; j<SIZE; j++)
			cin>>arr[i][j];
	ans = inning(-1, order, 0);
	cout<<ans<<endl;
	return 0;
}