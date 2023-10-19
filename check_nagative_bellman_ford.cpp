#include <bits/stdc++.h>
using namespace std;


class Edges
{
public:
    int u;
    int v;
    int w;

    Edges(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;

    }


};

int main()
{

   int n,e;
   cin>>n>>e;
   vector<Edges>v;

   while(e--){
      int a,b,w;
      cin>>a>>b>>w;

      Edges ed(a,b,w);
      v.push_back(ed);
   }

   int dist[n+1];

   for(int i=1;i<=n-1;i++){
     dist[i]=INT_MAX;
   }
    dist[1]=0;

    for(int i=1;i<=n;i++){
         for(int j=0;j<v.size();j++){
             Edges ed= v[j];
             int a=ed.u;
             int b=ed.v;
             int w=ed.w;

             if(dist[a]+w < dist[b]){
                 dist[b] = dist[a] + w;
             }
         }
    }

    bool cycle = false;

     for(int j=0;j<v.size();j++){
             Edges ed= v[j];
             int a=ed.u;
             int b=ed.v;
             int w=ed.w;

             if(dist[a]+w < dist[b]){
                    cycle=true;
                    break;
                 dist[b] = dist[a] + w;
             }
         }


    if(cycle){
         cout<<"Cycle Exist"<<endl;
    }
    else{
         for(int i=1;i<=n;i++){
             cout<<"Node "<<i<<" "<<dist[i]<<endl;
         }
    }

    return 0;
}
