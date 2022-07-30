// CPP DSA CN Lec-04
/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
*/
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){

	if(input.length()==0){
        output[0]="";	//Base case
    	return 1;
    }
    string smallout[10000];
    int smallsize= returnPermutations(input.substr(1),smallout);
    int k=0;
    for(int i=0;i<smallsize;i++)	// Inserting input[0] in the whole string array at every place
    	for(int j=0;j<=smallout[i].length();j++)// here j loop is running one more time because in every string having n characters there are n+1 places for a new character to be inserted
            output[k++]=smallout[i].substr(0,j)+input[0]+smallout[i].substr(j);
    return k; // returning the total anteries in output string array
    
}
