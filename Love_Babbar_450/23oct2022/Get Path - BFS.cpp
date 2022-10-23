// CPP DSA CN Lec 20 Love Babbar 450
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


void getPathBFS(int **edges,int n,int start,int end,bool* visited,unordered_map<int,int> &prec){
  
  queue<int> q;
  q.push(start);

  while(!q.empty()){
    int node=q.front();
    q.pop();
    visited[node]=true;

    if(node==end)
      return;
    for(int i=0;i<n;i++){
      if(edges[node][i] && !visited[i]){
        q.push(i);
        if(prec.count(i)==0)
          prec[i]=node;
      }
    }
  }
}

int main()
{
  int V, E;
  cin >> V >> E;

  int **edges=new int*[V];
  //intialization
  for(int i=0;i<V;i++){
    edges[i]=new int[V];
    for(int j=0;j<V;j++)
      edges[i][j]=0;
  }

  for(int i=0;i<E;i++){
    int a,b;
    cin>>a>>b;
    edges[a][b]=1;
    edges[b][a]=1;
  }

  int s,e;
  cin>>s>>e;
  bool* visited=new bool[V];
  for(int i=0;i<V;i++)
    visited[i]=false;

  unordered_map<int,int> prec;
  getPathBFS(edges,V,s,e,visited,prec);

  if(visited[e]){
    int t=e;
    while(t!=s){
      cout<<t<<" ";
      t=prec[t];
    }
    cout<<t;
  }

  return 0;
}
