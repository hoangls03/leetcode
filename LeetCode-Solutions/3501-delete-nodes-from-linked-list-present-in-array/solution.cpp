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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* ans = NULL;
        ListNode* current = NULL;
        map<int,int> mp;
        mp.clear();
        for ( auto i : nums ) {
            mp[i]++;
        }
        while ( head != NULL ) {
            if ( mp[head->val] == 0 ) {
                ListNode* temp = new ListNode;
                temp->val = head->val;
                if ( ans == NULL ) {
                    current = temp;
                    ans = current;
                } else {
                    current->next = temp;
                    current = current->next;
                    current->next = NULL;
                }
            }
            head = head -> next;
        }
        return ans;
    }
};
