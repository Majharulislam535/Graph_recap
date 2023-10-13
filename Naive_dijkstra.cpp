#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5;
vector<pair<int,int>> adj[N];
int dist[N];


 void dijkstra(int s){

   queue<int> q;
   q.push(s);
   dist[s]=0;

   while(!q.empty()){
       int parent = q.front();
       q.pop();

       for(int i=0;i<adj[parent].size();i++){
          pair<int,int> child = adj[parent][i];
           int childNood = child.first;
           int childCost = child.second;

           if(dist[parent]+childCost < dist[childNood]){
               dist[childNood] =dist[parent]+childCost;
               q.push(childNood);
           }
       }



   }

 }


int main()
{

    int n,e;
    cin>>n>>e;

    while(e--){
         int a,b,w;
         cin>>a>>b>>w;

         adj[a].push_back({b,w});
         adj[b].push_back({a,w});
    }


    for(int i=1;i<=n;i++){
         dist[i]=INT_MAX;
    }

    dijkstra(1);

    for(int i=1;i<=n;i++){
         cout<<i<<" "<<dist[i]<<endl;
    }

    return 0;
}



