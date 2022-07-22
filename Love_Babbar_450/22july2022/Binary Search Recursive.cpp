// DSA Lecture 4
// input - input array
// size - length of input array
// element - value to be searched
int bin(int input[], int s, int e,int element)
{
	if(e<s)		// Base case, 
        return -1;
    
    int mid=(s+e)/2;
    if(input[mid]==element)	//If element is present at middle index
        return mid;
    
    if(element<input[mid])
        return bin(input, s,mid-1,element);
    // Here each time we are excluding middle lement hence in base case equality shouldnt be there
    //If we include middle element then in base case then equality must be there
    return bin(input, mid+1,e,element);
    
}
int binarySearch(int input[], int size, int element) {
    
	return bin(input,0,size-1,element);
}
