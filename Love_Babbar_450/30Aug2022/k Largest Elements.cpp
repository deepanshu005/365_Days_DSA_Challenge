// CPP DSA CN Lec 14
/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
#include<queue>
#include<vector>
vector<int> kLargest(int arr[], int n, int k) {
	priority_queue< int, vector<int>, greater<int> > pq;
    vector<int> v;
    for(int i=0; i<k; i++)
        pq.push(arr[i]);
    
    for(int i=k; i<n; i++){
        if(pq.top()<arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int i=0;
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}
