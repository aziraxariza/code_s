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
    
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a -> val > b -> val; // min heap condition
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(ListNode* head : lists){ // har ek list traverse in lists
            if(head){ // for all not null values
                pq.push(head); // min heap mein dala
            }
        }

        ListNode* ans = new ListNode(-1); // ans list empty
        ListNode* curr = ans; // ye node pointing to ans beginning

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;// next par gaye
            curr = node;    

            if(node -> next){
                pq.push(node -> next);
            }
        }
        return ans -> next;

    }
};
    

    /* BRUTE FORCE 
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> nums;

        for(ListNode* head : lists){   // Store all values
            while(head){ 
                nums.push_back(head->val);
                head = head->next;
            }
        }

        sort(nums.begin(), nums.end()); // Sort all values

        ListNode* dummy = new ListNode(-1); // Create new linked list
        ListNode* curr = dummy;

        for(int x : nums){
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return dummy->next;
        O(nlogn) T.C  */
