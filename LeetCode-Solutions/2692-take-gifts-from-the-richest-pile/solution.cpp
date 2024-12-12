class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        long long ans = 0; 
        for ( auto i : gifts ) {
            pq.push(i);
        }
        while ( k ) {
            long long temp = pq.top();
            pq.pop();
            temp = sqrt(temp);
            pq.push(temp);
            k--;
        }
        while ( pq.size() ) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
