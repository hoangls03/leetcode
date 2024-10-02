class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if ( arr.size() == 0 ) return {};
        vector<int> a = arr;
        sort(a.begin(),a.end());
        map<int,int> mp;
        int pos = 1;
        mp[a[0]] = 1;
        for ( int i = 1 ; i < a.size() ; ++i ) {
            if ( a[i] > a[i-1] ) {
                pos++;
                mp[a[i]] = pos;
            }
        }
        for ( int i = 0 ; i < arr.size() ; ++i ) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
