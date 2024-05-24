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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while ( temp != NULL ) {
            while ( st.size() && temp->val > st.top()->val ) {
                st.pop();
            }
            st.push(temp);
            temp = temp -> next;
        }
        ListNode* curr;
        ListNode* nxt = NULL;
        while ( st.size() ) {
            curr = st.top();
            st.pop();
            curr->next = nxt;
            nxt = curr;
        }
        return curr;
    }
};
