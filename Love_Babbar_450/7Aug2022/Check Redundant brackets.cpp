// CPP DSA CN Lec 10
#include<iostream>
#include<stack>
bool checkRedundantBrackets(string str) {
	stack<char> s;
    int i=0;
    while( str[i]!='\0' ){
        s.push(str[i]);	// Inserting elements in the stack until we get ')'
    	if( str[i]==')'){	// As we get ')' running a while loop on stack until we get '(' and counting chars between '(' and ')' if count is less than equal to 1 means it holds something unuseful hence we return true
            int count = 0;
            s.pop();	// poping this ')' which was inserted in above step (just below the first while loo)p
            while( s.top()!='(' ){
                s.pop();
                count++;
            }
            if( count<=1 ){
                return true;
            }
            s.pop();
        }
			i++;    
    }
    /*if( !s.empty() )// if stack becomes empty means all the braes were useful hence returning false
        return false;*/
    return false;    
}
