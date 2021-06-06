#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

class Point{
public:
	int x, y, k, dir;
	Point(int x, int y, int k, int dir){
		this->x = x; this->y = y; this->k = k;
		this->dir = dir;
	}
};

class Collision{
public:
	int a, b;
	double t;
	Collision(int a, int b, double t){
		this->a = a; this->b = b; this->t = t;
	}
	// 오름차순 정렬
	bool operator<(Collision &other){
		return this->t > other.t;
	}
};


vector<Point> elem;
vector<Collision> elemHeap;

void willCollide(int i, int j){
	double t;
	// 수평선
	if(elem[i].x == elem[j].x){
		if((elem[i].y < elem[j].y && elem[i].dir == 3 && elem[j].dir == 2)
		  || (elem[i].y > elem[j].y && elem[i].dir == 2 && elem[j].dir == 3)){
			t = (double)(elem[i].y - elem[j].y) / 2;
			t = t > 0 ? t : t * -1;
			elemHeap.push_back(Collision(i, j, t));
		}
	}
	// 수직선
	else if(elem[i].y == elem[j].y){
		if((elem[i].x < elem[j].x && elem[i].dir == 0 && elem[j].dir == 1)
		  || (elem[i].x > elem[j].x && elem[i].dir == 1 && elem[j].dir == 0)){
			t = (double)(elem[i].x - elem[j].x) / 2;
			t = t > 0 ? t : t * -1;
			elemHeap.push_back(Collision(i, j, t));
		}
	}
	// 기타(i 기준으로 탐색)
	// 위
	else if(elem[i].dir == 0){
		if(elem[i].x < elem[j].x){
			t = elem[j].x - elem[i].x;
			if((elem[j].dir == 2 && elem[j].y - t == elem[i].y)
			  || (elem[j].dir == 3 && elem[j].y + t == elem[i].y))
				elemHeap.push_back(Collision(i, j, t));
		}
	}
	// 아래
	else if(elem[i].dir == 1){
		if(elem[i].x > elem[j].x){
			t = elem[i].x - elem[j].x;
			if((elem[j].dir == 2 && elem[j].y - t == elem[i].y)
			  || (elem[j].dir == 3 && elem[j].y + t == elem[i].y))
				elemHeap.push_back(Collision(i, j, t));
		}
	}
	// 좌
	else if(elem[i].dir == 2){
		if(elem[i].y > elem[j].y){
			t = elem[i].y - elem[j].y;
			if((elem[j].dir == 1 && elem[j].x - t == elem[i].x)
			  || (elem[j].dir == 0 && elem[j].x + t == elem[i].x))
				elemHeap.push_back(Collision(i, j, t));
		}
	}
	// 우
	else if(elem[i].dir == 3){
		if(elem[i].y < elem[j].y){
			t = elem[j].y - elem[i].y;
			if((elem[j].dir == 1 && elem[j].x - t == elem[i].x)
			  || (elem[j].dir == 0 && elem[j].x + t == elem[i].x))
				elemHeap.push_back(Collision(i, j, t));
		}
	}
}

int main(int argc, char** argv)
{
	int test_case, x, y, k, dir;
	int T, n, ans;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		double lastT = 0.0;
		map<int, double> collided;
		elem.clear();
		elemHeap.clear();
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>y>>x>>dir>>k;
			elem.push_back(Point(x,y,k,dir));
			// 접점 찾음
			for(int j=0; j<i; j++)
				willCollide(i, j);
		}
		// heap 만듦
		make_heap(elemHeap.begin(), elemHeap.end());
		// heap 에서 빼면서 체크
		while(elemHeap.size()){
			Collision &temp = elemHeap.front();
			// 이미 충돌한건지 체크
			if(!collided[temp.a] && !collided[temp.b]){
				ans += elem[temp.a].k + elem[temp.b].k;
				collided[temp.a] = temp.t; collided[temp.b] = temp.t;
			}
			// 같은 점이라면?
			else if(temp.t == lastT){
				if(collided[temp.a] == temp.t && !collided[temp.b]){
					ans += elem[temp.b].k;
					collided[temp.b] = temp.t;
				}
				else if(!collided[temp.a] && collided[temp.b] == temp.t){
					ans += elem[temp.a].k;
					collided[temp.a] = temp.t;
				}
			}
			lastT = temp.t;
			pop_heap(elemHeap.begin(), elemHeap.end()); elemHeap.pop_back();
		}
		cout<<"#"<<test_case<<" "<<ans<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}