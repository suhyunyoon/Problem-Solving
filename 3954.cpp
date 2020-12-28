#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;


int main(){
	int T;
	cin>>T;
	for(int t=0; t<T; t++){
		int i, sm, sc, si, ptr = 0, sptr = 0, cnt = 0;
		string str, input;
		cin>>sm>>sc>>si;
		cin>>str>>input;
		vector<unsigned char> arr(sm, 0);
		map<int, int> bIndex, bCnt;
		
		// 괄호처리
		vector<int> cStack;
		for(int i=0; i<sc; i++){
			if(str[i] == '['){
				cStack.push_back(i);
				bIndex[i] = 0; bCnt[i] = 0;
			}
			else if(str[i] == ']'){
				bIndex[i] = cStack.back();
				bIndex[cStack.back()] = i;
				cStack.pop_back();
			}
		}
		i = 0;
		while(i < sc && cnt < 50000000){
			if(str[i] == '-') arr[ptr]--;
			else if(str[i] == '+') arr[ptr]++;
			else if(str[i] == '<') ptr = (ptr+sm-1) % sm;
			else if(str[i] == '>') ptr = (ptr+1) % sm;
			else if(str[i] == '['){
				if(!arr[ptr]){
					i = bIndex[i];
					bCnt[i] = 0;
				}
				else bCnt[i]++;
			}
			else if(str[i] == ']'){
				if(arr[ptr]){
					i = bIndex[i];
					bCnt[i]++;
				}
				else bCnt[bIndex[i]] = 0;
			}
			else if(str[i] == ','){
				if(sptr >= si) arr[ptr] = 255;
				else {
					arr[ptr] = (unsigned char)input[sptr];
					sptr++;
				}
			}
			i++; cnt++;
		}
		if(cnt < 50000000) cout<<"Terminates\n";
		else{
			int max = 0;
			for(int i=0; i<sc; i++)
				if(bCnt[i] > bCnt[max]) max = i;
			cout<<"Loops "<<max<<' '<<bIndex[max]<<'\n';
		}
	}
	return 0;
}