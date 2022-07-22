// DSA Lecture 4
bool checkAB(char input[]) {
	if( input[0]=='\0' )	//Base case
    	return true;
    if( input[0]!='a' )//If element at 0th index is b after 2 consecutive b's which is taken care by below recursive call
        return false;
	//THe code will come to this point only if input[0]=='a'
    if( input[1]=='b' && input[2]=='b' )
        return checkAB(input+3);//Recursive call whenever there are two consecutive b's after an a at 0th index
    else
        return checkAB(input+1);
}



