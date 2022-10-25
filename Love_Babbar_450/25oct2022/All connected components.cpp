// CPP DSA CN Lec 20 Love Babbar 450
#include <bits/stdc++.h>
using namespace std;

void popCon(int **edges,int n,int start,bool* visited,vector<int> &v){
    
    v.push_back(start);
    visited[start]=true;
    
    for(int i=0;i<n;i++){
        
        if(i==start)
            continue;
        
        if(edges[start][i] && !visited[i])
            popCon(edges,n,i,visited,v);
    }
}


void printComponents(vector <vector <int> >&ans){
    
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    
    int **edges=new int*[V];
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
    
    vector <vector <int> > ans;
    vector <int> temp;
    for(int i=0;i<V;i++){
        
        if(!visited[i]){
            popCon(edges,V,i,visited,temp);
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        
    }
    
    printComponents(ans);
    
    

  return 0;
}
