#include<iostream>
#include<vector>

using namespace std;

class Planet{
private:
	int x,y,r;
public:
	Planet(int x, int y, int r){
		this->x = x; this->y = y; this->r = r;
	}
	bool isInsideHere(int x, int y){
		int distSqare = (this->x - x)*(this->x - x) + (this->y - y)*(this->y - y);
		if(r*r > distSqare) return true;
		else return false;
	}
};

int calcMinShiftOrbit(){
	int N, x1, y1, x2, y2, ret = 0;
	int tempX, tempY, tempR;
	vector<Planet> planets;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> N;
	for(int i=0; i<N; i++){
		cin>>tempX>>tempY>>tempR;
		planets.push_back(Planet(tempX,tempY,tempR));
		if(planets.back().isInsideHere(x1,y1) != planets.back().isInsideHere(x2,y2)) ret++;
	}
	return ret;	
}
int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
		cout << calcMinShiftOrbit() << endl;
	return 0;
}