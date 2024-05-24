class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        vector<int> count(1001,0);
        for ( auto i : arr ) {
            mp[i]++;
        }
        sort(arr.begin(),arr.end());
        for ( int i = 0 ; i < arr.size() ; ++i ) {
            if ( i == 0 || arr[i] != arr[i-1] ) {
                count[mp[arr[i]]]++;
                if ( count[mp[arr[i]]] == 2 ) {
                    return false;
                }
            }
        }
        return true;
    }
};
