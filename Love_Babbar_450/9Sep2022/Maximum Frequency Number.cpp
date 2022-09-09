//CPP DSA CN Lec 15
#include<unordered_map>
/*
int highestFrequency(int arr[], int n) {
    unordered_map<int, int> freq;
    int max_count=0, res= -1;
    for(int i=n-1; i>=0; i--){
        freq[arr[i]]++;
    
            if(max_count <= freq[arr[i]]){
                res = arr[i];
                max_count = freq[arr[i]];
            }
        }
    return res;
        
}
*/
// Both methods are correct
#include <unordered_map> 
int highestFrequency(int arr[], int n) { 
    unordered_map<int, int> freq; 
    int maxFreq = 0; 
    for (int i = 0; i < n; i++) { 
        freq[arr[i]]++; 
        maxFreq = max(maxFreq, freq[arr[i]]); 
    }
    int maxFreqElement; 
    for (int i = 0; i < n; ++i) { 
        if (freq[arr[i]] == maxFreq) {
            maxFreqElement = arr[i];
            break; 
        }
    } 
    return maxFreqElement; 
}
