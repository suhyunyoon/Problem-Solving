// 1181_단어_정렬.c

#include<stdio.h>
#include<string.h>

char str[20000][51];

void swap(char a[51], char b[51]){
	char temp[51];
	strcpy(temp, a);
	strcpy(a,b);
	strcpy(b,temp);    
}

// 길이를 먼저 비교 후 strcmp로 알파벳순 비교
int sstrcmp(char a[51], char b[51]){
	int alen = strlen(a);
	int blen = strlen(b);
	if(alen > blen) return 1;
	else if(alen < blen) return -1;
	else{
		return strcmp(a,b);
	}
}

void quickSort(int start, int end){
	if(start<end){
		int l=start;
		int r=end;
    	int p = (l+r)/2; 
    	char pStr[51];
		strcpy(pStr, str[p]);
		// pivot값보다 작은 거는 왼쪽에, pivot값보다 큰거는 오른쪽에 배치시킨다. 
		while(l<=r){
			while(sstrcmp(str[l], pStr) < 0 && l<=end) l++;
			while(sstrcmp(str[r], pStr) > 0 && r>=start) r--;
			if(l<=r){
				swap(str[l],str[r]);
				l++;
				r--;
			}
		}
		if(start<r) quickSort(start, r);
		if(l<end) quickSort(l, end); 
   }
}

int main(){
	int i, n;
	// 입력
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", str[i]);
	}
	// 정렬(Quick sort)
	quickSort(0,n-1);
	// 중복되는 것은 제외하면서 출력
	printf("%s\n",str[0]);
	for(i=1; i<n; i++){
		if(sstrcmp(str[i], str[i-1]) != 0){
			printf("%s\n", str[i]);
		}
	}
	return 0;
}