// CPP DSA CN Lec 20 Love Babbar 450
#include <iostream>
using namespace std;

void hasPath(int** edges,int n,int start,int end,bool *visited){
  

  visited[start]=true;
  if(start==end)
    return;
  
  for(int i=0;i<n;i++){

    if(i==start)
      continue;
    
    if(edges[start][i] && !visited[i])
      hasPath(edges,n,i,end,visited);
  }
}

int main() {
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

  hasPath(edges,V,s,e,visited);

  cout<<boolalpha<<visited[e]<<endl;
  return 0;
}
