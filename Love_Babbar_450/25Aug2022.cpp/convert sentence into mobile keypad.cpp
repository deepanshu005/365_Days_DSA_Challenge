//Love_babbar 450 DSA
#include<bits/stdc++.h>
string convertSentence(string str, int n){
	
    string ans = "";
    map<char,string >MyMap;
        MyMap['a'] = '2';
        MyMap['b'] = "22";
        MyMap['c'] = "222";
        MyMap['d'] = '3';
        MyMap['e'] = "33";
        MyMap['f'] = "333";
        MyMap['g'] = '4';
        MyMap['h'] = "44";
        MyMap['i'] = "444";
        MyMap['j'] = '5';
        MyMap['k'] = "55";
        MyMap['l'] = "555";
        MyMap['m'] = '6';
        MyMap['n'] = "66";
        MyMap['o'] = "666";
        MyMap['p'] = '7';
        MyMap['q'] = "77";
        MyMap['r'] = "777";
        MyMap['s'] = "7777";
        MyMap['t'] = '8';
        MyMap['u'] = "88";
        MyMap['v'] = "888";
        MyMap['w'] = '9';
        MyMap['x'] = "99";
        MyMap['y'] = "999";
        MyMap['z'] = "9999";
//     int n = str.length();
    // string ans = MyMap[str[0]] ;
    for( int i=0; i<n; i++){
        ans = ans + MyMap[str[i]];
    }
    return ans;
}
