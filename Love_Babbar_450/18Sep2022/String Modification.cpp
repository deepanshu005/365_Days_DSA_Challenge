// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
/* The below function should return 
the transformed string */
class Solution{
  private:
    char new_char( int arr[] ){
        char ch;
        int freq = 0;
        for(int i=0; i<26; i++ ){// Traversing the whole arr to get maxm frequency character
            if( freq<arr[i] ){
                freq = arr[i];
                ch = i + 'a';
            }
        }
        return ch;
    }
  public:
    string rearrangeString(string str){
        int n = str.length();
        int arr[26] = {};//freq array
        for(int i=0; i<n; i++ )// Traversing the string and incrementing frequencies in arr
            arr[ str[i] - 'a' ]++;
        char ch = new_char(arr);
        int freq = arr[ ch - 'a' ];
        if( freq>(n+1)/2 )  
            return "";
        
        char vec[n] = {};
        
        //now inserting max occured character in even positions
        int i;
        for( i=0; i<n; ){
            while( freq>0 and i<n ){
                vec[i] = ch;
                freq--;
                i+2;
            }
            if( i>=n-1 )
                break;
            if( i<n and freq<=0 ){
                arr[ ch-'a' ] = 0;
                ch = new_char(arr);
                freq = arr[ ch- 'a' ];
            }
        }
        for( int i=1; i<n; ){
            while( freq>0 and i<n ){
                vec[i] = ch;
                freq--;
                i+2;
            }
            if( i>=n-1 )
                break;
            if( i<n and freq<=0 ){
                arr[ ch-'a' ] = 0;
                ch = new_char(arr);
                freq = arr[ ch- 'a' ];
            }
        }
        string ans = "";
        for( int i=0; i<n; i++ ){
            ans +=vec[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    string str;
	fflush(stdin);
	cin>>str;
	int oldLength=str.length();
	int chs[26];
	memset(chs,0,sizeof(chs));
	for(int i=0;i<str.length();i++){
	    chs[str[i]-'a']++;
	}
	Solution obj;
    str=obj.rearrangeString(str);
	int flag=1,ff=0;
	int chs2[26];
	memset(chs2,0,sizeof(chs2));
	for(int i=0;i<str.length();i++)
	    if(str[i]>='a'&&str[i]<='z')
	        chs2[str[i]-'a']++;
    if(str.length()!=oldLength)
        cout<<"0\n";
    else{
        for(int i=0;i<26;i++)
            if(chs[i]!=chs2[i])
                ff=1;
        if(ff==1){
            cout<<"0\n";
        }
        else{
        	if(str!="-1"){
            	for(int i=0;i<str.length();i++)
            	{
            		if(i>0)
            		if(str[i-1]==str[i])
            			flag=0;
            	}
            	if(flag==1)
            		cout<<"1\n";
            	else
            	cout<<"0\n";
        	}
        	else
        		cout<<"0\n";
            }
        }
	}
    return 0;
}
// } Driver Code Ends
