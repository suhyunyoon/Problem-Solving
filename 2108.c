#include<stdio.h>
#include<stdlib.h>

int arr[500000];
int n;

void swap(int a, int b){
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void quickSort(int start, int end){
	if(start<end){
		int l=start;
		int r=end;
    	int p = (l+r)/2;
		int pVal = arr[p];
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

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;    // 오름차순
}

int main(){
	int i, avg, mid, mode, modeVal, modeCnt, flag, range;
	long long sum = 0;
	// 입력
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	// 정렬
	qsort(arr, n, sizeof(int), compare);
	//quickSort(0, n-1);
	//for(i=0; i<n; i++)printf("%d ", arr[i]); printf("\n");
	// 평균
	avg = (int)(sum > 0 ? ((double)sum / n) + 0.5 : ((double)sum / n) - 0.5); 
	// 중앙값
	mid = arr[(n-1)/2];
	// 최빈값
	// flag는 몇번째 같은 최빈값인지
	mode = 1; modeVal = arr[0]; modeCnt = 1; flag = 0;
	for(i=1; i<n; i++){
		if(arr[i] == arr[i-1]) modeCnt++;
		else{
			if(mode < modeCnt) {
				mode = modeCnt;
				modeVal = arr[i-1];
				flag = 0;
			}
			else if(mode == modeCnt && flag < 2){
				modeVal = arr[i-1];
				flag++;
			}
			else mode = 1;
			modeCnt = 1;
		}
	}
	if(mode < modeCnt || (mode == modeCnt && flag < 2)) modeVal = arr[i-1];
	// 범위
	range = arr[n-1] - arr[0];
	// 출력
	printf("%d\n%d\n%d\n%d\n", avg, mid, modeVal, range);
	return 0;
}