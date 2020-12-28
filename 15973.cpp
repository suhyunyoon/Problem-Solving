#include<iostream> 
using namespace std;
int main(){
	int xmin[2], ymin[2], xmax[2], ymax[2];
	cin>>xmin[0]>>ymin[0]>>xmax[0]>>ymax[0];
	cin>>xmin[1]>>ymin[1]>>xmax[1]>>ymax[1];
	
	if(xmin[0] > xmax[1] || xmin[1] > xmax[0] || ymin[0] > ymax[1] || ymin[1] > ymax[0]) cout<<"NULL\n";
	else if((xmin[0] == xmax[1] && ymin[0] == ymax[1]) || (xmin[0] == xmax[1] && ymax[0] == ymin[1])
		  || (xmax[0] == xmin[1] && ymin[0] == ymax[1]) || (xmax[0] == xmin[1] && ymax[0] == ymin[1])) cout<<"POINT\n";
	else if(xmin[0] == xmax[1] || xmax[0] == xmin[1] || ymin[0] == ymax[1] || ymax[0] == ymin[1]) cout<<"LINE\n";
	else cout<<"FACE\n";
	return 0;
}