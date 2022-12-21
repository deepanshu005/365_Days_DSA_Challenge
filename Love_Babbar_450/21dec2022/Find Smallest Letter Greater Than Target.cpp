// CPP DSA Love Babbar 450
class Solution {
public:
    int BS( vector<char>arr, int i, int j, char ch, bool &exact ){
        int mid = i + (j-i)/2;
        int res = -1;
        while( i<=j ){
            mid = i + (j-i)/2;
            if( ch==arr[mid] ){
                exact = true;
                return mid;
            }
            if( ch<arr[mid] ){// Socho kya mid wala just greater ho skta h 
                j = mid-1;// Haan ho skta h
                res = mid;// hence updating the index
            }
            else{
                i = mid+1;
            }
        }
        return res;
    }
    char nextGreatestLetter(vector<char>& letters, char x) {
        bool exact = false;
        int n = letters.size();
        int index = BS( letters, 0, n-1, x, exact );
        
        if( index==-1 ){
            return letters[0];
        }
        while( index<n-1  ){
            if( letters[index] != letters[index+1] ){
                if(exact)
                    return letters[index+1];
                return letters[index];
            }
            index++;
        }
        if( index==(n-1) and !exact ){
            return letters[index];
        }
        return letters[0];
    }
};
