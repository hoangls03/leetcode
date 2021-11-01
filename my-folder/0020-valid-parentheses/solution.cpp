class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        bool check = true;
        for ( int i = 0 ; i < s.size() && check ; ++i )
        {
            if( s[i] != ')' && s[i] != ']' && s[i] != '}' )
            {
                q.push(s[i]);
            }
            else
            {
                if ( q.empty() )
                {
                    check = false;
                }
                else
                {
                    char ch = q.top();
                    if ( s[i] == ')' )
                    {
                        if ( ch != '(' ) check = false;
                        else q.pop();
                    }
                    if ( s[i] == ']' )
                    {
                        if ( ch != '[' ) check = false;
                        else q.pop();
                    }
                    if ( s[i] == '}' )
                    {
                        if ( ch != '{' ) check = false;
                        else q.pop();
                    }
                }
            }
        }
        if ( q.size() || !check ) return false;
        else return true;
    }
};
