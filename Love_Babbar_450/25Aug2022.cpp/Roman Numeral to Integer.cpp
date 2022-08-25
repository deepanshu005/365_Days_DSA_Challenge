// Love Babbar DSA 450
#include<bits/stdc++.h>
int romanToInt(string str) {
    map<char,int>MyMap;
    MyMap['I'] = 1;
    MyMap['V'] = 5;
    MyMap['X'] = 10;
    MyMap['L'] = 50;
    MyMap['C'] = 100;
    MyMap['D'] = 500;
    MyMap['M'] = 1000;
    int n = str.length();
    int num = 0;
    for( int i=0; i<n-1; i++){
        if( MyMap[str[i]] < MyMap[str[i+1]])// if the next element is greater than the prev element then we have to subtract the current element
            num = num - MyMap[str[i]];
        else
            num += MyMap[str[i]];
    }
    num += MyMap[str[n-1]];
    return num;
}
