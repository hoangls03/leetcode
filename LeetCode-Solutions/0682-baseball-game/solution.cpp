class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for ( auto i : operations ) {
            if ( i == "+" ) {
                int temp = ans[ans.size()-1];
                int temp1 = ans[ans.size() - 2];
                ans.push_back(temp+temp1);
            }
            else if ( i == "D" ) {
                int temp = ans[ans.size()-1];
                ans.push_back(temp*2);
            }
            else if ( i == "C" ) {
                ans.pop_back();
            } else {
                ans.push_back(stoi(i));
            }
        }
        int sum = 0;
        for ( auto i : ans ) {
            sum += i;
        }
        return sum;
    }
};
