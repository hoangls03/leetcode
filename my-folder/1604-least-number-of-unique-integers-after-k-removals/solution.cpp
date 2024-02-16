#define ii pair<int,int>
#define fi first 
#define se second
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<long long,int> mp;
        vector<int> vt;
        sort(arr.begin(),arr.end());
        int count = 0;
        for ( int i = 0 ; i < arr.size() ; ++i ) {
            mp[arr[i]]++;
            if ( i == arr.size() - 1 || arr[i] != arr[i+1] ) vt.push_back(mp[arr[i]]);
        }
        sort(vt.begin(),vt.end());
        int temp = 0;
        while ( temp < k && vt.size() ) {
            temp += vt[0];
            if ( temp <= k ) vt.erase(vt.begin());
        }
        return vt.size();
    }
};
