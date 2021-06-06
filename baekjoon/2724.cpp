#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

string trim(string);
int markupMsg();
int parsing(queue<string> &, queue<int> &, string &);
int printMULTI(queue<string> &, queue<int> &, int, int);
int newline(vector<string>&, string&, string[4], bool[4], int, int, int&);

int main(){
	int N;
	cin>>N;
	for(int i=1; i<=N; i++){
		cout<<i<<endl;
		markupMsg();
	}
	return 0;
}

int markupMsg(){
	int R, C;
	string msg;
	queue<string> msgQueue;
	// 0~ : sc, -1: nl, -2~-5: jl2~jl5, -6: string msg
	queue<int> cmd;
	
	cin>>R>>C;
	getline(cin, msg);
	msg = trim(msg);
	
	if(parsing(msgQueue, cmd, msg) == 0)
		printMULTI(msgQueue, cmd, R, C);	
	return 0;
}

int printMULTI(queue<string> &msgQueue, queue<int> &cmd, int R, int C){
	int jl = -2, sc = 0, len;
	int currentRow = 0, currentCmd = -6;
	// 현재 줄에서 사용된 jl은 true
	bool currentJl[4] = {false, false, false, false};
	string msgline[4] = {"", "", "", ""};
	vector<string> msg;
	string temp, line = "", space = "", tempSpace;
	while(cmd.size()){
		currentCmd = cmd.front(); space = "";
		switch(currentCmd){
			// 현재 jl에 따라 문자열 입력, TOO BIG 
			case -6:
				temp = msgQueue.front();
				msgQueue.pop();
				len = temp.length();
				for(int i=0; i<sc; i++) space += " ";
				tempSpace = space;
				if(jl == -5){
					// 띄어쓰기 칸 계산은 나중에 줄바꿀때
					space = "";
				}
				msgline[-2-jl] += temp[0];
				for(int i=1; i<len; i++) msgline[-2-jl] += space + temp[i];
				space = tempSpace;
				break;
			// 줄바꿈. 현재 줄 남은 칸 채우고, 입력할 줄 남았는지 체크, 이전 줄의 값들 초기화
			case -1:
				// new line	
				if(msgline[0] != "" || msgline[1] != "" || msgline[2] != "" || msgline[3] != "" || currentRow < R)
					if(newline(msg,line,msgline,currentJl,R,C,currentRow) == -1){
						cout<<"TOO BIG"<<endl;
						return -1;
					}
				break;
			// jl5 나왔는지 검사
			case -2:
				if(currentJl[3] && msgline[3] != ""){
					cout<<"TAG CONFLICT"<<endl;
					return -1;
				}
			// 앞에 다른문자 출력되지 않았는지 검사 & 값 추가
			case -5:
				if(msgline[0] != "" || msgline[1] != "" || msgline[2] != ""){
					cout<<"TAG CONFLICT"<<endl;
					return -1;
				}
				jl = currentCmd;
				currentJl[-2-jl] = true;
				break;
			// jl4 나왔는지 검사
			case -3:
				if(currentJl[2] && msgline[2] != ""){
					cout<<"TAG CONFLICT"<<endl;
					return -1;	
				}
			// jl5 나왔는지 검사
			case -4:
				if(currentJl[3] && msgline[3] != ""){
					cout<<"TAG CONFLICT"<<endl;
					return -1;	
				}
				jl = currentCmd;
				currentJl[-2-jl] = true;
				break;
			// sc
			default:
				sc = currentCmd;
				break;
		}
		//
		cmd.pop();
	}
	// 쓰던 줄 입력
	if(msgline[0] != "" || msgline[1] != "" || msgline[2] != "" || msgline[3] != "")
		if(newline(msg,line,msgline,currentJl,R,C,currentRow) == -1){
			cout<<"TOO BIG"<<endl;
			return -1;
		}
	
	// 남은 출 채우기
	for(int i=0; i<C; i++) line += " ";
	for(; currentRow < R; currentRow++)
		msg.push_back(line);
	
	// 출력
	for(int i=0; i<msg.size(); i++)
		cout<<msg[i]<<endl;
	
	return 0;
}

