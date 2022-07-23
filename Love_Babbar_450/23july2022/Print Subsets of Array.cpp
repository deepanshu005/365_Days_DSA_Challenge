
// CPP DSA Lecture 4

void helper(int input[], int size, int output[], int n){
    if (size == 0){	// Base case 
        for (int i = 0; i < n; i++)
            cout << output[i] << " ";
        cout << endl;
        return;
    }

    helper(input + 1, size - 1, output, n);
    // assuming current elemnet is included in array
    int newoutput[20] = {};
    
    for (int i = 0; i<n; i++)
        newoutput[i] = output[i];	//Copying the output array to the new array just to add new element at the end bco the size of output array is fixed and we cannt add anyelement to it
    
    newoutput[n] = input[0];	// Adding new element to new array
    helper(input + 1, size - 1, newoutput, n + 1);
}

void printSubsetsOfArray(int input[], int size){
    int ans[20] = {};
    helper(input, size, ans, 0);
}
