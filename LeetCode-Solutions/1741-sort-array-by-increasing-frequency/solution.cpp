class Solution {
public:
    bool cmp(int a, int b, map<int,int>& mp ) {
        if ( mp[a] == mp[b] ) return a > b;
        return mp[a] < mp[b];
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for ( auto i : nums ) {
            mp[i]++;
        }
        sort(nums.begin(),nums.end(),[&](int a, int b) {
            return cmp(a,b,mp);
        });
        return nums;
    }
};
