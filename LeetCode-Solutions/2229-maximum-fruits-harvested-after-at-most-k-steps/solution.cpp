class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int pos = 0;
        vector<vector<int>> rightFruits;
        int sum = 0, rightSum = 0;
        int ans = 0;
        for ( auto i : fruits ) {
            if ( i[0] > startPos ) {
                rightSum += i[1];
                if ( i[0] - startPos <= k ) {
                    ans = max(ans,rightSum);
                }
                rightFruits.push_back(i);
            }
            else sum += i[1];
        }
        int m = rightFruits.size();
        int rightVal = 0;
        for ( auto i : fruits ) {
            if ( i[0] > startPos ) {
                break;
            }
            int dis = startPos - i[0];
            while ( pos < m && min(2*dis + rightFruits[pos][0] - startPos,dis + (rightFruits[pos][0] - startPos)*2) <= k ) {
                rightVal += rightFruits[pos][1];
                ans = max(ans,rightVal + sum);
                pos++;
            }
            if ( dis <= k ) {
                ans = max(ans,sum);
            }
            sum -= i[1];
        }
        return ans;
    }
};
