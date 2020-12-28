#include<iostream>
using namespace std;

int main(){
	int N;
	unsigned int cnt;
	int m, n, x, y, v, init;
	bool flag;
	cin>>N;
	for(int i=0; i<N; i++){
		flag = false;
		cin>>m>>n>>x>>y;
		init = (x-1)%n + 1; cnt = x; v = init;
		do{
			if(v == y){
				flag = true;
				break;
			}
			v = (v+m-1)%n + 1;
			cnt += m;
		}while(v != init);
		if(flag)cout<<cnt<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
