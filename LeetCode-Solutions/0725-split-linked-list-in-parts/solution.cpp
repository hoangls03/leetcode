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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* node = head;
        int n = 0;
        while ( node != NULL ) {
            n++;
            node = node -> next;
        }
        int size = n/k;
        int num = n%k;
        vector<ListNode*> ans;
        ListNode* temp = head;
        n = 0;
        int part = 1;
        while ( head != NULL ) {
            n++;
            ListNode* cur = head->next;
            if ( n == size + (part <= num) ) {
                n = 0;
                head -> next = NULL;
                ans.push_back(temp);
                part++;
                temp = cur;
            }
            head = cur;
        }   
        temp = NULL;
        while ( ans.size() < k ) {
            ans.push_back(temp);
        }
        return ans;
    }
};
