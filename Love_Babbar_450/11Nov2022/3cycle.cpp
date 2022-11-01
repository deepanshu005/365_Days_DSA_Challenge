//CPP DSA CN Lec 20 Love Babbar 450
#include<iostream>
using namespace std;

int getcycle(bool** graph,int v)
{
    int cyclecount=0;
    for(int i=0;i<v-2;++i)
    {
        for(int j=1+i;j<v-1;++j)
          {
              for(int k=j+1;k<v;++k)
              {
                  if(graph[i][j] && graph[j][k] && graph[k][i])
                  {
                      ++cyclecount;
                  }
              }
          }
    
    }
    return cyclecount;
}

int main()
{
    int v,e;
    cin>>v>>e;

    bool** graph= new bool*[v];

    for(int i=0;i<v;++i)
    {
        graph[i]=new bool[v]();
    }

    for(int i=0,a,b;i<e;++i)
    {
        cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }

    cout<<getcycle(graph,v);
    for(int i=0;i<v;++i)
    {
        delete[]graph[i];
    }
    delete graph;
}
