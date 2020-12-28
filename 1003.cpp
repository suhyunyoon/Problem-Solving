#include<iostream>
using namespace std;
int main(){
	int N, testcase,temp, fib0,fib1;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>testcase;
		if(!testcase) cout<<"1 0"<<endl;
		else{
			fib0 = 0; fib1 = 1;
			for(int j=1; j<testcase; j++){
				temp = fib0; 
				fib0 = fib1;
				fib1 += temp;
			}
			cout<<fib0<<" "<<fib1<<endl;
		}
	}
	return 0;
}