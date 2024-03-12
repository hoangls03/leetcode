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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*> mp;
        mp.clear();
        int sum = 0;
        ListNode *temp_node = new ListNode(0);
        mp[0] = temp_node;
        temp_node -> next = head;
        while ( head != NULL ) {
            sum += head -> val;
            if ( mp[sum] != NULL ) {
                ListNode* start = mp[sum];
                ListNode* temp = start;
                int psum = sum;
                while ( temp != head ) {
                    temp = temp -> next;
                    psum += temp -> val;
                    if ( temp != head ) {
                        mp[psum] = NULL;
                    }
                    start -> next = head -> next;
                }
            }
            else mp[sum] = head;
            head = head -> next;

        }
        return temp_node->next;
    }
};
