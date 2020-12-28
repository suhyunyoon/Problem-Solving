//02_채점2.cpp 
 
#include <iostream>
#include <vector>
using namespace std;
 
// 메모리초과 문제, 겨우 값을 맞춰서 정답처리했음. 
#define N 800000

vector<vector<bool>> d;

// 이번에는 벡터를 참조로 받았다. 
// 편하게 쓰고 싶을 때, 어떤거라도 사용하면 된다. 
int getFirstImpossible(const vector<int> &score, int value, int sum){
    int no = score.size();
    vector<int> sum_score;
    vector<int> max_score;
    
	d = vector<vector<bool>>(no, vector<bool>(sum+1,0));
	
    sum_score.push_back(score[0]);
    max_score.push_back(sum_score[0]);
    
    int index=0;
	
    for (int index = 1; index < no; index++){
        sum_score.push_back(score[index] + sum_score[index - 1]);
        max_score.push_back(sum_score[index] + max_score[index -1]);
    }
    // k 값이 마지막 max_score보다 크다면 답이 없어서, 그냥 k를 출력하게 한다. 
    if (value > max_score[no - 1]){
        return value;
    }
	
    d[0][0]=1;         // 첫번째 문제를 틀리면 0점이 나오므로, 이것도 가틍하다. 
    d[0][max_score[0]]=1;  // 맞으면 이 점수가 가능하다고 설정
     
    for (int i = 1; i < no; i++){
        
        // 모두 다 맞는 경우 
        d[i][max_score[i]]=1; 
        
        // k번째가 틀리는 경우, 
        // (k가 0 에 도달하는 경우는 따로 계산한다.) 
        for (int k = i; k >= 0; k--){
            int sum=0; 
            int max=0;
            for(int l=k+1;l<=i;l++){// k번째 이후의 합을 계산 
                sum+=score[l];
                max+=sum;
            }
            
            //k가 0이고, 즉 0번째가 틀린경우    
            if(k==0){
                d[i][max]=1;
                //d[i][score[i]+sum]=1; // 이거 한줄이 실수 
                break;
            }
            
            for(int j=max;j<=max_score[k-1]+max;j++){ 
                d[i][j] = d[i][j] | d[k-1][j-max];
            }
        }
 
    }
    for (int i = value; i <= max_score[no - 1] + 1; i++){
		// max_score 는 나올수 있으므로 +1해줘서 안되는 수 출력한다.        
        if (d[no - 1][i] == 0) 
            return i;
    }
    // 여기 도달하면 프로그램 오류이다. 
    return -1;
}
 
int main(void ){
    freopen("02_채점a.txt","r",stdin);
    vector<int> score;
    int k, n, sum = 0;    
    cin >> n;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
		sum += sum+num;
        score.push_back(num);
    }
    cin >> k;
 	while(getFirstImpossible(score, k, sum)){k++;}
	cout<<k<<'\n';
    return 0;
}
 