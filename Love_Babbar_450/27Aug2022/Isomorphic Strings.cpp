// CPP DSA Love Babbar 450
#include<bits/stdc++.h>
bool areIsomorphic(string &str1, string &str2){
    int m = str1.length();
    int n = str2.length();
    if( m!=n )
        return false;
    map<char,char> Map;
    map<char,bool> used;
    for( int i=0; i<m ; i++){
        if( Map.find(str1[i] ) != Map.end() ){//searching if str[i] is present in Map
          //if str1[i] is present means already mapped with someone
            //so if the mapped element is not present in used map then return false
            if( used.find(Map[str1[i]]) == used.end() )
                return false;
            else{
                //if mapped element is present but mapped with someone else
                if( str2[i] != Map[str1[i]])
                    return false;
            }
        }
        else{// pair is not present in map
            Map[str1[i]] = str2[i];//pushing that pair in map
            
            if( used.find(Map[str1[i]]) != used.end() ){
                //if mapped element is present in used map
                if(  str2[i] != used[Map[str1[i]]]){
                    //if element present but mapped with someone else
                    return false;
                }
            }
            else{
             //if mapped element is not present in used map then pushing that pair in used map
                used[str2[i]] = true;
            }
        }
    }
    return true;
}
