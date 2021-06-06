#include<iostream>
#include<string>
#include<vector>
using namespace std;

int len;

int calc(int n1, int n2, char op){
	if(op == '+') return n1+n2;
	else if(op == '-') return n1-n2;
	else if(op == '*') return n1*n2;
	else n2;
}

int f(string &exp, int i, int ret){
	// 마지막 숫자
	if(i == len)
		return calc(ret, (int)(exp[i] - '0'), exp[i-1]);
	else if(i > len) return ret;
	int n1, n2;
	n1 = f(exp, i+2, calc(ret, (int)(exp[i] - '0'), exp[i-1]));
	n2 = f(exp, i+4, calc(ret, calc((int)(exp[i] - '0'), (int)(exp[i+2] - '0'), exp[i+1]), exp[i-1]));
	return n1>n2?n1:n2;
}

int main(){
	int max;
	string exp;
	cin>>len;
	cin>>exp;
	exp = '+' + exp;
	max = f(exp, 1, 0);
	
	cout<<max<<'\n';
	
	return 0;
}