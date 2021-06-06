#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	return 0;
}

/*
// 17230_문제집만들기.cpp

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main(void){
   int n, m, q;
   int a, b, w, x, y;
   list<int> qlist[100001];
   
   cin>>n>>m>>q;
   
   for(int i=0; i<m; i++){
      cin>>a>>b;
      qlist[a].push_back(b);
      qlist[a].sort();
   }

   list<int>::iterator it;
   
   for(int i=0; i<q; i++){
      cin>>w>>x>>y;
      if(w==1){
         int flag=0;
         for(int j=x; j<y+1; j++){
            if(qlist[j].empty()){   
            }
            else if(qlist[j].front()<x){
               flag=1;
               break;
            }
            else if(qlist[j].back()>y){
               flag=1;
               break;
            }
         }
         if(flag==1){
            cout<<"NO\n";   
         }
         else{
            cout<<"YES\n";   
         }
      }
      else if(w==2){
         qlist[x].remove(y);
      }
      else{
         qlist[x].push_back(y);
         qlist[x].sort();
      }
   }
   
   return 0;
}*/