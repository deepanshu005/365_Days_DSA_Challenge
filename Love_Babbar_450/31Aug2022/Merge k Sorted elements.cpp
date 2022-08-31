// CPP DSA CN Lec 14
// Problem of Min Heap
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    vector<int>mergedArray;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i=0; i<input.size();i++)
    {
        for(int j=0;j<input[i]->size();j++)
        {
            minHeap.push(input[i]->at(j));
        }
    }
    
    while(!minHeap.empty())
    {
        mergedArray.push_back(minHeap.top());
        minHeap.pop();
    }
        
    return mergedArray;

}
