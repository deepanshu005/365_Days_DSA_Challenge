// CPP DSA CN Lec 17 Love babbar 450
// #include<bits/stdc++.h>
// using namespace std;
// bool isOkay( int i, int j, int n, int *arr){
//     //for row
//     for( int x=i; x<n; x++){
//         if( arr[x][j]>0 )
//             return false;
//     }
//     //for column
//     for( int y=j; y<n; y++){
//         if( arr[i][y]>0 )
//             return false;
//     }
//     //for back diagonal moving downward
//     for( int x=i, int y=j; x<n && y<n ; x++,y++){
//         if( arr[x][y]>0 )
//             return false;
//     }
    
//     //for back diagonal moving upward
//     for( int x=i, int y=j; x>=0 && y>=0 ; x--,y--){
//         if( arr[x][y]>0 )
//             return false;
//     }
    
//     //for forward diagonal moving downward
//     for( int x=i, int y=j; x<n && y>=0 ; x++,y--){
//         if( arr[x][y]>0 )
//             return false;
//     }
    
//     //for back diagonal moving upward
//     for( int x=i, int y=j; x>=0 && y<n ; x--,y++){
//         if( arr[x][y]>0 )
//             return false;
//     }
//     return true;
// }
// int main(){
//     int n;
//     cin>>n;
//     int **arr = new int*[n];
//     for( int i=0; i<n; i++ ){
//         arr[i] = new int[n];
//         for( int j=0; j<n; j++ ){
//             arr[i][j] = 0;
//         }
//     }
    
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

int board[11][11];

bool isPossible(int n,int row,int col){
// No need to check for lower coz we are moving down roowise hence no need to check below of the current row
// Same Column
  for(int i=row-1;i>=0;i--){
    if(board[i][col] == 1){
      return false;
    }
  }
//Upper Left Diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
    if(board[i][j] ==1){
      return false;
    }
  }

  // Upper Right Diagonal

  for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
    if(board[i][j] == 1){
      return false;
    }
  }

  return true;
}
void nQueenHelper(int n,int row){
  if(row==n){
    // We have reached some solution.
    // Print the board matrix
    // return

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << board[i][j] << " ";
      }
    }
    cout<<endl;
    return;

  }

  // Place at all possible positions and move to smaller problem
  for(int j=0;j<n;j++){

    if(isPossible(n,row,j)){
      board[row][j] = 1;
      nQueenHelper(n,row+1);
      board[row][j] = 0;
    }
  }
  return;

}
void placeNQueens(int n){

  memset(board,0,11*11*sizeof(int));

  nQueenHelper(n,0);

}
int main(){
  int n;
    cin>>n;
  placeNQueens(n);
  return 0;
}
