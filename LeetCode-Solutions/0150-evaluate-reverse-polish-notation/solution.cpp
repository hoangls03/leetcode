class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for ( auto i : tokens ) {
            cout<<i<<'\n';
            if ( i == "+" ) {
                int u = st.top();
                st.pop();
                int v = st.top();
                st.pop();
                int temp = v + u;
                st.push(temp);
            }
            else if ( i == "-" ) {
                int u = st.top();
                st.pop();
                int v = st.top();
                st.pop();
                int temp = v - u;
                st.push(temp);
            }
            else if ( i == "*" ) {
                int u = st.top();
                st.pop();
                int v = st.top();
                st.pop();
                int temp = v * u;
                st.push(temp);
            }
            else if ( i == "/" ) {
                int u = st.top();
                st.pop();
                int v = st.top();
                st.pop();
                int temp = v / u;
                st.push(temp);
            }
            else {
                int num = 0;
                for ( int j = 0  ; j < i.size() ; ++j ) {
                    if ( i[j] != '-' ) num = num*10 + i[j] - '0';
                }
                if ( i[0] == '-' ) num = -num;
                st.push(num);
            }
        }
        int ans = st.top();
        return ans;
    }
};
