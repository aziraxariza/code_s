/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // edge cases
        
        stack<ListNode*> st; 

        ListNode* temp = head; // pehle sabko stack mein dalo fir n/2 times peeche ke one by one normal nodes ke baad add 

        int n = 0; // total nodes
        while(temp){
            st.push(temp);
            n++;
            temp = temp->next;
        }

        ListNode* curr = head;

        for(int i = 0; i < n/2; i++){
            ListNode* back = st.top();
            st.pop();

            ListNode* front = curr->next;

            curr->next = back;
            back->next = front;

            curr = front;
        }
        curr->next = NULL; // last node
    }
};