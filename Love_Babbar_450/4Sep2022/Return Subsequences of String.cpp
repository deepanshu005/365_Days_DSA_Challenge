//CPP DSA Love Babbar
// This is Love Babbar Approach (Including And Excluding) 

#include<bits/stdc++.h>
void solve( string str,string temp, int index, vector<string>&ans ){
    if( index>= str.length() ){// base case
        if( temp != "" )// As we dont want empty push in answer hence putting a check before pushing
            ans.push_back(temp);
        return;
    }
    solve( str, temp, index+1, ans );// excluding the character at index
    
    temp += str[index];// including the character at index
    solve( str, temp, index+1, ans);
}
vector<string> subsequences( string str ){
    vector<string> ans;
    string temp = "";
    solve( str, temp, 0, ans );
    return ans;
}





/* Coding ninjas Approach */

#include <iostream>
using namespace std;

int subs(string input, string output[]) {
	if (input.empty()) {
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutputSize = subs(smallString, output);
	for (int i = 0; i < smallOutputSize; i++) {
		output[i + smallOutputSize] = input[0] + output[i];
	}
	return 2 * smallOutputSize;
}

int main() {
	string input;
	cin >> input;
	string* output = new string[1000];
	int count = subs(input, output);
	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
}
