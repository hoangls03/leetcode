class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> right;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( s[i] == ')' ) {
                right.push(i);
            } 
            if ( s[i] == '(' ) {
                int end = right.top();
                right.pop();
                reverse(s.begin()+i + 1,s.begin() + end);
            }
        }
        string ans = "";
        for ( auto i : s ) {
            if ( i != '(' && i != ')' ) {
                ans += i;
            }
        }
        return ans;
        
    }
};
