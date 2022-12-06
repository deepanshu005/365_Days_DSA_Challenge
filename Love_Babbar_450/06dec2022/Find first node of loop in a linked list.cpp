// CPP DSA Love Babbar 450
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if( !head or !head->next )
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast and fast->next ){
            slow = slow->next;
            fast = fast->next->next;
            if( slow==fast )
                break;
        }
        if( !fast or !fast->next )
            return NULL;
        fast = head;
        while( fast!=slow ){// yha tak tbhi aayega jb loop exist kr rhi
        // Now if cycle exists
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
