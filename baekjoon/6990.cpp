// 03_달팽이_정리.cpp
 
#include<cstdio>
#include<cstdlib>
#include<cmath>
 
#define N 1000
#define M 2000000
 
#define gmax( a, b) (( a) > ( b) ? ( a) : ( b))
 
int n, l;
double ans = 0;
double Check[ N + 1];
 
struct Racer{
    int vec_x, vec_y, x, y, a, b, c;
} Data[ N + 1], Bound[ 4], Left, Right, Up, Bottom;
 
struct Cross_Point{
    double d_i, d_j;
    int i, j;
} Cross[ M];
 
struct Crossing{
    double x, y;
    int check;
};
 
int sortf( const void *a, const void *b){
    // 길이가 더 긴것이 뒤쪽으로 가게 된다.
    // 즉, 오름차순 정렬이 된다. 
    double t = ( *( struct Cross_Point *)a).d_i - ( *( struct Cross_Point *)b).d_i;
    if ( t > 0) return 1;
    if ( t == 0) return 0;
    return -1;
}
 
double distance( double x1, double y1, double x2, double y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
 
int going_check( int vecX, int vecY, int x, int y, double tx, double ty){
    if ( vecX == 0)    {
        if ( ( ty - y) * vecY >= 0 && x == tx) return 1;
        else return 0;
    }
    else{
        if ( ( tx - x) * vecX >= 0 && (ty - y) * vecY >= 0) return 1;
        else return 0;
    }
}
 
struct Crossing get_co( Racer A, Racer B){
    Crossing tmp;
    if ( A.a*B.b - B.a*A.b == 0){ // 평행한 경우 
        if ( A.c*B.a == B.c*A.a && A.c*B.b == B.c*A.b){  // 선이 겹치는 경우 
            if ( going_check( A.vec_x, A.vec_y, A.x, A.y, B.x, B.y) == 1){  // A가 B쪽으로 간다. 
                if ( going_check( B.vec_x, B.vec_y, B.x, B.y, A.x, A.y) == 1){ // B가 A쪽으로 간다. 
                    // 두 점이 서로를 향해서 가고있다면,
                    // 중간에서 만나게 된다. 
                    tmp.y = ( A.y + B.y) / (double)2;
                    tmp.x = ( A.x + B.x) / (double)2;
                }
                else{  // A는 결국 B의 시작점에서 만나게 된다. 
                    tmp.y = B.y;
                    tmp.x = B.x;
                }
                tmp.check = 1;
            }
            else{ // A는 딴방향으로 가고 있고, 
                if ( going_check( B.vec_x, B.vec_y, B.x, B.y, A.x, A.y) == 1){  // B는 A방향으로 가고 있다.
                                                                                // 결국, A의 시작점에서 만나고 있다. 
                    tmp.y = A.y;
                    tmp.x = A.x;
                    tmp.check = 1;
                }
                else{
                    tmp.check = 0;
                }
            }
        }
        else{ // 선이 겹치지 않는 경우 , 답이 없다. 
            tmp.check = 0;
        }
    }
    else{
        // 기울기가 다르다면 무조건 만나게 되어있다. 
        tmp.y = ( (double)A.c*B.a-(double)B.c*A.a) / ((double)A.b*B.a - (double)B.b*A.a);
        tmp.x = ( (double)A.c*B.b-(double)B.c*A.b) / ((double)A.a*B.b - (double)B.a*A.b);
        tmp.check = 1;
    }
    return tmp;
}
 
 
void prs( void){
    int i, j, cnt = 0;
    double x, y;
    Cross_Point tmp;
    Crossing crossing;
    
    // 격자에서 방정식을 뽑아냈다. 
    Left.a = 1;         Left.b = 0;         Left.c = 0;         Left.x = 0;         Left.y = 0;    // x=0 (0,0)에서 시작 
    Right.a = 1;        Right.b = 0;        Right.c = l;        Right.x = l;        Right.y = 0;   // x=l (l,0)에서 시작 
    Up.a = 0;           Up.b = 1;           Up.c = l;           Up.x = 0;           Up.y = l;      // y=l (0,l)에서 시작 
    Bottom.a = 0;       Bottom.b = 1;       Bottom.c = 0;       Bottom.x = 0;       Bottom.y = 0;  // y=0 (0,0)에서 시작  
    
    // 왼쪽,오른쪽,위,아래를 배열로 저장한 것 뿐이다. 
    Bound[ 0] = Left;   Bound[ 1] = Right;  Bound[ 2] = Up;     Bound[ 3] = Bottom;
    
    printf(" i선분 j선분  i-->교점 거리  j-->교점 거리\n"); 
    for ( i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            // i라는 직선과 j라는 직선과의 교점을 구해낸다. 
            if ( i != j){
                // 교점의 좌표를 구해낸다. 
                crossing = get_co( Data[ i], Data[ j]);
                tmp.i = i;
                tmp.j = j;
                
                // 교점이 격자범위 밖에 있으면 무시한다. 
                if ( crossing.x < 0 || crossing.x > l || crossing.y < 0 || crossing.y > l) continue;
                
                // 만나게 되는 경우 
                if ( crossing.check == 1){
                    // i번째선분이 교점을 향해 움직이고 있다면  
                    if ( going_check( Data[i].vec_x, Data[i].vec_y, Data[i].x, Data[i].y, crossing.x, crossing.y) == 1){
                        // j번째 선분이 교점을 향해 움직이고 있다면 
                        if ( going_check( Data[j].vec_x, Data[j].vec_y, Data[j].x, Data[j].y, crossing.x, crossing.y) == 1){
                            // 교점에서 i의 시작점까지의 거리와 
                            tmp.d_i = distance(crossing.x, crossing.y, Data[i].x, Data[i].y);
                            
                            // 교점에서 j의 시작점까지의 거리를 구한다. 
                            tmp.d_j = distance(crossing.x, crossing.y, Data[j].x, Data[j].y);
                            
                            // 교점에서 i쪽까지 거리가 더 클때만 저장해 놓는다.
                            // 그래야 , i선분이 j선분에 도달하게 된다. 
                            // 자세히 보면 j쪾까지의 거리도 같이 저장해 놓고 있다. 
                            if ( tmp.d_i >= tmp.d_j) {
                                Cross[cnt] = tmp;
                                printf("  %3d   %3d %12.2f %12.2f\n", Cross[cnt].i,Cross[cnt].j, Cross[cnt].d_i, Cross[cnt].d_j);
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        tmp.i = i;
        tmp.j = n;  // 이거는 나머지 격자선분과 교점이 생길수 있는 거를 감안하는 코드이다. 
                    // 알기쉽게 외곽선은 9번이라고 한다. 
        for ( j = 0; j < 4; j++){
            // 교점을 구해서 범위안에 있는지 확인한다. 
            crossing = get_co( Data[ i], Bound[ j]);
            if ( crossing.x < 0 || crossing.x > l || crossing.y < 0 || crossing.y > l)
                continue;
            if ( crossing.check == 1){
                // i번째 선분이 교점쪽으로 이동하고 있다면... 
                if ( going_check(Data[ i].vec_x, Data[ i].vec_y, Data[ i].x, Data[ i].y, crossing.x, crossing.y) == 1){
                    // 교점은 외곽선에서만 생긴다.
                    // 따라서, j쪽 길이는 0이 될수 밖에 없다. 
                    tmp.d_i = distance( crossing.x, crossing.y, Data[ i].x, Data[i].y);
                    tmp.d_j = 0;
                             // 외곽선에서부터의 거리는 0으로 한다. 
                    Cross[ cnt] = tmp;
                    printf("  %3d   %3d %12.2f %12.2f\n", Cross[cnt].i,Cross[cnt].j, Cross[cnt].d_i, Cross[cnt].d_j);
                    cnt++;
                }
            }
        }
    }
    qsort( Cross,   cnt,              sizeof(Cross[ 0]), sortf);
    //     배열   정렬할 원소 갯수    원소한개 크기      정렬함수
     
    printf("cnt=%d\n", cnt);
    printf(" i선분 j선분  i-->교점 거리  j-->교점 거리\n"); 
    for ( i = 0; i < cnt; i++){
        printf("  %3d   %3d %12.2f %12.2f\n", Cross[i].i,Cross[i].j, Cross[i].d_i, Cross[i].d_j);
    }
     
    for ( i = 0; i <= n; i++) Check[ i] = -1;
    
    printf("\n");
    for ( i = 0; i < cnt; i++){
        // 이게 오름차순으로 설정한 이유가 있구나.
        // Check[i]번째에는 이동시간이 들어가는데.. 
        // 이미 정렬된 결과에서 작은게 다른 선분이랑 먼저만나서 멈춘거이기 때문에 
        // 아래 첫번째 조건이 이를 의미하게 된다.
        // 아직 계산이 안된 빈 요소이어야지만 i번째 시간이 저장될 가능성이라도 있다.+ 
 
        if ( Check[ Cross[ i].i] == -1 && 
             (Check[ Cross[ i].j] == -1 || Check[ Cross[ i].j] >= Cross[ i].d_j)
           ){
        //    i선분에서 교점까지 시간-아직없다면 
        //                                 j선분에서 교점까지 시간-아직없다면
        //                                                            또는
        //                                                               이미 기록되어 있는 j선분에서 교점까지 시간>=   
        //                                                                                       j선분에서 교점까지 시간
        //  아하..                                                              더 짧은 시간이 있다라는 의미이므로
        //                                                                      그 값을 기록해줘야 한다. 
        // 길이가 짧은 녀석이 먼저 지나갔다..
        // 따라서 나는 멈춰야 한다.
        // 마지막 조건이 j에서 i선분쪽으로의 교점시간인데..그게 더 짧으므로..
        // 나는 멈춰서야 한다는 의미이다. 
            Check[ Cross[ i].i] = Cross[ i].d_i;            
            
            ans = gmax( ans, Cross[ i].d_i); // 거리가 곧, 시간이구나... 
            printf("i=%2d, Check[%d]=%f, ans=%f (%f)\n",i, Cross[i].i,   Check[ Cross[ i].i], ans, sqrt(ans));
        }
    }
}
 
 
int main( void){
    //freopen ( "03_달팽이.TXT", "r", stdin);
    int i, tmpx, tmpy;
    
    // n: 달팽이수,  l: 울타리 한변의 길이 
    scanf("%d %d", &n, &l);
    
    for( i = 0; i < n; i++){
        scanf("%d %d %d %d", &Data[ i].x, &Data[ i].y, &tmpx, &tmpy);
        //                   |______________________|  |___________|
        //                         시작좌표               목적지 좌표(방향을 위해 쓴다.) 
         
        Data[ i].vec_y = tmpy - Data[ i].y; // y증가량 
        Data[ i].vec_x = tmpx - Data[ i].x; // x증가량 
        
        // 아래는 ax+by=c 으로 나타냈을 때의 결과이다. 
        Data[ i].a = Data[i].vec_y;
        Data[ i].b = -Data[ i].vec_x;
        Data[ i].c = Data[ i].vec_y * Data[ i].x - Data[ i].vec_x * Data[ i].y;
    }    
    
    prs();
    printf("%.2lf\n", sqrt(ans));
    return 0;
}
