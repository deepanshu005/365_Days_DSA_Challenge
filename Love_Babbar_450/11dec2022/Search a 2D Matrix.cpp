// CPP DSA Love Babbar 450
class Solution {
public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
       int minrow = 0;
       int maxrow = matrix.size()-1;
       int midrow;
       int i = 0;
       while (minrow < maxrow) {
           // cout << minrow << " ";
           // cout << maxrow << " ";
           midrow = (minrow + maxrow) / 2;
           if (target < matrix[midrow][0]) {
               maxrow = midrow-1;
               // cout << "ch to max: " << maxrow;
           } else if (target > matrix[midrow][0]) {
               minrow = midrow;
               // cout << "ch to min: " << minrow;
           } else {
               cout << 1;
               return true;
           }
           // cout << i << '\n';
           i++;
       }
       return binary_search(matrix[minrow].begin(), matrix[minrow].end(), target);
   }
};
