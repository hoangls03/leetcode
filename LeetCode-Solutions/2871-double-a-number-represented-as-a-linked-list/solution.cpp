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
    ListNode* doubleIt(ListNode* head) {
        long long val = 0;
        ListNode* temp = head;
        stack<int> st;
        while ( temp != NULL ) {
            st.push(temp->val);
            temp = temp->next; 
        }
        ListNode* nxt = NULL;
        ListNode* curr = head;
        int add = 0;
        while ( st.size() ) {
            val = st.top()*2 + add;
            if ( val >= 10 ) {
                add = 1;
            } else {
                add = 0;
            }
            val = val%10;
            curr = new ListNode(val);
            st.pop();
            curr->next = nxt;
            nxt = curr;
        }
        if ( add == 1 ) {
            curr = new ListNode(1);
            curr->next = nxt;
        }
        return curr;
    }
};
