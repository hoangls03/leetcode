class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                mp[nums[i]*nums[j]]++;
            }
        }
        for ( auto &it : mp ) {
            int count = it.second;
            if ( count >= 2 ) {
                ans += count*(count-1)/2;
            }
        }
        return ans*8;
    }
};
