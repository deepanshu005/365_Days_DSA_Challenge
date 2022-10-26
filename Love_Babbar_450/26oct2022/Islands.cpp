// CPP DSA CN Lec 20 Love babbar 450

#include <bits/stdc++.h>
using namespace std;

void DFS(bool** graph, int v,bool* visited,int currentVertex){
    visited[currentVertex]=true;
    
    for(int i=0;i<v;++i)
    {
        if(graph[currentVertex][i] && !visited[i])
            DFS(graph,v,visited,i);
    }
    
}

int getislandgroups(bool** graph ,int v)
{
    bool* visited = new bool[v]();
    int groupcount =0;

      for(int i=0;i<v;++i)
    {
        if(!visited[i])
        {
            DFS(graph,v,visited,i);
            ++groupcount;
        }
    }
    return groupcount;
}

int main()
{
    int v,e;
    cin>>v>>e;
    bool** graph = new bool*[v];

    for(int i=0;i<v;i++)
    {
        graph[i]=new bool[v]();

    }

    for(int i=0,a,b;i<e;++i)
    {
        cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }

    cout<<getislandgroups(graph,v);
    for(int i=0;i<v;++i)
    {
        delete[] graph[i];
    }

    delete[] graph;
}
