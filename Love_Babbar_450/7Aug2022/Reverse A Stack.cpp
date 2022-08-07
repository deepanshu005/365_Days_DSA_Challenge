// CPP DSA CN Lec 10
// Actually we need three satcks to solve rthis problem 1st is the final stack and other twos are helper stacks
// here we have giuven only one extra stack hence we will use recursion to get the thirs stack , since recursion is the application of stack
void reverseStack(stack<int> &input, stack<int> &extra) {
	if( input.empty() )	// if the given stack is empty or the stack become empty after  pops
        return ;
    int LastElement = input.top();
    input.pop();
    reverseStack( input, extra );// storing and poping the top most element for future use and making recursive call after each pop
    
    while( !input.empty() ){	// transfering all the elements from input to eaxtra at each recursive step
        int top = input.top();
        input.pop();
        extra.push(top);
    }
    extra.push(LastElement);
    while( !extra.empty() ){	// transefering all elements from extra to input at each recursive step
        int top = extra.top();
        extra.pop();
        input.push(top);
    }
}
