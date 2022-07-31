// CPP DSA CN Lec-5
// Using XOR bitwise operator approach
// XOR gate results zero only if both inputs are same
// a^a=0
int findUnique(int *arr, int n) {
    int x=0;
    for( int i=0; i<n; i++ )	// Since a^a = 0 and a^0 = a
        x = x^arr[i]; 	// Since XOR operator is Associative in nature hense after the traversal of whole array it will just contain the unique element whereas ll the same elements with becomes zero with XOR operator
    
    return x;
}
