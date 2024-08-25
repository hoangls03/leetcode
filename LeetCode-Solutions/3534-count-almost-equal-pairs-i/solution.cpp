class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(); 
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                int temp = nums[i];
                vector<int> d;
                while ( temp > 0 ) {
                    d.push_back(temp%10);
                    temp /= 10;
                }
                temp = nums[j];
                vector<int> d1;
                while ( temp > 0 ) {
                    d1.push_back(temp%10);
                    temp /= 10;
                }
                while ( d.size() < d1.size() ) {
                    d.push_back(0);
                }
                while ( d1.size() < d.size() ) {
                    d1.push_back(0);
                }
                vector<int> pos;
                for ( int k = 0 ; k < d.size() ; ++k ) {
                    if ( d[k] != d1[k] ) pos.push_back(k);
                }
                if ( pos.size() == 2 ) {
                    swap(d[pos[0]],d[pos[1]]);
                    bool check = true;
                    for ( int k = 0 ; k < d.size() ; ++k ) {
                        if ( d[k] != d1[k] ) check = false;
                    }
                    ans += check;
                } else if ( pos.size() == 0 ) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
