#include<iostream>
#include<string>

using namespace std;

string addBigNum(string a, string b){
	string ret;
	int lenA, lenB, c = 0, sub;
	lenA = a.length(); lenB = b.length();
	sub = lenA - lenB;
	for(int i=lenB-1; i>=0; i--){
		c += (int)(a[i + sub] - '0') + (int)(b[i] - '0');
		ret = (char)((c % 10)+'0') + ret;
		c /= 10;
	}
	for(int i=sub-1; i>=0; i--){
		c += (int)(a[i] - '0');
		ret = (char)((c % 10)+'0') + ret;
		c /= 10;
	}
	if(c) ret = (char)((c % 10)+'0') + ret;
	return ret;
}

int main(){
	string a,b,sum;
	int lenA, lenB;
	cin >> a >> b;
	lenA = a.length(); lenB = b.length();
	if(lenA > lenB) sum = addBigNum(a, b);
	else if(lenA == lenB){
		for(int i=0; i<lenA; i++){
			if(a[i] > b[i]){
				sum = addBigNum(a, b);
				break;
			}
			else if(a[i] < b[i]){
				sum = addBigNum(b, a);
			}
		}
		sum = addBigNum(a, b);
	}
	else sum = addBigNum(b, a);
	
	cout << sum << endl;
	return 0;
}