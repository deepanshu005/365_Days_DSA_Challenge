// CPP DSA Coding Ninjas Lecture-04
#include <string.h>
using namespace std;
int getCodes(string input, string output[]) {
	if(input[0] == '\0'){	//Base case 
		output[0] = "";
		return 1;
	}
	int first = input[0] - 48;
	char firstChar = first + 'a' - 1;
	char secondChar = '\0';
	string smallOutput1[500];
	string smallOutput2[500];
	int size1 = getCodes(input.substr(1), smallOutput1);	//Recursive call
	int size2 = 0;
	if(input[1] != '\0'){
		int second = first * 10 + input[1] - 48;
		if(second >= 10 && second <= 26){
			secondChar = second + 'a' - 1;
			size2 = getCodes(input.substr(2), smallOutput2);	//Recursive call
		}
	}
	int k = 0;
	for(int i = 0; i < size1; i++)
		output[k++] = firstChar + smallOutput1[i];

	for(int i = 0; i < size2; i++)
		output[k++] = secondChar + smallOutput2[i];
		
	return k;
}
