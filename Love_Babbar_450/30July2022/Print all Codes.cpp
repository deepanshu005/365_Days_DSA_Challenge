//CPP DSA CN Lec-04
#include <string.h>
using namespace std;

void printAllPossibleCodes( string input, string output = "" ){	// Output string is default argument
    if(input[0] == '\0'){ 	//Base case
        cout << output << endl; // Generally in case of printing subsequences the base case hits 2^n times
        return;
    } 
    int num = input[0] - 48;	// Converting first character integer to numeric integer
    char ch = num - 1 + 'a';	// Convertig number num into its corresponding character
    printAllPossibleCodes(input.substr(1), output + ch);	// Recursive call considering only 1st integer as code 
    if(input[1] != '\0'){	// CHecking if there is only one character left in the string
        num = num * 10 + input[1] - 48;	// If input string contains more than one characters and coverting two chars in a two digit integer
        ch = 'a' + num - 1 ;	// Convertig two digit number into its corresponding character
        if(num >= 10 && num <= 26)	// Calling only when two integers ranges in between alphabets
		    printAllPossibleCodes(input.substr(2), output + ch);	// Recursive call considering 1st and 2nd index integer as code
    }
}
