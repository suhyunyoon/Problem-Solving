#include<stdio.h>
#include<math.h>

// n이 1~k일때 (k/i)+1 ~ (k/i-1)에서 i-1만큼 값을 곱하는 역순열이 나옴
// ~(k/sqrt(k))+1 까지 루프, k%(k/i-1)가 시작값인 (k/i-1 - k/i)(k/i-1 - k/i + 1)/2 + (k/i-1 - k/2)(k%k/i-1)

long long calcSlice(long long k, long long i, long long flag){
	long long temp, slice;
	if(flag)
		temp = k/(i-1) - flag;
	else 
		temp = k/(i-1) - k/i;
	slice = (k%(k/(i-1)))*temp + (i-1)*temp*(temp-1)/2;
	return slice;
}

long long josephus(long long n, long long k){
	long long i,sum = 0;
	for(i=1; i<=n; i++)
		sum += k % i;
	return sum;
}

long long wrongJosephus(long long n, long long k){
	long long i, temp;
	long long sum = 0;
	long long rootK;
	int flag;
	rootK = sqrt((double)k);
	// ~ k/sqrt(k)
	flag = 1;
	for(i=1; i<=k/rootK; i++){
		sum += k%i;
		//printf("sum: %lld\n", sum);
		if(n < k && n <= i){
			flag = 0;
			break;
		}
	}
	//printf("sum: %lld\n", sum);
	// 자름
	if(flag){
		for(i=rootK; i>1; i--){
			sum += calcSlice(k, i, 0);
			if(n < k && n <= k/(i-1) && n > k/i){
				//printf("sum :%lld\n", sum);	
				sum -= calcSlice(k, i, n);
				//printf("sum :%lld\n", sum);	
				break;
			}
		}
	}
	//printf("sum :%lld\n", sum);	
	sum += (n > k ? k*(n - k) : 0);	
	//printf("sum after :%lld\n", sum);	
	return sum;
}

int main(){
	int n,k, i;
	scanf("%d %d", &n, &k);
	printf("%lld\n", wrongJosephus(n,k));
	//printf("%lld\n", josephus(n,k));
	return 0;
}