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
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int x = 0;
        int y = 0;
        ans[0][0] = head -> val;
        head = head -> next;
        int pos = 0;
        while ( head != NULL ) {
            int u = x + dx[pos];
            int v = y + dy[pos];
            if ( u < m && v < n && u >= 0 && v >= 0 && ans[u][v] == -1 ) {
                ans[u][v] = head -> val;
            } else {
                pos = ( pos + 1 )%4;
                u = x + dx[pos];
                v = y + dy[pos];
                ans[u][v] = head -> val;
            }
            x = u;
            y = v;
            head = head -> next;
        }
        return ans;
    }
};
