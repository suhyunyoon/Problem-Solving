#include<stdio.h>
#include<string.h>

char dict[1000][21];

int cmp(int a, int b){
	int alen, blen, i=0;
	char aupper, bupper;
	alen = strlen(dict[a]); blen = strlen(dict[b]);
	// index 0부터 순차적으로 비교
	while(i<alen && i<blen){
		// 대문자로 변환
		aupper = dict[a][i]; bupper = dict[b][i];
		aupper += (aupper >= 'a' && aupper <= 'z' ? ('A' - 'a') : 0);
		bupper += (bupper >= 'a' && bupper <= 'z' ? ('A' - 'a') : 0);
		if(aupper != bupper)
			return aupper > bupper ? 1 : -1;
		i++;
	}
	// 길이가 같지 않다면 긴 쪽이 더 큼
	if(alen == blen) return 0;
	else return alen > blen ? 1 : -1;
	return 0;
}

int main(){
	int n,i,min;
	while(1){
		min = 0;
		scanf("%d", &n);	
		if(!n) break;
		// 입력받으면서 사전순으로 제일 앞에 있는 단어 index 저장
		for(i=0; i<n; i++){
			scanf("%s", dict[i]);
			if(cmp(i, min) == -1)min = i;
		}
		printf("%s\n", dict[min]);
	}
	return 0;
}