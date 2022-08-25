#include<bits/stdc++.h>
string second_repeat(vector<string> &arr, int n){
    map< string, int>MyMap;
    for( int i=0; i<n; i++ ){
        if( MyMap.find(arr[i]) != MyMap.end() ){
            MyMap[arr[i]]++;
        }
        else
            MyMap[arr[i]] = 1;
    }
    int j = 0;
    int m = 1;
    string str = "";
    for( auto itr = MyMap.begin(); itr != MyMap.end(); itr++){
        if( itr->second >m ){ 
            j = m;
            m = itr->second;
            str = itr->first;
        }
    }
    return str;
}
