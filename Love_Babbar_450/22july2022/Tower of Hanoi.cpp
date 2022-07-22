// Coding ninjas DSA lecture 3
void towerOfHanoi(int n, char a, char b, char c) {  //a is source, b is helper , and c is destination
    if(n>0){	//Recursion chlta rhega jb tk source ya fir auxilliary m rings bchi hui h
        towerOfHanoi( n-1, a, c, b);	// Moving all n-1 rings from source to auxiiliary except the last one that is nth ring in source
        cout<<a<<" "<<c<<endl;	//Moving nth ring frm source to destination 
        towerOfHanoi( n-1, b, a, c);	// Now moving all the rings i.e, n-1 rings in auxilliary from auxilliary to destination 
    }
}
