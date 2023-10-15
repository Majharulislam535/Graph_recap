#include<bits/stdc++.h>

using namespace std;

const int N= 1e5+5;
bool visited[N];
vector<int> adj[N];

vector<int>cmp;


void dfs(int s){

  visited[s]=true;
   cmp.push_back(s);
  for(int child:adj[s]){
      if(!visited[child]){
         dfs(child);
      }
  }

}

int main()
{
     int n,e;
     cin>>n>>e;

     while(e--){
       int a,b;
       cin>>a>>b;

       adj[a].push_back(b);
       adj[b].push_back(a);
     }
     int cnt=0;
     for(int i=1;i<=n;i++){
         if(!visited[i]){
                cnt++;
             dfs(i);
         }

         for(int j:cmp){
             cout<<j<<" ";
         }
          

         cmp.clear();
     }

     cout<<cnt<<endl;

    return 0;
}



