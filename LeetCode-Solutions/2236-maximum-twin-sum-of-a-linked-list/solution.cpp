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
    int pairSum(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        while ( cur != NULL ) {
            ListNode* next = cur -> next;
            ListNode* newCur = new ListNode(cur->val,prev);
            prev = newCur;
            cur = next;
        }
        cur = prev;
        int ans = 0;
        while ( cur != NULL ) {
            ans = max(ans,cur -> val + head -> val);
            cur = cur -> next;
            head = head-> next;
        }
        return ans;
    }
};
