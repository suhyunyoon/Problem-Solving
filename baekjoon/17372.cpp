#include<iostream>
#include<vector>
using namespace std;

long long gcd(long long, long long);
long long gcdFib(int);

int main(){
	//gcdFib(0);
	for(int i=2; i<=200; i++)
		cout<<(gcdFib(i) - gcdFib(i-1) + 1000000007) % 1000000007<<" ";
	cout<<endl;
	return 0;
}

long long gcdFib(int n){
	vector<long long> fib(2,1);
	long long sum = 0;
	
	if(n == 0)cin>>n;
	
	if(n == 1)fib.pop_back();
	else if(n == 0)fib.clear();
	for(int i=2; i<n; i++)
		fib.push_back(fib[i-2] + fib[i-1]);
	
	/*for(int i=0; i<n; i++)
		cout<<fib[i]<<' ';
	cout<<endl;*/
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			sum = (sum + gcd(fib[i], fib[j])) % 1000000007;
	//cout<<sum<<endl;
	return sum;
}

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else
		return gcd(b, a%b);
}