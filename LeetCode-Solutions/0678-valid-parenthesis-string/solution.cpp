class Solution {
public:
    bool checkValidString(string s) {
        int count_right = 0;
        stack<int> count_left;
        deque<int> count_star;
        for ( int i = 0 ; i < s.size() ; ++i ) {
            char ch = s[i];
            if ( ch == ')' ) {
                if ( count_left.empty() && count_star.empty() ) return false;
                if ( count_left.empty() ) {
                    count_star.pop_front();
                }  else {
                    count_left.pop();
                }
            }
            if ( ch == '(' ) count_left.push(i);
            if ( ch == '*' ) count_star.push_back(i);
        }
        while ( count_left.size() ) {
            if ( count_star.empty() ) return false;
            int pos_left = count_left.top();
            int pos_star = count_star.back();
            if ( pos_left > pos_star ) return false;
            count_left.pop();
            count_star.pop_back();
        }
        return true;
    }
};
