// CPP DSA CN Lec 10
// Aaj ka stock price kitne consecutive previos prices se jyaada h including aaj itself, this is called span of stock for that day
#include <stack> 
int *stockSpan(int *price, int n) {
	stack<int> stk;
	int *output = new int[n]; 
	stk.push(0);
	output[0] = 1;
	for (int i = 1; i < n; i++) {
    	while ( !stk.empty() && price[stk.top()] < price[i])
        	stk.pop(); 
    	if (stk.empty())
        	output[i] = i + 1;	// +1 for the day ityself
    	else
        	output[i] = i - stk.top();
    	stk.push(i); // Inserting index in the stack
	}
	return output; 
}





