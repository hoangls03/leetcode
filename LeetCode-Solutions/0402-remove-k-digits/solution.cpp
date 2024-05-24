class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> dq;
        dq.clear();
        if ( k >= num.size() ) return "0";
        for ( auto i : num ) {
            if ( dq.empty() ) dq.push_back(i);
            else {
                while ( dq.size() && dq.back() > i && k > 0 ) {
                    dq.pop_back();
                    k--;
                }
                dq.push_back(i);
            }
        }
        while (k > 0 && !dq.empty()) {
            dq.pop_back();
            k--;
        }
        string ans = "";
        while ( dq.size() ) {
            char temp = dq.front();
            if ( ans != "" || temp != '0' || dq.size() == 1 ) ans += temp;
            dq.pop_front();
        }
        return ans;
    }
};
