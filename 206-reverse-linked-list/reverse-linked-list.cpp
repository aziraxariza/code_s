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
        ListNode* curr = head; // curr head se start
        ListNode* prev = NULL; // prev initially null hai

        while(curr){ // jab tak node hai
            ListNode* nxt = curr -> next; // nxt nikala
            curr -> next = prev; // prev ko next banaya

            prev = curr; // curr ab prev ban gaya
            curr = nxt; // curr ka next ab curr ban gaya
        }
        return prev; // prev curr hai isliye head wahi
    }
};