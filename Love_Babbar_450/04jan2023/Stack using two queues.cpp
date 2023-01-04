// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x){
    q1.push(x);// always q1 will be empty and we insert new element in q1 
    while( !q2.empty() ){// now insreting all elments of q2 in q1
        q1.push(q2.front());
        q2.pop();
    }// at the end q2 becomes empty
    swap(q1,q2);// swapping q1 and q2
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop(){
    if( q2.empty() )
        return -1;
    int k = q2.front();
    q2.pop();
    return k;
}
