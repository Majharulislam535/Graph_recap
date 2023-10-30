#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

const int N = 1e5+5;
bool visited[N];
vector<pi> v[N];

class Edges{

public:
     int a,b,w;
     Edges(int a,int b,int w){
           this->a= a;
           this->b = b;
           this->w = w;
       }

};

  class cmp{
  public:
     bool operator()(Edges a,Edges b){

        return a.w > b.w;
     }

  };

 void prims(int s){

     priority_queue<Edges,vector<Edges>,cmp> pq;
     vector<Edges> edgeList;

     pq.push(Edges(s,s,0));

     while(!pq.empty()){
          Edges parent = pq.top();
          pq.pop();

          int a = parent.a;
          int b = parent.b;
          int w = parent.w;

          if(visited[b])continue;

          visited[b] = true;

          edgeList.push_back(parent);

          for(int i=0;i<v[b].size();i++){
              pi child = v[b][i];

              if(!visited[child.first]){
                  pq.push(Edges(b,child.first,child.second));
              }

          }

     }

         edgeList.erase(edgeList.begin());

          for(Edges i:edgeList){

               cout<<i.a<<" "<<i.b<<" "<<i.w<<" "<<endl;
          }


 }




int main()
{

   int n,e;
   cin>>n>>e;

    while(e--){

          int a,b,w;
          cin>>a>>b>>w;

          v[a].push_back({b,w});
          v[b].push_back({a,w});


    }

    prims(1);




    return 0;
}

/*
8 11
1 5 2
1 2 4
1 4 10
5 4 5
2 4 8
2 3 18
3 4 11
4 8 9
4 7 11
7 6 1
8 6 2
*/
