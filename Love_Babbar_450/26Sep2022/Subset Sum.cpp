// CPP DSA CN lec 17 Love Babbar 450
#include<bits/stdc++.h>
using namespace std;

#define N 9

bool isvalid(int board[][9],int row,int col,int val)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==val)
        {
            return false;
        }
        if(board[row][i]==val)
        {
            return false;
        }
    }
    int newrow = row - (row%3);
    int newcol = col - (col%3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i+newrow][j+newcol]==val)
            {
                return false;
            }
        }
    }
    return true;
    
}
    
bool findempty(int board[][9],int &row,int &col)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool sudokuSolver(int board[][9]){

  int row,col;
  if(!findempty(board,row,col))
  {
      return true;
  }
  for(int i=1;i<=9;i++)
  {
      if(isvalid(board,row,col,i))
      {
          board[row][col] = i;
          bool ans = sudokuSolver(board);
          if(ans)
          {
              return true;
          }
          board[row][col]=0;
      }
  }
  return false;  
 

}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}
