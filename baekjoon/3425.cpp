#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define NUM_LIMIT 1000000000

class GOSTACK{
private:
	vector<long long> gostack;
	vector< pair<int, long long> > cmds;
	int calcCase(long long data){
		long long ret, temp;
		int len = cmds.size();
		// Init
		gostack.push_back(data);
		for(vector< pair<int, long long> >::size_type i = 0; i<len; i++){
			switch(cmds[i].first){
				case 0: // NUM
					gostack.push_back(cmds[i].second);
					break;
				case 1: // POP
					if(gostack.size() < 1) throw -333;
					gostack.pop_back();
					break;
				case 2: // INV
					if(gostack.size() < 1) throw -333;
					gostack.back() *= -1;
					break;
				case 3: // DUP
					if(gostack.size() < 1) throw -333;
					gostack.push_back(gostack.back());
					break;
				case 4: // SWP
					if(gostack.size() < 2) throw -333;
					temp = gostack.back();
					gostack.back() = gostack[gostack.size()-2];
					gostack[gostack.size()-2] = temp;
					break;
				case 5: // ADD
					if(gostack.size() < 2) throw -333;
					gostack[gostack.size()-2] += gostack.back();
					gostack.pop_back();
					if(gostack.back() > NUM_LIMIT || gostack.back() < -1 * NUM_LIMIT) throw -222;
					break;
				case 6: // SUB
					if(gostack.size() < 2) throw -333;
					gostack[gostack.size()-2] -= gostack.back();
					gostack.pop_back();
					if(gostack.back() > NUM_LIMIT || gostack.back() < -1 * NUM_LIMIT) throw -222;
					break;
				case 7: // MUL
					if(gostack.size() < 2) throw -333;
					gostack[gostack.size()-2] *= gostack.back();
					gostack.pop_back();
					if(gostack.back() > NUM_LIMIT || gostack.back() < -1 * NUM_LIMIT) throw -222;
					break;
				case 8: // DIV
					if(gostack.size() < 2) throw -333;
					if(gostack.back() == 0) throw -111;
					gostack[gostack.size()-2] /= gostack.back();
					gostack.pop_back();
					break;
				case 9: // MOD
					if(gostack.size() < 2) throw -333;
					if(gostack.back() == 0) throw -111;
					gostack[gostack.size()-2] %= gostack.back();
					gostack.pop_back();
					break;
				default:
					break;
			}
		}
		if(gostack.size() != 1) throw -444;
		return gostack.front();
	}
public:
	GOSTACK(){}
	int inputCmd(){
		string cmd = "";
		long long param = 0;
		while(cmd != "END"){
			cin >> cmd;
			if(cmd == "NUM"){
				cin >> param;
				cmds.push_back(make_pair(0, param));
			}
			else if(cmd == "POP")
				cmds.push_back(make_pair(1, 0));
			else if(cmd == "INV")
				cmds.push_back(make_pair(2, 0));
			else if(cmd == "DUP")
				cmds.push_back(make_pair(3, 0));
			else if(cmd == "SWP")
				cmds.push_back(make_pair(4, 0));
			else if(cmd == "ADD")
				cmds.push_back(make_pair(5, 0));
			else if(cmd == "SUB")
				cmds.push_back(make_pair(6, 0));
			else if(cmd == "MUL")
				cmds.push_back(make_pair(7, 0));
			else if(cmd == "DIV")
				cmds.push_back(make_pair(8, 0));
			else if(cmd == "MOD")
				cmds.push_back(make_pair(9, 0));
			else if(cmd == "QUIT")
				return 0;
		}
		//cout << cmds.size() << endl;
		return 1;
	}
	int calcAllCases(){
		int N;
		long long data, result;
		cin >> N;
		for(int i=0; i<N; i++){
			cin >> data;
			try{
				result = calcCase(data);
				cout << result << endl;
			} catch (int err){
				// -111: divide by 0
				// -222: |Value| > 10^9
				// -333: Less stack size for calc
				// -444: stack size is not 1 when it ends
				cout << "ERROR" << endl;
			}
			gostack.clear();
		}
		cout << endl;
		cmds.clear();
		return 0;
	}
};

int main(){
	GOSTACK gostack;
	string temp;
	while(gostack.inputCmd()){
		gostack.calcAllCases();
		getline(cin, temp);
	}
	return 0;
}