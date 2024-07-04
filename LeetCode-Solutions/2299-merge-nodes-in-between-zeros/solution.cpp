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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = NULL;
        int sum = 0;
        ListNode* ans_head = NULL;
        while ( head != NULL ) {
            sum += head->val;
            if ( head->val == 0 ) {
                if ( sum != 0 ) {
                    if ( ans == NULL ) {
                        ans = new ListNode();
                        ans->val = sum;
                        ans_head = ans;
                    }
                    else {
                        ListNode* node = new ListNode();
                        node->val = sum;
                        ans->next = node;
                        ans = ans->next;
                    } 
                } 
                sum = 0;

            }
            head = head -> next;
        }
        return ans_head;
    }
};
