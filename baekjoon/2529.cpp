#include<iostream>
#include<vector>
using namespace std;

int n;
char arr[10];
long long maxN = 0, minN = 10000000000;

void f(vector<int> numbers, int num){
    // end
    if(num >= n+1){
        long long temp = 0;
        for(int i=0; i<num; i++){
            temp *= 10;
            temp += numbers[i];
        }
        if(maxN < temp) maxN = temp;
        if(minN > temp) minN = temp;
        return;
    }
    // next
    bool flag, flag2;
    for(int i=0; i<=9; i++){
        flag = true;
        for(int j=0; j<num; j++){
            if(numbers[j] == i){
                flag = false;
                break;
            }
        }
        if(flag){
            flag2 = true;
            // inequality validation
            if(arr[num-1] == '<'){
                if(numbers[num-1] >= i)
                    flag2 = false;
            }
            else if(arr[num-1] == '>'){
                if(numbers[num-1] <= i)
                    flag2 = false;
            }
            if(flag2){
                numbers.push_back(i);
                f(numbers, num+1);
                numbers.pop_back();
            }
        }
    }
}

void printNum(long long num, int k){
    if(k <= 0) return;
    printNum(num/10, k-1);
    cout<<num%10;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<=9; i++)
        f(vector<int>(1, i), 1);
    printNum(maxN, n+1); cout<<'\n';
    printNum(minN, n+1); cout<<'\n';
    return 0;
}