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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* ans = head;
        int count = 0;
        int carry = 0;
        while ( l1 != NULL && l2 != NULL ) {
            ListNode* cur = new ListNode();
            cur -> val = l1 -> val + l2 -> val + carry;
            if ( cur -> val >= 10 ) {
                carry = 1;
                cur -> val -= 10;
            } else carry = 0;
            if ( count == 0 ) {
                head -> val = cur -> val;
            } else {
                head -> next = cur;
                head = head -> next;
            }
            count++;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while ( l1 != NULL ) {
            ListNode* cur = new ListNode();
            cur -> val = l1 -> val + carry;
            if ( cur -> val >= 10 ) {
                carry = 1;
                cur -> val -= 10;
            } else carry = 0;
            head -> next = cur;
            head = head -> next;
            l1 = l1 -> next;
        }
        while ( l2 != NULL ) {
            ListNode* cur = new ListNode();
            cur -> val = l2 -> val + carry;
            if ( cur -> val >= 10 ) {
                carry = 1;
                cur -> val -= 10;
            } else carry = 0;
            head -> next = cur;
            head = head -> next;
            l2 = l2 -> next;
        }
        if ( carry == 1 ) {
            ListNode* cur = new ListNode(1);
            head->next = cur;
        }
        return ans;
    }
};
