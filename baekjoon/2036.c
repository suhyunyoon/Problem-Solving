#include<stdio.h>

long long arr[100000];
int n;

void swap(int a, int b){
	long long temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void quickSort(int start, int end){
	if(start<end){
		int l=start;
		int r=end;
    	int p = (l+r)/2;
		long long pVal = arr[p];
		// pivot값보다 작은 거는 왼쪽에, pivot값보다 큰거는 오른쪽에 배치시킨다. 
		while(l<=r){
			while(arr[l] < pVal && l<=end) l++;
			while(arr[r] > pVal && r>=start) r--;
			if(l<=r){
				swap(l, r);
				l++;
				r--;
			}
		}
		if(start<r) quickSort(start, r);
		if(l<end) quickSort(l, end); 
   }
}

int main(){
	int i, l, r;
	long long sum = 0;
	// 입력
	scanf("%d",&n);
	for(i=0; i<n; i++)
		scanf("%lld", &arr[i]);
	// 정렬
	quickSort(0, n-1);
	// 양수 음수 모두 절댓값이 큰 2개씩 곱한것을 더하고 1개 남을 경우 더함
	// 음수
	for(l=0; l<n-1; l++){
		if(arr[l] <= 0 && arr[l+1] <= 0) {
			sum += arr[l] * arr[l+1];
			l++;
		}
		else break;
	}
	if(arr[l] <= 0) sum += arr[l];
	// 양수
	for(r=n-1; r>0; r--){
		if(arr[r] > 1 && arr[r-1] > 1){
			sum += arr[r] * arr[r-1];
			r--;
		}
		else if(arr[r] > 0) sum += arr[r];
		else break;	
	}
	if(arr[r] > 0) sum += arr[r];
	printf("%lld\n", sum);
	return 0;
}