//CPP DSA Love Babbar 450
/*
#include<unordered_map>
#include<string>
string uniqueChar(string str) {
	string newstr;
    int k=0;
    unordered_map< char, int > ourmap;
	for(int i=0; i<str.length(); i++){
        ourmap[str[i]]++;
        
        if(ourmap[str[i]] < 2){
            newstr[k] = str[i];	// this statement is not valid coz we hadnt specified the size of string
            k++;
        }
    }
	return newstr;
}*/

// #include<unordered_map>
// #include<string>
// string uniqueChar(string str) {
// 	string newstr;
//     int k=0;
//     unordered_map< char, bool > ourmap;
// 	for(int i=0; i<str.length(); i++){
//         if(ourmap.count(str[i]) > 0){
//             continue;
//         }
//         else{
//             ourmap[str[i]] = true;
//             newstr.push_back(str[i]);
//         }
//     }
// 	return newstr;
// }
#include<unordered_map>
#include<string>
string uniqueChar(string str) {
	string newstr = "";
    // int k=0;
    unordered_map< char, int > ourmap;
	for(int i=0; i<str.length(); i++){
        ourmap[str[i]]++;
        
        if(ourmap[str[i]] < 2){
            // string concatenation
            newstr += str[i];
            // k++;
        }
    }
	return newstr;
}
