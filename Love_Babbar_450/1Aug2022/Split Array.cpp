// CPP DSA CN Test 1
bool splitArray(int *input, int size, int start=0, int ls=0, int rs=0 ){
    if(start==size)	// Base case
    	return ls==rs;	// Return true if ls==rs else false
    if(input[start]%5==0)
        ls+=input[start];	// ls will maintain  the sum of numbers divisible by 5
    else if(input[start]%3==0)
        rs+=input[start];	// rs will maintain  the sum of numbers divisible by 3 but not 5
    else{	// if number is neither divisible by 5 nor 3
        bool lans=splitArray( input, size, start+1, ls+input[start], rs);
        bool rans=splitArray( input, size, start+1, ls, rs+input[start]);
        return lans||rans;	//returns the results on the basis of truth table of OR gate
    } 
    return splitArray( input, size, start+1, ls, rs);
}
