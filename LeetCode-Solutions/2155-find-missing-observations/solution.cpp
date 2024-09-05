class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = ( m + n )*mean;
        for ( auto i : rolls ) {
            sum -= i;
        }
        if ( sum > n*6 || sum < n ) return {};
        vector<int> ans;
        while ( n > 0 ) {
            int temp = min(sum - (n-1),6);
            n--;
            ans.push_back(temp);
            sum -= temp;
        }
        return ans;
    }
};
