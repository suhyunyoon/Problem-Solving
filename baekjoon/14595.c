#include<stdio.h>
/*int main(){
	char wall[1000000] = {0,};
	int N, M, i, j;
	int x, y, sum = 1;
	scanf("%d %d", &N, &M);
	for(i=0; i<M; i++){
		scanf("%d %d", &x, &y);
		for(j=x-1; j<=y-2; j++)
			wall[j] = 1;
	}
	for(i=0; i<N-1; i++){
		//printf("%d ", wall[i]);
		if(wall[i] == 0) sum++;
	}
	printf("%d\n",sum);
	return 0;
}*/
int main(){
	char wall[1000000] = {0,};
	int xArr[5000], yArr[5000];
	int N, M, i, j;
	int sum = 1;
	// Input
	scanf("%d %d", &N, &M);
	for(i=0; i<M; i++)
		scanf("%d %d", &xArr[i], &yArr[i]);
	// Merge duplicated orders
	for(i=0; i<M; i++){
		for(j=0; j<i; j++){
			if(i==j)continue;
			
			if(xArr[i] < xArr[j]){
				// 1
				if(yArr[i] < xArr[j]) continue;
				// 2
				else if(yArr[i] < yArr[j]){
					yArr[i] = yArr[j];
					xArr[j] = 0; yArr[j] = 0;
				}
				// 3
				else{
					xArr[j] = 0; yArr[j] = 0;
				}
			} else{
				// 4
				if(xArr[i] > yArr[j]) continue;
				// 5
				else if(yArr[i] < yArr[j]){
					xArr[i] = xArr[j];
					yArr[i] = yArr[j];
					xArr[j] = 0; yArr[j] = 0;
				}
				// 6
				else{
					xArr[i] = xArr[j];
					xArr[j] = 0; yArr[j] = 0;
				}
			}
		}
	}
	// Break the Wall
	for(i=0; i<M; i++){
		// Invalid case
		if(!xArr[i] || !yArr[i]) continue;
		for(j=xArr[i]-1; j<=yArr[i]-2; j++)
			wall[j] = 1;
	}
	// Calc Answer
	for(i=0; i<N-1; i++){
		if(wall[i] == 0) sum++;
	}
	printf("%d\n",sum);
	return 0;
}