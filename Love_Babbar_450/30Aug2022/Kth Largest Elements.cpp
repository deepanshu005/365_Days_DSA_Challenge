//CPP DSA CN Lec 14
#include<queue>
int kthLargest(int arr[], int n, int k) {
	priority_queue< int, vector<int>, greater<int> > pq;
    for(int i=0; i<k; i++)
        pq.push(arr[i]);
    
    for(int i=k; i<n; i++){
        if(pq.top()<arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    int i=0;
    int input[k];
    while(!pq.empty()){
        input[i] = pq.top();
        pq.pop();
        i++;
    }
    return input[0];
}
