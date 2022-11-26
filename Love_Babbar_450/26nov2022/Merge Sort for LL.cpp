// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void merge(vector<int> &v, int low, int mid, int high)
    {
        int len1 = mid - low + 1, len2 = high - mid;
        int left[len1], right[len2];
        for (int i = 0; i < len1; ++i)
            left[i] = v[i + low];
        for (int i = 0; i < len2; ++i)
            right[i] = v[mid + i + 1];
        int i = 0, j = 0, idx = low;
        while (i < len1 && j < len2)
        {
            if (left[i] <= right[j])
                v[idx++] = left[i++];
            else
                v[idx++] = right[j++];
        }
        while (i < len1)
            v[idx++] = left[i++];
        while (j < len2)
            v[idx++] = right[j++];
    }
    void mergeSortUtil(vector<int> &v, int low, int high)
    {
        if (high > low)
        {
            int mid = low + (high - low) / 2;
            mergeSortUtil(v, low, mid);
            mergeSortUtil(v, mid + 1, high);
            merge(v, low, mid, high);
        }
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        vector<int> v;
        Node *tmp = head;
        while(tmp != NULL) {
            v.push_back(tmp->data);
            tmp = tmp->next;
        }
        mergeSortUtil(v, 0, v.size()-1);
        tmp = head;
        int i = 0;
        while(tmp != NULL) {
            tmp->data = v[i];
            ++i;
            tmp = tmp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
