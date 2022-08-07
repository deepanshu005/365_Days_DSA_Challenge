// CPP DSA CN Lec 10
// Indirectly we are are using stack to reverse the queue
// because recursion is itself the application of stack
// we can do these questions with the help of arrays but according to the queston we are restricted to do so
#include<queue>
void reverseQueue(queue<int> &input) {
	if( input.empty() )
        return;
    int top = input.front();
    input.pop();
    reverseQueue(input);	// storing all the elements of queue in the recursion stack 
    input.push(top);	// now insrting element in the queue one by one 
}
