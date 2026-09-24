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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || !k)
            return head;

        vector<ListNode*> temp;
        ListNode* res = head;

        while (res) {
            temp.push_back(res);
            res = res->next;
        }

        rotate(temp, k);

        for (int i = 0; i < temp.size() - 1; i++)
            temp[i]->next = temp[i + 1];

        temp.back()->next = nullptr;

        return temp.front();
    }

    void rotate(vector<ListNode*>& ar, int k) {
        int n = ar.size();
        k %= n;

        reverse(ar.begin(), ar.end()); // right rotate
        reverse(ar.begin(), ar.begin() + k);
        reverse(ar.begin() + k, ar.end());
    }
};