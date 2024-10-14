class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for ( auto i : nums ) {
            pq.push(i);
        }
        while ( k ) {
            int temp = pq.top();
            ans += temp;
            pq.pop();
            int div = temp/3;
            temp = div + (div*3 != temp);
            pq.push(temp);
            k--;
        }
        return ans;
    }
};
