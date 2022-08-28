//CPP DSA Love Babbar
#include<bits/stdc++.h>
vector<vector<string> > groupAnagramsTogether(vector<string> &List){
    
    map< string, vector<string> > Map;
    int n = List.size();
    //creating map and pushing values
    for( int i=0; i<n; i++){
        string str = List[i];
        sort( str.begin(), str.end() );
        Map[str].push_back( List[i] );//Map[str] is a vector which is the value of key str of Map 
    }
    vector< vector<string> > ans;
    //Now traversing the whole map to store it into vector
    for( auto i: Map )
        ans.push_back(i.second);
    return ans;
}
