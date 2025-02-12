class Solution {
public:
    int digitSum( int n ) {
        int sum = 0;
        while ( n > 0 ) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        vector<int> mark(100,0);
        int ans = -1;
        for ( auto i : nums ) {
            int temp = digitSum(i);
            if ( mark[temp] != 0 ) {
                ans = max(ans,i+mark[temp]);
            }
            mark[temp] = max(mark[temp],i);
        }    
        return ans;  
    }
};
