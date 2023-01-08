// CPP DSA Love Babbar 450
#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    queue<int> q1, q2;
 
    int n = q.size();
 
    // Inserting first half in q1
    for (int i = 0; i < n / 2; i++) {
        q1.push(q.front());
        q.pop();
    }
 
    // inserting second half in q2
    for (int i = 0; i < n / 2; i++) {
        q2.push(q.front());
        q.pop();
    }
    // Insert elements of q1 and q2 back
    // to q in alternate order.
    for (int i = 0; i < n/2; i++) {
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
    return;
}
