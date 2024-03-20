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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list2;
        while ( temp -> next != NULL ) {
            temp = temp -> next;
        }    
        ListNode* start = NULL;
        ListNode* end = NULL;
        int dem = 0;
        ListNode* head = list1;
        while ( head != NULL ) {
            if ( dem == a - 1 ) {
                start = head;
            }
            if ( dem == b + 1 ) {
                end = head;
            }
            head = head -> next;
            dem++;
        }
        start -> next = list2;
        temp -> next = end;
        return list1;
    }
};
