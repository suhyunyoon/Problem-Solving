#include<stdio.h>
#include<string.h>

// 입력받는 문자열
char arr[100][101];
// 문자열로 저장할 숫자들
char nums[10000][101];
int n, m;

void swap(int a, int b){
	char temp[101];
	strcpy(temp, nums[a]);
	strcpy(nums[a], nums[b]);
	strcpy(nums[b], temp);
}

// 길이를 먼저 비교 후 strcmp로 크기 비교
int sstrcmp(char a[101], char b[101]){
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
    	char pStr[101];
		strcpy(pStr, nums[p]);
		// pivot값보다 작은 거는 왼쪽에, pivot값보다 큰거는 오른쪽에 배치시킨다. 
		while(l<=r){
			while(sstrcmp(nums[l], pStr) < 0 && l<=end) l++;
			while(sstrcmp(nums[r], pStr) > 0 && r>=start) r--;
			if(l<=r){
				swap(l,r);
				l++;
				r--;
			}
		}
		if(start<r) quickSort(start, r);
		if(l<end) quickSort(l, end); 
   }
}

int main(){
	int i, j, flag;
	// 입력
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%s", arr[i]);
	// 숫자 분리해서 arr에 넣음
	m = 0;
	for(i=0; i<n; i++){
		// 숫자 입력중일때 flag > 0
		j = -1; flag = 0;
		do{
			j++;
			// 첫 0이나오면 다음이 숫자가 아니면 0 저장 (아님 무시)
			if(!flag && arr[i][j] == '0'){
				if(arr[i][j+1] > '9' || arr[i][j+1] < '0'){
					strcpy(nums[m], "0\0"); m++;
					flag = 0;
				}
				else continue;
			}
			// 숫자가 나올 때
			else if(arr[i][j] >= '0' && arr[i][j] <= '9'){
				nums[m][flag] = arr[i][j];
				flag++;
			}
			// 숫자가 끝나고 문자가 나올 때
			else if(flag){
				nums[m][flag] = '\0';
				m++;
				flag = 0;
			}	
		} while(arr[i][j] != '\0');
	}
	// 정렬
	quickSort(0, m-1);
	// 출력
	for(i=0; i<m; i++)
		printf("%s\n", nums[i]);
	return 0;
}