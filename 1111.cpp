#include<iostream>
using namespace std;

int IQTest(int);

int main(){
	int N;
	cin>>N;
	IQTest(N);
	return 0;
}
int IQTest(int N){
	short arr[50] = {0,};
	for(int i=0; i<N; i++)
		cin>>arr[i];
	if(N == 1 || (N == 2 && arr[0] != arr[1])){
		cout<<"A"<<endl;
		return 0;
	}
	bool flag = false;
	for(short a=-200; a<=200; a++){
		short b = arr[1] - a*arr[0];
		short temp = arr[1];
		flag = true;
		for(int i=2; i<N; i++){
			if(b != arr[i] - a*arr[i-1] || arr[i] != temp*a + b){
				flag = false;
				break;
			}
			temp = arr[i];
		}
		if(flag){
			//cout<<"a: "<<a<<" b: "<<b<<endl;
			cout<<arr[N-1] * a + b<<endl;
			return 0;
		}
	}
	cout<<"B"<<endl;
	return 0;
}
