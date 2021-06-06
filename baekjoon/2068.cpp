#include<iostream>
#include<vector>
using namespace std;
int bicycleRace(int, int, int);
int intSqrt(int);
int race(vector<int>, int, int, int, int);

int main(){
	int ans[20][100][100];
	//cout<<bicycleRace(0,0,0)<<endl;
	/*for(int e=1; e<=100; e++){
		for(int d=1; d<=e; d++){
			cout<<bicycleRace(1,e,d)<<' ';
		}
		cout<<endl;
	}*/
	cout<<'{'<<endl;
	for(int n=4; n<=4; n++){
		for(int e=88; e<=100; e++){
			cout<<"\t";
			for(int d=1; d<=100; d++){
				cout<<bicycleRace(n,e,d)<<", ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<'}'<<endl;
	return 0;
}

int bicycleRace(int n, int e, int d){
	// input
	if(n == 0) cin>>n>>e>>d;
	vector<int> goats(n, e);
	// unable
	if(d>e){
		//cout<<0<<endl;
		return 0;
	}
	// normal case
	else{
		//cout<< race(goats, 0, d, 0, 0) << endl;
		return race(goats, 0, d, 0, 0);
	}
	return 0;
}

int race(vector<int> goats, int speed, int remainDist, int first, int time){
	int len = goats.size();
	int maxHP = 0;
	int minTime = 999;
	// reduce health
	goats[first] -= speed * (speed - 1);
	for(vector<int>::size_type i=0; i<len; i++){
		if(goats[i] > 0) goats[i] -= speed;
		if(goats[i] > maxHP) maxHP = goats[i];
	}
	remainDist -= speed;
	// check ending of race
	if(remainDist <= 0)
		return time;
	// check availability to next time
	if(maxHP < remainDist)
		return -1;
	// head one more time?
	int maxSpeed;
	if(goats[first] >= speed * speed && speed != 0)
		maxSpeed = speed;
	else{
		int before = first;
		int len = goats.size();
		int sec = 0;
		for(int i=0; i<len; i++)
			if(goats[first] < goats[i]) first = i;
		maxSpeed = intSqrt(goats[first]);
		
		/*for(; maxSpeed>=1; maxSpeed--){
			// 다음턴 가능한지 판단
			if(remainDist - maxSpeed <= goats[first] - (maxSpeed*(before == first ? maxSpeed : 1)) ) break;
		}*/
	}
	// run
	for(int sp = maxSpeed; sp>=1; sp--){
		int temp = race(goats, sp, remainDist, first, time+1);
		if(temp != -1 && temp < minTime) minTime = temp;
	}
	//cout<<time<<" "<<minTime<<endl;
	return minTime;
}

int intSqrt(int n){
	for(int i=1; i<n; i++){
		if(i*i > n)
			return i-1;
	}
}
