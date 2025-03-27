class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        if ( n == 1 ) {
            return -1;
        }
        vector<int> save(n,-1);
        map<int,int> mp;
        int app = 0;
        int num = -1;
        for ( int i = n - 1; i >= 0 ; --i ) {
            mp[nums[i]]++;
            if ( mp[nums[i]] > app ) {
                num = nums[i];
                app = mp[nums[i]];
            }
            int len = n - i;
            if ( mp[num] > len/2 ) {
                save[i] = num;
            }
        }
        mp.clear();
        num = -1;
        app = 0;
        for ( int i = 0 ; i < n - 1 ; ++i ) {
            mp[nums[i]]++;
            if ( mp[nums[i]] > app ) {
                num = nums[i];
                app = mp[nums[i]];
            }
            int len = i + 1;
            if ( mp[num] > len/2 ) {
                if ( num == save[i+1] ) {
                    return i;
                }
            }
        }
        return -1;
    }
};
