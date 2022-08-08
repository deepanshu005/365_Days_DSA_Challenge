// CPP DSA CN Lec 10
#include <stack> 
int countBracketReversals(string input) { 
    int len = input.length(); 
    if (len == 0) {
        return 0;
    } 
    if (len % 2 != 0) {
        return -1;
        // Only even number of brackets can be balanced 
    }
    stack<char> stack;
    for (int i = 0; i < len; i++) { 
        char currentChar = input[i];
        if (currentChar == '{') {
            stack.push(currentChar);
        }
        else {
            // Pop if there is a balanced pair 
            if (!stack.empty() && stack.top() == '{') {
                stack.pop(); } 
            else { stack.push(currentChar); 
                 }
        }
    }
    int count = 0; // Only unbalanced brackets are there in stack now 
    while (!stack.empty()) {
        char char1 = stack.top();
        stack.pop();
        char char2 = stack.top(); 
        stack.pop(); /* When char1 = } and char2 = {, then we need to reverse both of them so count will increase by 2 */ 
        if (char1 != char2) { 
            count += 2; 
        } else { 
            count += 1; 
        } 
    }
    return count; 
}
            
        
