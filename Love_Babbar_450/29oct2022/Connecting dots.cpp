// CPP DSA CN Lec 20 Love Babbar 450
void dfs (vector<vector<char>> &board,vector<vector<bool>> &visited, int x ,int y, int fromx,int fromy,char needcolor,bool &foundcycle,int n,int m){
    if(x<0 || x>=n || y<0 || y>=m)
    {
        return;
    }

    if(board[x][y] != needcolor)
    {
        return;
    }

    if(visited[x][y])
    {
        foundcycle=true;
        return;
    }

    visited[x][y]=true;
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

    for(int i=0;i<4;++i)
    {
        int nextx=x+dx[i];
        int nexty =y+dy[i];
        if(nextx ==fromx && nexty == fromy)
        continue;
        dfs(board,visited,nextx,nexty,x,y,needcolor,foundcycle,n,m);
    }


} 

bool hasCycle(vector<vector<char>> &board,int n,int m)
{
    bool foundcycle=false;
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j])
            {
                dfs(board,visited,i,j,-1,-1,board[i][j],foundcycle,n,m);
            }
        }
    }
    return foundcycle;
}

