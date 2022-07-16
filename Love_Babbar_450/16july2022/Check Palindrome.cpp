// Lecture 10 from coding ninjas cpp introduction course
bool checkPalindrome(char str[]) {
    int k = strlen(str); //thiis returns the total number of characters excluding null character
	int i = 0;
    int j = k-1;
    bool isPalin = true;
    while( i<j ){
        if( str[i]!=str[j] )
            return false;
        i++;
        j--;
    }
    return true;
}
