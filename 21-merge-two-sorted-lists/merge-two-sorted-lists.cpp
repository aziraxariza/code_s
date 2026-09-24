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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1; // agar koi ek exist nhi krta

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        while(temp1 && temp2){ // jab tak dono ke nodes hai
            if(temp1->val < temp2->val){ // jiski chhoti val usko next node liya
                ans->next = temp1;
                temp1 = temp1->next; // next node of temp pr jao
            }
            else{
                ans->next = temp2;
                temp2 = temp2->next;
            }
            ans = ans->next; // ans aage badho
        }

        if(temp1) ans->next = temp1; // jiske nodes bach gaye
        else ans->next = temp2;

        return dummy->next;
    }
};