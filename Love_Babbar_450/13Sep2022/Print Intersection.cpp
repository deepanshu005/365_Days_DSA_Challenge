//CPP DSA CN Lec 15 Love Babbar 450
#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int,int> inter;
    for(int i=0; i<n; i++){
        inter[arr1[i]]++;
    }
    for(int i=0; i<m; i++){
        if(inter[arr2[i]] > 0){
            cout<<arr2[i]<<"\n";
            inter[arr2[i]]--;
        }
    }
}
    
