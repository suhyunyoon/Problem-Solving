// 1296_데이트.c

#include<stdio.h>
#include<string.h>

char minsik[21];
char ladies[50][21];
int L=0,O=0,V=0,E=0;

int loveCalc(int index){
	int i, ret, len;
	// 오민식의 LOVE갯수와 여자의 LOVE갯수를 합쳐서 계산
	int l=L, o=O, v=V, e=E;
	len = strlen(ladies[index]);
	for(i=0; i<len; i++){
		if(ladies[index][i] == 'L') l++;
		else if(ladies[index][i] == 'O') o++;
		else if(ladies[index][i] == 'V') v++;
		else if(ladies[index][i] == 'E') e++;
	}
	ret = ((l+o)*(l+v)*(l+e)*(o+v)*(o+e)*(v+e))%100;
	return ret;
}

int main(){
	int i, n, temp, len, maxindex = 0, max = 0;
	// 입력
	scanf("%s", minsik);
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s", ladies[i]);
	}
	// 오민식 이름에서 카운트
	len = strlen(minsik);
	for(i=0; i<len; i++){
		if(minsik[i] == 'L') L++;
		else if(minsik[i] == 'O') O++;
		else if(minsik[i] == 'V') V++;
		else if(minsik[i] == 'E') E++;
	}
	// 여자들 이름하고 같이 계산 후 최댓값 저장
	for(i=0; i<n; i++){
		temp = loveCalc(i);
		if(temp > max){
			max = temp;
			maxindex = i;
		}
		// 같으면 이름 알파벳 순으로 비교
		else if(temp == max && strcmp(ladies[i], ladies[maxindex]) < 0){
			max = temp;
			maxindex = i;
		}
	}
	//printf("%d\n", n);
	printf("%s\n", ladies[maxindex]);
}