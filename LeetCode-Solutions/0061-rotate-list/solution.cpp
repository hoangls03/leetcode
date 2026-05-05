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
        ListNode* tempHead= head;
        int n = 0;
        while ( tempHead != NULL ) {
            n++;
            tempHead = tempHead -> next;
        }
        if ( n == 0 ) {
            return head;
        }
        k %= n;
        int m = n - k;
        tempHead = head;
        n = 0;
        ListNode* ans = new ListNode();
        ListNode* res = ans;
        while ( tempHead != NULL ) {
            n++;
            if ( n > m ) {
                ans->next = tempHead;
                ans = ans -> next;
            }
            tempHead = tempHead -> next;
        }
        tempHead = head;
        n = 0;
        while ( tempHead != NULL ) {
            n++;
            if ( n <= m ) {
                ans->next = new ListNode(tempHead -> val);
                ans = ans -> next;
            }
            tempHead = tempHead -> next;
        }
        return res -> next;
    }
};
