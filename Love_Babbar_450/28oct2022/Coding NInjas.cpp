// CPP DSA CN Lec 20 Love Babbar 450
int validpoint(int x,int y,int n,int m)
{
    return(x>=0 && x<n && y>=0 &&y<m);
}

bool dfs(vector<vector<char>> &board,vector<vector<bool>> &used, string &word,int x,int y,int wordindex,int n,int m)
{
    if(wordindex == 11)
    return true;

    used[x][y]= true;
    bool found= false;
    int dxdy[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    for(int i=0;i<8;++i)
    {
        int newx=x+dxdy[i][0];
        int newy = y+dxdy[i][1];

        if(validpoint(newx,newy,n,m) && board[newx][newy] == word[wordindex] && !used[newx][newy])
        {
            found = found | dfs(board,used,word,newx,newy,wordindex+1,n,m);

        }
    }
    used[x][y]=false;
    return found;
}

bool hasPath(vector<vector<char>> &board,int n ,int m)
{
    bool foundpath= false;
    string word= "CODINGNINJA";
    vector<vector<bool>> used(n,vector<bool>(m,false));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    foundpath=dfs(board,used,word,i,j,1,n,m);
                    if(foundpath) break;

                }
            }
            if(foundpath) break;
    }

    return foundpath;
}

