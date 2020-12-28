#include<stdio.h>

long long constructBridge();
long long combination(int, int);

int main(){
	constructBridge();	
	return 0;
}

long long constructBridge(){
	int N, i;
	int a, b;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d %d", &a, &b);
		printf("%lld\n", combination(b,a));
	}
	return 0;
}

long long combination(int a, int b){
	long long mul = 1;
	int p_a, p_b = 2;
	for(p_a = a; p_a > a-b; p_a--){
		mul *= p_a;
		while(p_b <= b && mul % p_b == 0){
			mul /= p_b;
			p_b++;
		}
	}
	return mul;
}