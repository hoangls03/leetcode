class Solution {
public:
    string countOfAtoms(string s) {
        int status = 0;
        stack<long long> st;
        int n = s.size();
        string temp = "";
        long long num = 1;
        string ans = "";
        vector<string> list;
        map<string,int> mark;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( s[i] >= '0' && s[i] <= '9' ) {
                status = 2;
                temp += s[i];
            } else if ( s[i] == ')' ) {
                num = 0;
                for ( int j = temp.size() - 1; j >= 0 ; --j ) {
                    num = num*10 + (temp[j] - '0');
                }
                num = max(num,1LL);
                st.push(num);
                num = 1;
                temp = "";
            } else if ( s[i] == '(' ) {
                st.pop();
            } else {
                num = 0;
                
                for ( int j = temp.size() - 1 ; j >= 0 ; --j ) {
                    num = num*10+temp[j]-'0';
                }
                num = max(num,1LL);
                if ( st.size() ) {
                    stack<long long> temp_st = st;
                    while ( temp_st.size() ) {
                        num *= temp_st.top();
                        temp_st.pop();
                    }
                }
                
                if ( s[i] >= 'a' && s[i] <= 'z' ) {
                    status = 1;
                    temp = s[i-1];
                    temp += s[i];
                    i--;
                } else {
                    temp = s[i];
                }
                if (mark[temp] == 0 ) list.push_back(temp);
                mark[temp] += num;
                temp = "";
            }
        } 
        sort(list.begin(),list.end());
        for ( int i = 0 ; i < list.size() ; ++i ) {
            ans += list[i];
            if ( mark[list[i]] != 1 ) ans += to_string(mark[list[i]]);
        }
        return ans;
    }
};
