class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> mp;
        for ( auto i : basket1 ) {
            mp[i]++;
        }
        for ( auto i : basket2 ) {
            mp[i]++;
        }
        map<int,int> mp1;
        vector<int> fruit;
        int minVal = 1e9 + 1;
        for ( auto i : basket1 ) {
            mp1[i]++;
            if ( mp[i] & 1 ) {
                return -1;
            }
            if ( mp1[i] > mp[i]/2 ) {
                fruit.push_back(i);
            }
            minVal = min(minVal,i);
        }
        mp1.clear();
        for ( auto i : basket2 ) {
            mp1[i]++;
            if ( mp[i] & 1 ) {
                return -1;
            }
            if ( mp1[i] > mp[i]/2 ) {
                fruit.push_back(i);
            }
            minVal = min(minVal,i);
        }
        sort(fruit.begin(),fruit.end());
        int n = fruit.size();
        long long ans = 0;
        for ( int i = 0 ; i < n/2 ; ++i ) {
            ans += min(minVal * 2,fruit[i]);
        }
        return ans;
    }
};
