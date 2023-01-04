// CPP DSA Love Babbar 450
//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}

// } Driver Code Ends


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x){
    while( !s1.empty() ){// s1 ko khaaali krke hi x ko push krenge taaki x hamesha bottom m hi pahunche
        s2.push(s1.top());// and jb pop krenge to s1 se hi krenge taaki jo sbse phle element dla tha wo phle aaye
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return;
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop(){
    int k = -1;
    if(!s1.empty()){
        k=s1.top();
        s1.pop();
    }
    return k;
}
