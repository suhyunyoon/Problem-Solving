#include<iostream>
#include<string>
using namespace std;

int parsing(string);

int main(){
	int N;
	string temp;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>temp;
		parsing(temp);
	}
	return 0;
}
// (100+1+ | 01)+
int parsing(string str){
	// 0~8, -1: 막다른 길
	int state = 0;
	for(int i=0; i<str.length(); i++){
		switch(state){
			case 0:
				state = str[i] == '0' ? 1 : 2;
				break;
			case 1:
				state = str[i] == '0' ? -1 : 3;	
				break;
			case 2:			
				state = str[i] == '0' ? 4 : -1;
				break;
			case 3:
				state = str[i] == '0' ? 1 : 2;
				break;
			case 4:
				state = str[i] == '0' ? 5 : -1;
				break;
			case 5:
				state = str[i] == '0' ? 5 : 6;
				break;
			case 6:
				state = str[i] == '0' ? 1 : 7;
				break;
			case 7:
				state = str[i] == '0' ? 8 : 7;
				break;
			case 8:
				state = str[i] == '0' ? 5 : 3;	
			default:
				break;
		}
	}
	if(state == 3 || state == 6 || state == 7) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}