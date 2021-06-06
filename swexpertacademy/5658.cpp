#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

#include<cstdio>
using namespace std;

int n;
string num;

int hex2dec(int it, int b){
	int ret = 0;
	int nq = n/4;
	for(int i=it+b; i<it+b+nq; i++){
		ret *= 16;
		ret += num[i%n] >= 'A' ? num[i%n] - 'A' + 10 : num[i%n] - '0';
	}
	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, k, temp;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		map<int, bool> checked;
		vector<int> vec;
		cin>>n>>k;
		cin>>num;
		
		for(int i=0; i<n/4; i++){
			for(int j=0; j<4; j++){
				temp = hex2dec(i, j*n/4);
				//printf("%x ", temp);
				if(!checked[temp]){
					checked[temp] = true;
					vec.push_back(temp);
				}
			}
		}
		
		sort(vec.begin(), vec.end());
		
		for(int i=0; i<vec.size(); i++){
			//cout<<vec[i]<<' ';
			//printf("%x ", vec[i]);
		}
		//cout<<endl;
		
		
		cout<<"#"<<test_case<<" "<<vec[vec.size()-k]<<'\n';
	}
	return 0;
}