#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
bool visited[N];
vector<int> adj[N];
int dist[N];

 void bfs(int src){
     queue<int> q;
     q.push(src);
     visited[src]=true;
     dist[N]=0;

     while(!q.empty()){
         int parent =q.front();
         q.pop();
          cout<<parent<<" ";
         for(int i:adj[parent]){
             int child = i;
             if(visited[child]==false){
                 q.push(child);
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

    for(int i=1;i<=n;i++){
         cout<<i<<" :"<<dist[i]<<endl;
    }

    return 0;
}



