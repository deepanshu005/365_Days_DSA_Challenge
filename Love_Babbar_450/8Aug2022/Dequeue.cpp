// CPP DSA CN Test 2
/**********
 
 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.
 
 
 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }
 
 return 0;
 }
 
 ************/

#define MAX 100
class Deque
{
    int  arr[MAX];
    int  front;
    int  rear;
    int  size;
public :
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }
 
    // Operations on Deque:
    void  insertFront(int key);
    void  insertRear(int key);
    void  deleteFront();
    void  deleteRear();
    bool  isFull();
    bool  isEmpty();
    int  getFront();
    int  getRear();
};
 
// Checks whether Deque is full or not.
bool Deque::isFull()
{
    return ((front == 0 && rear == size-1)||
            front == rear+1);
}
 
// Checks whether Deque is empty or not.
bool Deque::isEmpty ()
{
    return (front == -1);
}
 
// Inserts an element at front
void Deque::insertFront(int key)
{
    // check whether Deque if  full or not
    if (isFull())
    {
        cout<<"-1"<<endl;
        return ;
    }
 
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
 
    // front is at first position of queue
    else if (front == 0)
        front = size - 1 ;
 
    else // decrement front end by '1'
        front = front-1;
 
    // insert current element into Deque
    arr[front] = key ;
}
 
// function to inset element at rear end
// of Deque.
void Deque ::insertRear(int key)
{
    if (isFull())
    {
        cout << "-1" << endl;
        return;
    }
 
    // If queue is initially empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
 
    // rear is at last position of queue
    else if (rear == size-1)
        rear = 0;
 
    // increment rear end by '1'
    else
        rear = rear+1;
 
    // insert current element into Deque
    arr[rear] = key ;
}
 
// Deletes element at front end of Deque
void Deque ::deleteFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        cout << "-1" << endl;
        return ;
    }
 
    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        // back to initial position
        if (front == size -1)
            front = 0;
 
        else // increment front by '1' to remove current
            // front value from Deque
            front = front+1;
}
 
// Delete element at rear end of Deque
void Deque::deleteRear()
{
    if (isEmpty())
    {
        cout << "-1" << endl ;
        return ;
    }
 
    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = size-1;
    else
        rear = rear-1;
}
 
// Returns front element of Deque
int Deque::getFront()
{
    // check whether Deque is empty or not
    if (isEmpty())
    {
        
        return -1 ;
    }
    return arr[front];
}
 
// function return rear element of Deque
int Deque::getRear()
{
    // check whether Deque is empty or not
    if(isEmpty() || rear < 0)
    {
        return -1 ;
    }
    return arr[rear];
 }
    
