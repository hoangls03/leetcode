class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        map<long long,int> mp;
        long long ans = 0;
        for ( auto i : arr1 ) {
            long long temp = i;
            long long count= 0;
            while ( pow(10,count) <=temp ) {
                count++;
            }
            for ( int j = count - 1 ; j >= 0 ; --j ) {
                long long val = pow(10,j);
                mp[i/val] = 1;
            }
        }
        for ( auto i : arr2 ) {
            long long temp = i;
            long long count= 0;
            while ( pow(10,count) <= temp ) {
                count++;
            }
            long long dem = 0;
            for ( int j = count - 1 ; j >= 0 ; --j ) {
                dem++;
                long long val = pow(10,j);
                //cout<<j<<" "<<val<<" "<<i<<" "<<i/val<<'\n';
                if ( mp[i/val] != 0 ) ans = max(ans,dem);
            }
        }
        return ans;
    }
};
