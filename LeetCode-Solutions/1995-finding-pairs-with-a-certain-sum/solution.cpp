class FindSumPairs {
public:
    vector<int> nums3,nums4;
    map<int,int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        nums3 = nums1;
        nums4 = nums2;
        mp.clear();
        for ( auto i : nums4 ) {
            mp[i]++;
        }
    }
    
    void add(int index, int val) {
        mp[nums4[index]]--;
        nums4[index] += val;
        mp[nums4[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for ( auto i : nums3 ) {
            ans += mp[tot - i];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
