class Solution {
public:
    struct st{
        int pre;
        int suf;
        int sum;
        int max;
    };
    st maxarray( int l , int r , vector<int>& nums  ) {
        st ans;
        if ( l == r ) {
            ans.pre = nums[l];
            ans.suf = nums[l];
            ans.sum = nums[l];
            ans.max = nums[l];
            return ans;
        }
        int mid = (l + r) >> 1;
        st left = maxarray(l,mid,nums);
        st right = maxarray(mid+1,r,nums);
        ans.pre = max({left.pre,left.sum + right.pre,left.sum + right.sum});
        ans.suf = max({right.suf,right.sum + left.suf,right.sum + left.sum});
        ans.sum = left.sum + right.sum;
        ans.max = max({left.max,right.max,left.suf+right.pre,left.sum + right.sum});
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        st ans = maxarray(0,n-1,nums);
        return ans.max;
    }
};
