#include<stdio.h>

int pattern[4][1024+1];
int a[101][101];

int n;
int main(){
	scanf("%d",&n);
	
	pattern[0][0] = 0;
	pattern[1][0] = 1;
	pattern[2][0] = 2;
	pattern[3][0] = 3;
	
	int start=0, end=1, temp;
	for(int k=0;k<4; k++){
		temp=1;
		for(int i=1; i<=10; i++){
			start=temp<<(i-1);
			end=temp<<i;
			
			for(int j=start, q=1;j<end;j++, q+=2){
				pattern[k][j]=(pattern[k][j-q]+1)%4;
			}
		}
	}
	for(int i=0; i<n; i++){
		int x,y,dir,gen;
		scanf("%d %d %d %d",&x, &y, &dir,&gen);
		int end=1<<gen;
		
		a[y][x]=1;
		for(int j=0; j<end; j++){
			if(pattern[dir][j]==0) x+=1;
			if(pattern[dir][j]==1) y-=1;
			if(pattern[dir][j]==2) x-=1;
			if(pattern[dir][j]==3) y+=1;
			a[y][x] = 1;
		}
	}
	int ans=0;
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1])
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}