#include<iostream>
#include<string>
using namespace std;
int main(){
	string str[3];
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=0; j<3; j++) cin>>str[j];
		cout<<"#"<<i<<" "<<(char)(str[0][0] + 'A' - 'a')<<(char)(str[1][0] + 'A' - 'a')<<(char)(str[2][0] + 'A' - 'a')<<'\n';
	}
	return 0;
}