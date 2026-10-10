class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<int> pq;
        int n = nums1.size();
        map<int,int> mp;
        for ( int i = 0 ; i < n ; ++i ) {
            int val = abs(nums1[i] - nums2[i]);
            if ( mp[val] == 0 ) {
                pq.push(val);
                // cout<<val<<'\n';
            }
            mp[val]++;
        }
        long long val = k1 + k2;
        while (val > 0) {
            // cout<<"VAL BEFORE "<<val<<" "<<pq.size()<<" "<<pq.top()<<'\n';
            long long u = pq.top();
            pq.pop();
            int v = 0;
            if ( pq.size() ) {
                v = pq.top();
            }
            // cout<<u<<" "<<mp[u]<<" "<<val<<" "<<v<<" "<<'\n';
            long long subtract = min((u - v)*mp[u], val);
            if ( u == 0 ) break;
            if ( subtract < mp[u] ) {
                mp[u] -= subtract;
                if ( mp[u-1] == 0 ) {
                    pq.push(u - 1);
                }
                mp[u - 1] += subtract;
                // cout<<"EXECUTED\n";
                pq.push(u);
            } else {
                int numE = subtract/mp[u];
                subtract = numE * mp[u];
                // cout<<"run here "<<numE<<" "<<mp[u-numE]<<'\n';
                if ( mp[u - numE] == 0 ) {
                    pq.push(u - numE);
                }
                mp[u - numE] += mp[u];
                mp[u] = 0;    
            }
            int checkTop = 0;
            if ( pq.size() ) {
                checkTop = pq.top();
            }
            // cout<<"after "<<u<<" "<<mp[u]<<" "<<pq.size()<<" "<<subtract<<" "<<checkTop<<'\n';
            val -= subtract;
            // cout<<"Val after "<<val<<'\n';
        }
        long long ans = 0;
        while ( pq.size() ) {
            long long u = pq.top();
            pq.pop();
            // cout<<u<<" "<<mp[u]<<'\n';
            ans += u*u*mp[u];
        }
        return ans;
    }
};
