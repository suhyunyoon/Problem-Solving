// 1431_시리얼_번호.c

#include<stdio.h>
#include<string.h>

int n;
char guitar[1000][51];

// 두 문자열 교체
void swap(char a[51], char b[51]){
	char temp[51];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

// 길이 먼저 비교, 그다음 strcmp
int sstrcmp(char a[51], char b[51]){
	int i, alen, blen, asum = 0, bsum = 0;
	alen = strlen(a); blen = strlen(b);
	// 길이 같음
	if(alen == blen){
		// 자릿수 합 더함
		for(i=0; i<alen; i++)
			if(a[i] >= '0' && a[i] <= '9') asum += a[i] - '0';
		for(i=0; i<blen; i++)
			if(b[i] >= '0' && b[i] <= '9') bsum += b[i] - '0';
		// 자릿수 합도 같음
		if(asum == bsum){
			// 3번째는 ASCII 코드 상 숫자가 알파벳 대문자보다 작으므로 strcmp 그대로 사용가능
			// a가 나중이면 양수, b가 나중이면 음수 return
			return strcmp(a,b);
		}
		else return asum > bsum ? 1 : -1;
	}
	else return alen > blen ? 1 : -1;
}

// 시리얼 넘버 갯수가 총 1000개이므로 O(n^2)인 정렬알고리즘 모두 사용 가능
void bubbleSort(){
	int i,j;
	for(i=n-1; i>0; i--){
		for(j=0; j<i; j++){
			// j가 j+1번째 문자열보다 순서상 나중이면 교체
			if(sstrcmp(guitar[j], guitar[j+1]) > 0)
				swap(guitar[j], guitar[j+1]);
		}
	}
}

int main(){
	int i;
	// 입력
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", guitar[i]);
	}
	// 정렬
	bubbleSort();
	// 출력
	for(i=0; i<n; i++){
		printf("%s\n", guitar[i]);
	}
	return 0;
}