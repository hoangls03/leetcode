class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for ( auto i : nums ) {
            pq.push(i);
        }
        int ans = 0;
        while ( pq.size() >= 2 && pq.top() < k ) {
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            pq.push(num1*2+num2);
            ans++;
        }
        return ans;
    }
};
