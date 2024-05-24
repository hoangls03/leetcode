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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        map<int,int> mp;
        mp.clear();
        while ( head != NULL ) {
            mp[n] = head -> val;
            n++;
            head = head -> next;
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mp[i] != mp[n-i-1] ) return false;
        }
        return true;
    }
};
