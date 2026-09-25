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
        ListNode* curr = head;
        ListNode* prev = NULL; // curr aur prev 2 nodes lo

        while(curr){
            ListNode* nxt = curr->next; // save og next of curr

            curr->next = prev; // peeche wala ab next 
            prev = curr; // ab peeche wala curr hai

            curr = nxt; // curr ab apna og curr ka next hai
        }
        return prev;
    }
};