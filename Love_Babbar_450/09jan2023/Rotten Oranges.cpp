// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    // rotten bole to sde hue
    // ek sda hua orange uske left right up down, total 4 oranges ko ek unit time m sda dega
    // Approach is very simple just an application of BFS as it rotten oranges at level 1
    // hence to apply BFS we will take a queue and a 2D array to have a count for visited
    // we will pe pushing those oranges that are rotten and visited 
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int vis[row][col];
        //{ {i,j}, time }
        queue<pair<pair<int,int>,int>> q;
        
        for( int i=0; i<row; i++ ){
            for( int j=0; j<col; j++ ){
                if( grid[i][j]==2 ){//pushing all the oranges which are already rotten and marking them as visited
                    q.push( {{i,j},0} );
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        int tym = 0; //l  r   t  b
        int drow[] = { 0, 0, -1, 1};
        int dcol[] = {-1, 1,  0, 0};
        while( !q.empty() ){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tym = max(tym, t);
            q.pop();
            for(int i=0; i<4; i++ ){// Now getting the neighbour of rotten oranges
                int newR = r+drow[i];
                int newC = c+dcol[i];
                if( newR>=0 and newR<row and newC>=0 and newC<col and vis[newR][newC] == 0 and grid[newR][newC]==1 ){
                    q.push( {{newR,newC},t+1} );// those which are not rotten we will rotten them and mark as visited
                    vis[newR][newC] = 2;
                }
                
            }
        }
        for( int i=0; i<row; i++ ){// just checking is there any orange left which is not rotten at the end
            for( int j=0; j<col; j++ ){
                if( grid[i][j]==1 and vis[i][j]!=2 ){
                    return -1;
                }
            }
        }
        return tym;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
