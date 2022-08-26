// CPP DSA CN Lec 14
#include<vector>
/*
class PriorityQueue {
    vector <int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }
    /**************** Implement all the public functions here ***************
    void insert(int element) {
        pq.push_back(element);
        int CI = pq.size()-1;
        while( CI>0 ){
            int PI = (CI-1)/2;
            if( pq[CI]>pq[PI]){
                int temp = pq[CI];
                pq[CI] = pq[PI];
                pq[PI] = temp;
            }
            else	break;
        CI = PI;
        }
    }
    int getMax() {
        if( isEmpty())		return 0;
        return pq[0];
    }
    int removeMax() {
        if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// down-heapify

		int PI = 0;
		int LCI = 2 * PI + 1;
		int RCI = 2 * PI + 2;
	
		while( LCI < pq.size()) {
			int MaxIndex = PI;
			if(pq[MaxIndex] < pq[LCI]) {
				MaxIndex = LCI;
			}
			if( RCI > pq.size() && pq[RCI] > pq[MaxIndex]) {
				MaxIndex = RCI;
			}
			if(MaxIndex == PI) {
				break;
			}
			int temp = pq[MaxIndex];
			pq[MaxIndex] = pq[PI];
			pq[PI] = temp;
		
			PI = MaxIndex;
			LCI = 2 * PI + 1;
			RCI = 2 * PI + 2;
		}
		return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size()==0;
    }
};

#include <vector>

/*******************
 * Main function -
*
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMin
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}

*/

class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMax() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] > pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMax() {
        // Complete this function
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int pi=0;
        int leftchildindex=2*pi+1;
       int rightchildindex=2*pi+2;
        while(leftchildindex<pq.size())
        {
            int maxindex=pi;
            
            if(pq[maxindex]<pq[leftchildindex])
            {
                maxindex=leftchildindex;
                
            }
            if(rightchildindex<pq.size()&&pq[maxindex]<pq[rightchildindex])
            {
                maxindex=rightchildindex;
            }
            if(maxindex==pi)
            {
                break;
            }
            swap(pq[maxindex],pq[pi]);
            pi=maxindex;
            leftchildindex=2*pi+1;
                    rightchildindex=2*pi+2;

        }
        return ans;
    }
};
