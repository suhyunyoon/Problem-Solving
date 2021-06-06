#include<iostream>
#include<string>
using namespace std;

string ret = "";

long long gcd(long long a, long long b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

long long repComb(int n, int m){
	int j = 2;
	long long mul = 1;
	long long jmul = 1;
	long long divisor;
	if(n < m){
		int temp = n;
		n = m;
		m = temp;
	}
	// n+m C n
	for(int i=n+1; i<=n+m; i++){
		for(; j<=m; j++){
			if((jmul*j)%100000 != ((jmul%100000)*j)%100000) break;
			jmul *= j;
		}
		// overflow하는지 검사
		if((mul*i)%100000 != ((mul%100000)*i)%100000) return 0;
		mul *= i;
		// 약분
		divisor = gcd(mul, jmul);
		mul /= divisor; jmul /= divisor;
	}
	return mul;
}

void addStr(int n, int m, long long k){
	if(n <= 0){
		// k가 너무 클 때
		if(k > 1){
			ret = "";
			cout<<-1;
			return;
		}
		while(m > 0){
			ret += 'z';
			m--;
		}
		return;
	}
	else if(m <= 0){
		// k가 너무 클 때
		if(k > 1){
			ret = "";
			cout<<-1;
			return;
		}
		while(n > 0){
			ret += 'a';
			n--;
		}
	}
	else{
		long long mid = repComb(n-1, m);
		if(!mid || k <= mid){
			ret += 'a';
			addStr(n-1, m, k);
		}
		else {
			ret += 'z';
			addStr(n, m-1, k-mid);
		}
	}
}

int main(){
	int n, m;
	long long k;
	cin>>n>>m>>k;
	addStr(n, m, k);
	cout<<ret<<'\n';
	return 0;
}