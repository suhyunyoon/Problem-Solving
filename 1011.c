#include<stdio.h>
// gcc <file> -lm
#include<math.h>

int calcDist();
int minJump(unsigned int);

int main(){
	calcDist();
	return 0;
}

int calcDist(){
	int N, i;
	unsigned int a, b;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%u %u", &a, &b);
		printf("%d\n", minJump(b - a));
	}
	return 0;
}

int minJump(unsigned int dist){
	unsigned int tempSqrt;
	int k;
	tempSqrt = (int)sqrt(dist-1);
	
	k = dist > (tempSqrt*(tempSqrt + 1)) ? (int)(tempSqrt*2+1) : (int)(tempSqrt*2);
	return k;
}