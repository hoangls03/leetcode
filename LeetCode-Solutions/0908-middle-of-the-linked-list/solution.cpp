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
        ListNode* temp = head;
        ListNode* ans = head;
        int left = 0;
        int right = 0;
        while ( temp != NULL ) {
            if ( right - left >= 1 ) {
                ans = ans -> next;
                left++;
                right--;
            }
            temp = temp -> next;
            right++;       
        }
        return ans;
    }
};
