#include<stdio.h>

typedef struct{
	int country;
	int num;
	int score;
}Std;

Std std[100];
int cnt[101] = {0,};
int n;

// 두 구조체의 변수들을 바꿔줌
void swap(int a, int b){
	Std temp = {std[a].country, std[a].num, std[a].score};
	std[a].country = std[b].country;
	std[a].num = std[b].num;
	std[a].score = std[b].score;
	std[b].country = temp.country;
	std[b].num = temp.num;
	std[b].score = temp.score;
} 

// 내림차순 버블정렬
void bubbleSort(){
	int i, j;
	for(i=n-1; i>0; i--){
		for(j=0; j<i; j++){
			if(std[j].score < std[j+1].score)
				swap(j,j+1);
		}
	}
}

int main(){
	Std a = {1,1,100};
	int i, rank = 0;
	// 입력
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d %d %d", &std[i].country, &std[i].num, &std[i].score);
	// 정렬
	bubbleSort();
	// 큰 순서대로 나라 2번이상 나오지 않았는지 체크
	for(i=0; i<n; i++){
		if(rank >= 3) break;
		else if(cnt[std[i].country] < 2){
			printf("%d %d\n", std[i].country, std[i].num);
			cnt[std[i].country]++;
			rank++;
		}
	}
	return 0;
}