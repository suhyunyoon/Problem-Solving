#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Tomato{
public:
	int i;
	int j;
	int day;
	Tomato(int i, int j, int d){
		this->i = i;
		this->j = j;
		this->day = d;
	}
};

vector<vector<int>> box;
queue<Tomato> tomato;
int fresh, day;

int main(){
	int n, m;
	// input & init
	fresh = 0; day = 0;
	cin>>m>>n;
	box = vector<vector<int>>(n,vector<int>(m, 0));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>box[i][j];
			if(box[i][j] != -1) fresh++;
			if(box[i][j] == 1) tomato.push(Tomato(i,j,0));
		}
	}
	if(!fresh){
		cout<<0<<'\n';
		return 0;
	}
	// bfs
	while(tomato.size()){
		Tomato &t = tomato.front();
		fresh--;
		if(day < t.day) day = t.day;
		// 4-direction
		if(t.i > 0 && !box[t.i - 1][t.j]){
			box[t.i - 1][t.j] = t.day+1;
			tomato.push(Tomato(t.i-1, t.j, t.day+1));
		}
		if(t.i < n-1 && !box[t.i + 1][t.j]){
			box[t.i + 1][t.j] = t.day+1;
			tomato.push(Tomato(t.i+1, t.j, t.day+1));
		}
		if(t.j > 0 && !box[t.i][t.j - 1]){
			box[t.i][t.j - 1] = t.day+1;
			tomato.push(Tomato(t.i, t.j-1, t.day+1));
		}
		if(t.j < m-1 && !box[t.i][t.j + 1]){
			box[t.i][t.j + 1] = t.day+1;
			tomato.push(Tomato(t.i, t.j+1, t.day+1));
		}

		tomato.pop();
	}
	// print
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<box[i][j]<<' ';
		}cout<<'\n';
	}
	if(fresh) day = -1;
	cout<<day<<'\n';

	return 0;
}