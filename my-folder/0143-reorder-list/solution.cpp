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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while ( temp != NULL ) {
            st.push(temp);
            temp = temp -> next;
        }
        int n = st.size();
        temp = head;
        while ( temp != NULL ) {
            ListNode* link = NULL;
            if (st.size() ) {

            link = st.top();
            st.pop();
            
            }
            ListNode* run = temp -> next;
            //cout<<link->val<<" "<<temp->val<<" "<<" "<<run->val<<" "<<st.size()<<'\n';
            if ( link == temp || st.size() < n/2 ) {
                temp -> next = NULL;
                break;
            }
            else {
                temp -> next = link;
                link -> next = run;
            } 
            temp = run;
        }
    }
};
