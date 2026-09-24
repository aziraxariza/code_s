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
        if(!head || !head->next) return NULL;

        ListNode* slow = head; 
        ListNode* fast = head;

        while(fast && fast->next){ //***
            slow = slow->next; // 1step
            fast = fast->next->next; // 2steps

            if(slow == fast){
                ListNode* temp = head;

                while(temp != slow){ //**
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};