// CPP DSA Cn Lec-04
/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
*/
// Top Down Approach
void Helper(string input, string output){
    if(input.length() == 0){	// Base case
        cout << output << endl;
        return;
    }
    for(int i = 0; i<= output.length(); i++)
    	Helper(input.substr(1), output.substr(0,i) + input[0] + output.substr(i));	// Adding input[0] in each output array
}
void printPermutations(string input){
    Helper(input, ""); 
    return; 
}
