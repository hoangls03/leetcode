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
    bool check(int pre, int current, int next ) {
        if ( ( current > pre && current > next ) || ( current < pre && current < next ) ) return true;
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = -1;
        int current = -1;
        int next = -1;
        int pre_point = -1;
        int pos = 0;
        int min_point = -1;
        int min_dis = 1e6;
        while ( head != NULL ) {
            prev = current;
            current = next;
            next = head -> val;
            if ( prev != -1 && check(prev,current,next) ) {
                if ( pre_point != -1 ) {
                    min_dis = min(min_dis,pos-pre_point);
                    pre_point = pos;
                } else {
                    pre_point = pos;
                    min_point = pos;
                }
            }
            pos++;
            head = head->next;
        }
        if ( min_dis == 1e6 ) return {-1,-1};
        return {min_dis,pre_point-min_point};
    }
};
