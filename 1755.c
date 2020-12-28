// 1755_숫자놀이.c

#include<stdio.h>
#include<string.h>

int m, n;
int numindex[100];
char numbers[100][12];

// index만 교환하는 형식
void bubbleSort(){
	int i, j, temp;
	for(i=n-m; i>=0; i--){
		for(int j=0; j<i; j++){
			if(strcmp(numbers[numindex[j]], numbers[numindex[j+1]]) > 0){
				temp = numindex[j];
				numindex[j] = numindex[j+1];
				numindex[j+1] = temp;
			}
		}
	}
}

int main(){
	int i, j, temp;
	char num[10][6] = {"zero", "one", "two", 
					   "three", "four", "five", 
					   "six", "seven", "eight", "nine"};
	// 입력 후 배열에 숫자 영문명 저장
	scanf("%d %d", &m, &n);
	for(i=m; i<=n; i++){
		// index 저장
		numindex[i-m] = i-m;
		// 10의자리수 있을 때만
		if(i >= 10){
			strcat(numbers[i-m], num[i/10]);
			strcat(numbers[i-m], " ");
		}
		strcat(numbers[i-m], num[i%10]);
	}
	// 정렬
	bubbleSort();
	// 1줄에 10개씩 출력
	for(i=0; i<((n-m)/10)+1; i++){
		for(j=i*10; j<(i+1)*10 && j<=n-m; j++){
			printf("%d ", numindex[j]+m);
		}
		printf("\n");
	}
}