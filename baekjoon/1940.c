#include<stdio.h>

unsigned int material[15000];
int n;
unsigned int m;

void swap(int a, int b){
	int temp;
	temp = material[a];
	material[a] = material[b];
	material[b] = temp;
}

void quickSort(int start, int end){
	if(start<end){
		int l=start;
		int r=end;
    	int p = (l+r)/2;
		int pVal = material[p];
		// pivot값보다 작은 거는 왼쪽에, pivot값보다 큰거는 오른쪽에 배치시킨다. 
		while(l<=r){
			while(material[l] < pVal && l<=end) l++;
			while(material[r] > pVal && r>=start) r--;
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
	int i, cnt, l, r;
	// 입력
	scanf("%d", &n);
	scanf("%u", &m);
	for(i=0; i<n; i++)
		scanf("%u", &material[i]);
	// 정렬
	quickSort(0, n-1);
	// 양쪽에서부터 합이 m이 되는 set 찾기
	l = 0; r = n-1; cnt = 0;
	while(l < r){
		// 재료 찾음
		if(material[l]+material[r] == m){
			cnt++;
			l++; r--;
		}
		else if(material[l]+material[r] > m) r--;
		else l++;
	}
	printf("%d\n", cnt);
	return 0;
}