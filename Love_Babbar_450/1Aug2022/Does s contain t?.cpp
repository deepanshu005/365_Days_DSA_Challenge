//CPP DSA CN Test 1
bool checksequenece(char large[] , char* small) {
	if( small[0] == '\0' )	// Base case
        return true;
    if( large[0] == '\0' )	// Base Case
        return false;
   
    if( large[0]==small[0] )
        return  checksequenece( large+1 , small+1) ;	// If character matched then shifting both pointers to the next 
    else 
        return  checksequenece( large+1 , small) ;	// Else if nnot matched then shifting only the pointer of large char array
    
}
