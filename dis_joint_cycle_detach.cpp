#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parentLevel[1000];

 void dsu_set(int n){

    for(int i=1;i<=n;i++){
         parent[i]=-1;
         parentLevel[i]=0;
    }
 }



 int find_Ope(int n){

      while(parent[n] != -1){

         n=parent[n];

      }

      return n;
 }


 void dsu_union(int a,int b){

      int leaderA = find_Ope(a);
      int leaderB = find_Ope(b);

      if(leaderA != leaderB){

          if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
      }
 }


int main()
{

  int n,e;
  cin>>n>>e;

  dsu_set(n);
  while(e--){

      int a,b;
      cin>>a>>b;

      int leaderA = find_Ope(a);
      int leaderB = find_Ope(b);

       if(leaderA == leaderB){
          cout<<"cycle detach "<<a<<" "<<b<<endl;
       }
       else{
         dsu_union(a,b);
       }


  }






    return 0;
}
