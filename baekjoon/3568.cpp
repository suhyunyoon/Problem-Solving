#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class ISharpCompiler{
private:
	string str;
	int strIndex;
	vector<string> idName;
	vector<vector<int> > addCnt;
	int parseID(){
		int startIndex = strIndex;
		int len = str.length();
		for(; strIndex<len; strIndex++)
			if(!((str[strIndex] >= 'A' && str[strIndex] <= 'Z') 
			  || (str[strIndex] >= 'a' && str[strIndex] <= 'z')))
				break;
		idName.push_back(str.substr(startIndex, strIndex - startIndex));
		if(str[strIndex] == ' ') {
			addCnt.push_back(vector<int>());
			return 2;
		}
		return 1;
	}
	int parseVarAddOn(){
		vector<int> temp;
		int len = str.length();
		for(; strIndex<len; strIndex++){
			if(str[strIndex] == '[')continue;
			else if(str[strIndex] == ']' && str[strIndex-1] =='[')
				temp.push_back(0);
			else if(str[strIndex] == '&')
				temp.push_back(1);
			else if(str[strIndex] == '*')
				temp.push_back(2);
			else break;
		}
		if(idName.size() == 1) addCnt.push_back(vector<int>(temp));
		else {
			reverse(temp.begin(), temp.end());
			addCnt.push_back(vector<int>(temp));
		}
		return 2;
	}
	int parseInterVar(){
		int len = str.length();
		// ' ', ';'인지 ", "인지
		if(idName.size() == 1){
			for(; strIndex<len; strIndex++)
				if(str[strIndex] != ' ')break;
		}
		else{
			for(; strIndex<len; strIndex++){
				if(str[strIndex] == ';') return 3;	
				else if(str[strIndex] != ',' && str[strIndex] != ' ')
						break;
			}
		}
		return 0;
	}
	int printVarDecl(){
		int len = idName.size();
		for(vector<string>::size_type i=1; i<len; i++){
			cout<<idName[0];
			for(vector<int>::size_type j=0; j<addCnt[0].size(); j++){
				switch(addCnt[0][j]){
					case 0:
						cout<<"[]";
						break;
					case 1:
						cout<<"&";
						break;
					case 2:
						cout<<"*";
						break;
				}
			}
			for(vector<int>::size_type j=0; j<addCnt[i].size(); j++){
				switch(addCnt[i][j]){
					case 0:
						cout<<"[]";
						break;
					case 1:
						cout<<"&";
						break;
					case 2:
						cout<<"*";
						break;
				}
			}
			cout<<' '<<idName[i]<<';'<<endl;
		}
		return 0;
	}
public:
	ISharpCompiler(string str){
		this->str = str;
		strIndex = 0;
	}
	int iParse(){
		int flag = 0;
		// Parse
		while(1){
			if(flag == 0)
				flag = parseID();
			else if(flag == 1)
				flag = parseVarAddOn();
			else if(flag == 2)
				flag = parseInterVar();
			else break;
		}
		// Output
		printVarDecl();
		return 0;
	}
};

int main(){
	string temp;
	getline(cin, temp);
	ISharpCompiler iComp(temp);
	iComp.iParse();
	return 0;
}