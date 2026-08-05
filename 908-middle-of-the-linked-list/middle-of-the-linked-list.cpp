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
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        while(temp){
            n++;
            temp = temp->next;
        }

        int p = n / 2 + 1;  // mid point

        temp = head;
        int k = 1;

        while(k < p){
            temp = temp->next;
            k++;
        }
        return temp; //yaha se n wale nodes shuru
    }
        
};