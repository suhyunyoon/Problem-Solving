#include<iostream>
#include<vector>
using namespace std;

class Rotation{
public:
	int r, c, s;
	Rotation(int r, int c, int s){
		this->r = r; this->c = c; this->s = s;
	}
};

vector<Rotation> r;
vector<int> order;
int n, m, k;

void print(vector<vector<int>> & arr){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}


int calcMin(vector<vector<int>> &arr){
	int temp, minVal = 10000;
	for(int i=0; i<n; i++){
		temp = 0;
		for(int j=0; j<m; j++){
			temp += arr[i][j];
		}
		if(minVal > temp) minVal = temp;
	}
	return minVal;
}

void rotate(vector<vector<int>> &arr, int index){
	int tr = r[index].r-1, tc = r[index].c-1, ts = r[index].s;
	
	for(int s = 1; s <= ts; s++){
		int temp = arr[tr-s][tc+s];
		for(int i=tc+s; i>=tc-s+1; i--) arr[tr-s][i] = arr[tr-s][i-1];
		for(int i=tr-s; i<tr+s; i++) arr[i][tc-s] = arr[i+1][tc-s];
		for(int i=tc-s; i<tc+s; i++) arr[tr+s][i] = arr[tr+s][i+1];
		for(int i=tr+s; i>=tr-s+1; i--) arr[i][tc+s] = arr[i-1][tc+s];
		arr[tr-s+1][tc+s] = temp;
	}
	
	cout<<tr<<' '<<tc<<' '<<ts<<endl;
	print(arr);
}

int f(vector<vector<int>> arr, int index, int num){
	if(index >= 0)
		rotate(arr, num);
	// end
	if(index >= k-1){
		return calcMin(arr);
	}
	// next
	int temp, minVal = 10000;
	for(int i=0; i<k; i++){
		int j;
		for(j=0; j<index; j++){
			if(order[j] == i) break;
		}
		if(index != num && (j==index || index == -1)){
			order.push_back(num);
			temp = f(arr, index+1, i);
			order.pop_back();
			if(minVal > temp) minVal = temp;
		}
	}
	return minVal;
}

int main(){
	int temp[3];
	cin>>n>>m>>k;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<int> order(k, -1);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>arr[i][j];
	for(int i=0; i<k; i++){
		for(int j=0; j<3; j++) cin>>temp[j];
		r.push_back(Rotation(temp[0], temp[1], temp[2]));
	}
	int ans = f(arr, -1, 0);
	cout<<ans<<'\n';
}