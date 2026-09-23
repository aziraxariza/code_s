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
        if (!list1) return list2;
        if (!list2) return list1; // koi ek exist nahi krti toh dusra return

        ListNode* ans =  NULL; // initialized null node

        ListNode* temp1 = list1; //temp1 and 2 with ptrs to resp list
        ListNode* temp2 = list2;

        if(list1->val < list2->val){ // jo chhoti woh starting node in ans
            ans = list1;
            temp1 = temp1->next; // aage badhaya le kar
        }
        else{
            ans = list2;
            temp2 = temp2->next;
        }
        ListNode* head = ans; // ans ptr ko head banaya

        while(temp1 && temp2){ //dono mein kuch hai

            if(temp1->val < temp2->val){ // jo chhota woh pehle
                ans->next = temp1; // ab ye aayega
                temp1 = temp1->next; //aage badhao
                ans = ans->next; // aage badhao
            }
            else{
                ans->next = temp2;
                temp2 = temp2->next;
                ans = ans->next;
            }
        }
        if(temp1) ans->next = temp1;// agar kisiki nodes bach gayi toh ek ptr se sari attach ho jayengi
        if(temp2) ans->next = temp2;

        return head; //ptr to ans ka start
    }
};