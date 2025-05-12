class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10);
        for ( auto i : digits ) {
            count[i]++;
        }
        vector<int> ans;
        for ( int i = 1 ; i <= 9 ; ++i ) {
            for ( int j = 0 ; j <= 9 ; ++j ) {
                for ( int z = 0 ; z <= 9 ; z += 2 ) {
                    count[i]--;
                    count[j]--;
                    count[z]--;
                    if ( count[i] >= 0 && count[j] >= 0 && count[z] >= 0 ) {
                        ans.push_back(i*100 + j*10 + z);
                    }
                    count[i]++;
                    count[j]++;
                    count[z]++;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
