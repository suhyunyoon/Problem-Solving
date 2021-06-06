#include<iostream>
using namespace std;
int main(){
	int w, h, p, q, t;
	int ppos, qpos, pdir, qdir, cnt = 0;
	cin>>w>>h;
	cin>>p>>q>>t;
	w--; h--;
	ppos = p; qpos = q;
	// + or -
	pdir = 1; qdir = 1;
	
	do{
		if(pdir==1 && ppos>=w) pdir = -1;
		else if(qdir==1 && qpos>=h) qdir = -1;
		else if(pdir==-1 && ppos<=0) pdir = 1;
		else if(qdir==-1 && qpos<=0) qdir = 1;
		
		ppos+=pdir;
		qpos+=qdir;
		cnt++;
	}while(!(ppos == p && qpos == q && pdir == 1 && qdir == 1));
	
	cout<<cnt<<'\n';
	
	return 0;
}
/*
if(p/w==1) x = w-x;
if(q/h==1) y = h-y;

*/