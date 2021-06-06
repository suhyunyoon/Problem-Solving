#include<iostream>
#include<string>
using namespace std;
int main(){
	string set;
	int n = 0, sum = 0;
	cin>>set;
	int len = set.length();
	for(int i=0; i<len; i++){
		if(set[i] == '('){
			if(set[i+1] == '(') n++;
			// laser
			else if(set[i+1] == ')'){
				sum += n;
				i++;
			}
		}
		else if(set[i] == ')'){
			n--;
			sum++;
		}
	}
	cout<<sum<<'\n';
	return 0;
}