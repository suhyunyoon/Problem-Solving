#include<stdio.h>
#include<vector>
using namespace std;

vector<int> a;

void printAnswer(int x, int y1, int y2, int z, int n){
	while(x==n || x==0 || y1==0 || y2==0 || z==0 || z==n || y1>y2){
		if(x==1) x=x+n;
		if(z==1) z=z+n;
		x--; y1++;y2++; z++;
		y1%=n; y2%=n; z%=n;
	}
	printf("%d\n%d %d\n%d\n", x, y1, y2, z);
}

void solve(int n){
	int CountDown = 1;
	for(int i=1; i<n; i++){
		int cur=a[i]%n;
		if((a[i-1]-1)==cur) CountDown++;
	}
	if(CountDown==n){
		for(int i=0; i<n/2; i++){
			a.push_back(a[0]);
			a.erase(a.begin());
		}
		int left=1, right=n-1, delta1 = 0;
		while(left<right){
			int temp=a[left];
			a[left]=a[right];
			a[right]=temp;
			left++, right--;
		}
		for(int i=0; i<n;){
			if(a[i] != 1){
				a.push_back(a[i]);
				a.erase(a.begin());
				delta1++;
			}
			else
				break;
		}
		printAnswer(n-delta1, 2, n, n-n/2, n);
		
		return ;
	}
	
	int delta2=0;
	for(int i=1; i<n;){
		int prev=a[i-1]%n;
		if(prev+1 != a[i]){
			a.push_back(a[i-1]);
			a.erase(a.begin());
			delta2++;
		}
		else
			break;
	}
	
	for(int i=n-1; i>=1;){
		int cur=a[i]%n;
		if(a[i-1]-1 != cur){
			a.insert(a.begin(), a[i]);
			a.erase(a.end()-1);
			delta2--;
		}
		else{
			break;
		}
	}
	delta2 = (n+delta2)%n;
	
	int left=0, right=n-1;
	for(int i=0; i<n-1; i++){
		if(a[i]-1 == a[i+1]%n){
			left=i;
			break;
		}
	}
	int n1=left, n2=right;
	
	while(left < right){
		int temp=a[left];
		a[left]=a[right];
		a[right]=temp;
		left++, right--;
	}
	int delta1=0;
	for(int i=0; i<n;){
		if(a[i] != 1){
			a.push_back(a[i]);
			a.erase(a.begin());
			delta1++;
		}
		else break;
	}
	printAnswer(n-delta1, n1+1, n2+1, n-delta2, n);
}

int main(){
	int n;
	scanf("%d", &n);
	a.resize(n);
	
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	
	solve(n);
	
	return 0;
}