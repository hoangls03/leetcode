#define LL long long;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = potions.size();
        vector<int> ans;
        for ( int i = 0 ; i < spells.size() ; ++i ) {
            int l = 0;
            int r = n - 1;
            int pos = -1;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                long long temp = 1LL*potions[mid]*spells[i];
                if ( temp >= success ) {
                    pos = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            if ( pos == -1 ) ans.push_back(0);
            else ans.push_back(n-pos);
        }
        return ans;
    }
};
