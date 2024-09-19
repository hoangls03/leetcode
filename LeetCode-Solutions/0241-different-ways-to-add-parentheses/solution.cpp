class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> ans;
        if ( n == 0 ) return {};
        bool check = true;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( expression[i] == '-' || expression[i] == '+' || expression[i] == '*' ) {
                vector<int> l = diffWaysToCompute(expression.substr(0,i));
                vector<int> r = diffWaysToCompute(expression.substr(i+1));
                for ( auto j : l ) {
                    for ( auto z : r ) {
                        if ( expression[i] == '-' ) ans.push_back(j-z);
                        if ( expression[i] == '+' ) ans.push_back(j+z);
                        if ( expression[i] == '*' ) ans.push_back(j*z);
                    }
                }
                check = false;
            }
        }
        if ( check ) return {stoi(expression)};
        return ans;
    }
};
