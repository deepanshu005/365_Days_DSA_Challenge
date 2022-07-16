// Coding ninjas Test 2 from cpp introduction question number 2
#include<cstring>
/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/
void minLengthWord(char input[], char output[]){
	int count=0;	//this will count the length of string
	int k = strlen(input);
	int MinLength = k;	// This consists of least length of substring and initially we are assuming it to be max i.e., length of input array
    int MinIndex = 0; 	// This consists of starting index odf min string
    
    for( int i=0; i<k; ){	//This helps in traversing the whole input array
		int j=i;
        count = 0;
        while( input[j] != ' ' && j<k ){	// j will move on untill it found any space and restricted the length of input array
			count++;
            j++;
        }
        if( count<MinLength ){
            MinIndex = i;
            MinLength = count;
        }
    	i+=count +1;	// Jumping the i by count number of iterations
    }
    for( int i=0; i<MinLength; i++ ){	//coping min string to output array
        output[i] = input[MinIndex++];
    }
    
}
