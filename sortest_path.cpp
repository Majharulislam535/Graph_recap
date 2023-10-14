#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
vector<int> adj[N];
bool visited[N];
int dist[N];
int pare[N];

void bfs(int src){
   queue<int> q;
   q.push(src);
   pare[src]=-1;
   dist[src] = 0;
   visited[src]=true;

    while(!q.empty()){
         int parent = q.front();
         q.pop();

         for(int child:adj[parent]){

            if(visited[child]==false){
                 q.push(child);
                 pare[child]=parent;
                 dist[child] = dist[parent] + 1;
                 visited[child]=true;
            }
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

    bfs(1);

    int d;
    cin>>d;

     vector<int> result;

     if(visited[d]){
         int x=d;
         while(x!=-1){
             result.push_back(x);
             x=pare[x];
         }
     }
     else{
         cout<<"path nay"<<endl;
     }

     reverse(result.begin(),result.end());

     for(int i:result){
         cout<<i<<" ";
     }


    return 0;
}



