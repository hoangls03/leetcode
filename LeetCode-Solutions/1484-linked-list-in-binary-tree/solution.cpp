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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    void travel(ListNode* head, TreeNode* root, ListNode*temp, bool& ans ) {
        if ( root == NULL ) return ;
        if ( temp != head ) {

        }
        if ( root -> val != temp -> val ) {
            temp = head;
        } else {
            temp = temp -> next;
        }
        if ( temp == NULL ) {
            ans = true;
            return ;
        }
        
        travel(head,root->left,temp,ans);
        travel(head,root->right,temp,ans);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        bool ans = false;
        if ( root == NULL ) return false;
        if ( root -> val == head -> val ) {
            travel(head,root,head,ans);
            if ( ans ) return ans;
        }
        bool l = isSubPath(head,root->left);
        if ( l ) return l;
        bool r = isSubPath(head,root->right);
        if ( r ) return r;
        return false;
    }
};
