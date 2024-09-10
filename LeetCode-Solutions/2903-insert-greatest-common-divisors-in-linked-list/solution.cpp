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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = head;
        while ( head -> next != NULL ) {
            ListNode* cur = new ListNode(__gcd(head->val,head->next->val),head->next);
            ListNode* temp = head -> next;
            head -> next = cur;
            head = temp;
        }
        return ans;
    }
};
