#define LL long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int right_min = 0;
        int right_max = 0;
        int left_max;
        int left_min;
        int n =  nums.size();
        map<int,int> mp_min;
        map<int,int> mp_max;
        mp_min.clear();
        mp_max.clear();
        queue<int> q_min;
        queue<int> q_max;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( nums[i] == minK ) q_min.push(i);
            if ( nums[i] == maxK ) q_max.push(i);
        }
        for ( int i = 0 ; i < n ; ++i ) {
            right_min = max(right_min,i);
            right_max = max(right_max,i);
            left_min = n + 2;
            left_max = n + 2;
            if ( q_min.size() ) left_min = q_min.front();
            if ( q_max.size() ) left_max = q_max.front();
            while ( right_min < n && nums[right_min] >= minK ) {
                mp_min[nums[right_min]]++;
                right_min++;
            }
            while ( right_max < n && nums[right_max] <= maxK ) {
                mp_max[nums[right_max]]++;
                right_max++;
            }

            if ( mp_min[minK] != 0 && mp_max[maxK] != 0 && left_min <= right_min && left_max <= right_max ) {
                int l = max(left_min,left_max);
                int r = min(right_min,right_max);
                if ( l <= r ) ans += r - l;
                //cout<<"yes"<<" "<<r-l<<'\n';
            }
            //cout<<i<<" "<<left_min<<" "<<right_min<<" "<<left_max<<" "<<right_max<<'\n';
            if ( right_min > i ) mp_min[nums[i]]--;
            if ( right_max > i ) mp_max[nums[i]]--;
            if ( q_min.front() == i ) q_min.pop();
            if ( q_max.front() == i ) q_max.pop();
        } 
        return ans;
    }
};
