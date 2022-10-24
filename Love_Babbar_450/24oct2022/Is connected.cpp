// CPP DSA CN Lec 20
#include <iostream>
using namespace std;

void isConnected(int** edges,int n,int node,bool* visited){
  visited[node]=true;

  for(int i=0;i<n;i++){

    if(edges[node][i] && !visited[i])
      isConnected(edges,n,i,visited);
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
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
      visited[i]=false;

    isConnected(edges,V,0,visited);
    for(int i=0;i<V;i++){
      if(visited[i]==false){
        cout<<"false"<<endl;
        return 0;
      }
    }
    cout<<"true"<<endl;

  return 0;
}