int parsing(queue<string> &msgQueue, queue<int> &cmd, string &msg){
	string temp;
	int tempNum, state = 0;
	bool flag;
	int len = msg.length();
	temp = "";
	for(int i=0; i<len; i++){
		char ch = msg[i];
		switch(state){
			// 0 : 문자 입력
			case 0:
				if(ch == '['){
					state = 1;
					if(temp.length() > 0){
						if(cmd.size() > 0 && cmd.back() == -6)
							msgQueue.back() += temp;
						else{
							msgQueue.push(temp);
							cmd.push(-6);
						}
						temp = "";
					}
				}
				else if(ch == ']'){
					state = 2;
					if(temp.length() > 0){
						if(cmd.size() > 0 && cmd.back() == -6)
							msgQueue.back() += temp;
						else{
							msgQueue.push(temp);
							cmd.push(-6);
						}
						temp = "";
					}
				}
				else
					temp += ch;
				break;
			// 1 : [
			case 1:
				if(ch == '['){
					state = 0;
					temp += '[';
				}
				else if(len - i >= 3){
					string parsed = msg.substr(i,3);
					
					if(parsed == "nl]" || parsed == "NL]" 
					   || parsed == "Nl]" || parsed == "nL]"){
						cmd.push(-1);
						i += 2;
						state = 0;
						break;
					} 
					else if(len - i >= 4){
						parsed += msg[i+3];
						if(parsed == "/sc]" || parsed == "/SC]" 
						   || parsed == "/Sc]" || parsed == "/sC]"){
							cmd.push(0);
							i += 3;
							state = 0;
							break;
						}
						parsed.pop_back();
						parsed.pop_back();
						if(parsed == "sc" || parsed == "SC" 
						   || parsed == "Sc" || parsed == "sC"){
							i++;
							state = 3;
							break;
						}
						else if(parsed == "jl" || parsed == "JL" 
						   || parsed == "Jl" || parsed == "jL"){
							i++;
							state = 4;
							break;
						}
					}
				}
				else {
					cout<<"BAD TAG"<<endl;
					return -1;
				}
				break;
			// 2: ]
			case 2:
				if(ch == ']'){
					state = 0;
					temp += ']';
				}
				else {
					cout<<"BAD TAG"<<endl;
					return -1;
				}
				break;
			// 3: sc<digit>
			case 3:
				tempNum = 0;
				flag = false;
				while(ch >= '0' && ch <= '9'){
					tempNum *= 10;
					tempNum += (int)(ch - '0');
					ch = msg[++i];
					flag = true;
				}
				if(flag && ch == ']'){
					cmd.push(tempNum);
					state = 0;
					break;	
				}
				else {
					cout<<"BAD TAG"<<endl;
					return -1;
				}				
				break;
			// 4: jl<digit>
			case 4:
				if(ch >= '2' && ch <= '5' && (len - i >= 2 && msg[i+1] == ']')){
					cmd.push(0 - (int)(ch - '0'));
					i++;
					state = 0;
					break;
				}
				else {
					cout<<"BAD TAG"<<endl;
					return -1;
				}
				break;
		}
	}
	if(temp != ""){
		if(cmd.size() > 0 && cmd.back() == -6)
			msgQueue.back() += temp;
		else{
			msgQueue.push(temp);
			cmd.push(-6);
		}
		temp = "";
	}
	return 0;
}

string trim(string str){
	while(str[0] == ' '){
		str.erase(0, 1);
	}
	while(str[str.length()-1] == ' '){
		str.erase(str.length()-1, 1);
	}
	return str;
}

int newline(vector<string> &msg, string &line, string msgline[4], bool currentJl[4], int R, int C, int &currentRow){
	string space = "";
	int tempsc, len[4];
	
	if(currentRow < R) currentRow++;
	else return -1;
	
	for(int i=0; i<4; i++) len[i] = msgline[i].length();
	
	if(msgline[0] != ""){
		if(msgline[1] != ""){
			// msg msg msg
			if(msgline[2] != ""){
				if(len[0] >= (C-len[1])/2 || (C-len[1])/2 + len[1] + 1 >= C - len[2]) return -1;
				line += msgline[0];
				for(int i=len[0]; i<(C-len[1])/2; i++) line += " ";
				line += msgline[1];
				
				for(int i = line.length(); i<(C-len[2]); i++) line += " ";
				line += msgline[2];
			}
			// msg msg  x
			else{
				if(len[0] >= (C-len[1])/2) return -1;
				line += msgline[0];
				for(int i=len[0]; i<(C-len[1])/2; i++) line += " ";
				line += msgline[1];
			}
		}
		// msg  x  msg
		else if(msgline[2] != ""){
			if(len[0] >= C - len[2]) return -1;
			line += msgline[0];
			for(int i=len[0]; i<C-len[2]; i++) line += " ";
			line += msgline[2];
		} 
		// msg  x   x
		else{
			if(C < len[0]) return -1;
			line += msgline[0];
		}
	}
	else if(msgline[1] != ""){
		//  x  msg msg
		if(msgline[2] != ""){
			if((C-len[1])/2 + len[1] + 1 >= C - len[2]) return -1;
			
			for(int i=0; i<(C-len[1])/2; i++) line += " ";
			line += msgline[1];
			
			for(int i = line.length(); i<(C-len[2]); i++) line += " ";
			line += msgline[2];
		}
		//  x  msg  x
		else{
			if(C < len[1]) return -1;
			
			for(int i=0; i<(C-len[1])/2; i++) line += " ";
			line += msgline[1];
		}
	}
	//  x   x  msg
	else if(msgline[2] != ""){
		if(C < len[2]) return -1;
		
		for(int i=0; i<C-len[2]; i++) line += " ";
		line += msgline[2];
	}
	// xxxxxxxxxxx
	else if(msgline[3] != ""){
		tempsc = (C - len[3])/(len[3] > 1 ? (len[3]-1) : 1);
		for(int i=0; i<tempsc; i++) space += " ";
		
		if(len[3] + tempsc * (len[3] - 1) > C) return -1;
		line += msgline[3][0];
		for(int i=1; i<len[3]; i++) line += space + msgline[3][i];
		
		len[3] = line.length();
		space = "";
		for(int i=0; i<(C-len[3])/2; i++) space += " ";
		line = space + line;
	}
	
	// 뒤에 빈칸 채우기
	if(line.length() < C)
		for(int i = line.length(); i<C; i++) line += " ";
	msg.push_back(line);
	// initialization
	line = "";
	currentJl[0] = false; currentJl[1] = false; currentJl[2] = false; currentJl[3] = false;
	msgline[0] = ""; msgline[1] = ""; msgline[2] = ""; msgline[3] = "";
	
	return 0;
}