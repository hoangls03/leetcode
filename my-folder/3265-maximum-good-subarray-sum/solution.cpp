class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<long long,long long> mp;
        long long sum = 0;
        int n = nums.size(); 
        mp.clear();
        for ( int i = 0 ; i < n ; ++i ) {
            mp[nums[i]] = -1e15;
            mp[nums[i]+k] = -1e15;
            mp[nums[i]-k] = -1e15;
        }
        long long ans = -1e15;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mp[nums[i]] == -1e15 ) mp[nums[i]] = sum;
            else if ( sum < mp[nums[i]] ) mp[nums[i]] = sum;
            sum += nums[i];
            if ( mp[nums[i]-k] != -1e15 ) ans = max(ans,sum - mp[nums[i]-k]);
            if ( mp[nums[i]+k] != -1e15 ) ans = max(ans,sum - mp[nums[i]+k]);
            //cout<<ans<<" "<<sum<<" "<<mp[nums[i]-k]<<" "<<mp[nums[i]+k]<<" "<<mp[nums[i]]<<" "<<nums[i]<<'\n';
        }
        //cout<<"debug"<<'\n';
        if ( ans == -1e15 ) ans = 0;
        return ans;
    }
};
