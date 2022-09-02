// Love Babbar DSA 450
// reversing means switching the curly bracket
int countRev (string str)
{
    if( str.length()%2 ==1 )
      return -1;// Means we can't make the string balanced
      
    int left = 0;
    int right = 0;
    int n = str.length();
    for( int i=0; i<n; i++ ){
       if( str[i] == '{' )
         left++;
       else
        {
            if(left>0)// removing the balanced part
               left--;
            else
               right++;
        }
    }
    return (left+1)/2 + (right+1)/2;// Avoiding the odd number of closing or opening brackets
}
