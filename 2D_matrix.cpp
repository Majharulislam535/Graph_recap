#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;


 const int N = 1005;
 int dist[N][N];
 bool visited[N][N];
 vector<pi> path={{-1,0},{1,0},{0,-1},{0,1}};
 int n,m;

 bool isValid(int cI,int cJ){
if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;

  }

 void bfs(int si,int sj){

     queue<pi> q;
     q.push({si,sj});
     dist[si][sj]=0;
     visited[si][sj]=true;

     while(!q.empty()){

        pi parent = q.front();
        int pI = parent.first;
        int pJ=parent.second;

        q.pop();

        for(int i=0;i<4;i++){
             pi p=path[i];

             int cI = pI+p.first;
             int cJ=  pJ+p.second;

               if (isValid(cI, cJ) && !visited[cI][cJ])
            {
                visited[cI][cJ] = true;
                q.push({cI, cJ});
                dist[cI][cJ] = dist[pI][pJ] + 1;
            }

        }

     }

 }


int main()
{

   cin>>n>>m;

   char ar[n][m];

   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cin>>ar[i][j];
      }
   }

   int si,sj;
   cin>>si>>sj;

   bfs(si,sj);

   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cout<<dist[i][j];
      }
      cout<<endl;
   }


    return 0;
}


/*
2 4
....
....
0 1


for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cout<<ar[i][j];
      }
      cout<<endl;
   }

*/



