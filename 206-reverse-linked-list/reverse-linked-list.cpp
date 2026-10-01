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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head; // curr node
        ListNode* prev = NULL; // peeche wala kaun

        while(curr){
            ListNode* nxt = curr->next; // next kaun hai og

            curr->next = prev; // peeche wala ab next
            prev = curr; // new prev is curr

            curr = nxt; // move curr frwrd in og
        }
        return prev;
    }
};