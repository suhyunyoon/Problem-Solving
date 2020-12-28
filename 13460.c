#include<stdio.h>

int tilt(int,int,int,int,int,char[10][10]);
int printBoard(int, int,char[10][10]);


int main(){
	char board[10][10];
	int N, M, i, j, minTilt, temp;
	// input
	scanf("%d %d", &N, &M);
	for(i=0; i<N; i++){
		scanf("%s", board[i]);
		board[i][M] = '\0';
	}
	// calc
	//printBoard(N,M, board);
	minTilt = tilt(0,0,0,N,M,board);
	printf("%d\n", minTilt);
	return 0;
}

int tilt(int depth, int di, int dj, int N, int M, char board[10][10]){
	char newBoard[10][10];
	int i,j,index,tempTilt,minTilt = -1;
	int ri=1, rj=1, bi=1, bj=1, ri_init=1, rj_init=1, bi_init=1, bj_init=1;
	int flagR, flagB;
	//printBoard(N,M,board);
	
	if(depth > 10)
		return -1;
	
	// copy new board
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			if(board[i][j] == 'R'){
				ri = i; rj = j;
				ri_init = i; rj_init = j;
			}else if(board[i][j] == 'B'){
				bi = i; bj = j;
				bi_init = i; bj_init = j;
			}
			newBoard[i][j] = board[i][j];
		}
		newBoard[i][j] = '\0';
	}
	//printBoard(N,M,newBoard);
	
	// run except initial
	if(di || dj){
		// move Red Ball
		if(newBoard[ri+di][rj+dj] == '#') flagR = 0;
		else flagR = 1;
		while(flagR){
			ri += di; rj += dj;
			if(newBoard[ri+di][rj+dj] == '#' || newBoard[ri][rj] == 'O')break;
		}
		// move Black Ball
		if(newBoard[bi+di][bj+dj] == '#') flagB = 0;
		else flagB = 1;
		while(flagB){
			bi += di; bj += dj;
			if(newBoard[bi+di][bj+dj] == '#' || newBoard[bi][bj] == 'O')break;
		}
		// when two balls cannot move
		if(!(flagR || flagB)) return -1;
		// when Blue Ball enters into the hole
		else if(newBoard[bi][bj] == 'O') return -1;
		// when Red Ball enters into the hole
		else if(newBoard[ri][rj] == 'O') return depth;
		// when two balls overlap
		else if(ri == bi && rj == bj){
			if((ri_init - bi_init) * di > 0) bi -= di;
			else ri -= di;
			if((rj_init - bj_init) * dj > 0) bj -= dj;
			else rj -= dj;
			// when two balls cannot move
			if(ri == ri_init && rj == rj_init && bi == bi_init && bj == bj_init) return -1;
		}
		newBoard[ri_init][rj_init] = '.';
		newBoard[bi_init][bj_init] = '.';
		newBoard[ri][rj] = 'R';
		newBoard[bi][bj] = 'B';
	}
	// tilt four directions
	tempTilt = tilt(depth+1,1,0,N,M,newBoard);
	minTilt = (tempTilt > 0) && (tempTilt < minTilt || minTilt == -1) ? tempTilt : minTilt;
	tempTilt = tilt(depth+1,0,1,N,M,newBoard);
	minTilt = (tempTilt > 0) && (tempTilt < minTilt || minTilt == -1) ? tempTilt : minTilt;
	tempTilt = tilt(depth+1,-1,0,N,M,newBoard);
	minTilt = (tempTilt > 0) && (tempTilt < minTilt || minTilt == -1) ? tempTilt : minTilt;
	tempTilt = tilt(depth+1,0,-1,N,M,newBoard);
	minTilt = (tempTilt > 0) && (tempTilt < minTilt || minTilt == -1) ? tempTilt : minTilt;
	
	return minTilt;
}

int printBoard(int N, int M, char board[10][10]){
	int i,j;
	//for(int i=0; i<N; i++)
	//	printf("%s\n",board[i]);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
}