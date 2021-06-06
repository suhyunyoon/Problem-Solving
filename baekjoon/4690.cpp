#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findABC(int a){
	vector<vector<int>> bcd;
	vector<int> tempBCD;
	int tripleA, tripleB, tripleC;
	tripleA = a*a*a;
	for(int b = 2; b<a; b++){
		tripleB = b*b*b;
		for(int c = 2; c*c*c + tripleB < tripleA; c++){
			tripleC = c*c*c;
			for(int d = 2; d*d*d + tripleB + tripleC <= tripleA; d++)
				if(tripleA == tripleB + tripleC + d*d*d){
					tempBCD.clear();
					tempBCD.push_back(b); tempBCD.push_back(c); tempBCD.push_back(d);
					sort(tempBCD.begin(), tempBCD.end());
					// 중복체크하고 넣음
					bool flag = true;
					for(int i=0; i<bcd.size(); i++)
						if(bcd[i] == tempBCD){
							flag = false;
							break;
						}
					if(flag)
						bcd.push_back(tempBCD);
				}	
		}
	}
	for(int i=0; i<bcd.size(); i++)
		cout<<"Cube = "<<a<<", Triple = ("<<bcd[i][0]<<","<<bcd[i][1]<<","<<bcd[i][2]<<")"<<endl;
	return 0;
}

int main(){
	int mul, mul2;
	for(int a=6; a<=100; a++){
		findABC(a);
	}
	return 0;
}