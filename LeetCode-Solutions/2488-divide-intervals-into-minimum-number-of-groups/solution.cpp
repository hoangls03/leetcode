class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        multiset<int,greater<int>> ms;
        sort(intervals.begin(),intervals.end());
        for ( auto i : intervals ) {
            if ( ms.size() ) {
                auto it = ms.upper_bound(i[0]);
                if ( it != ms.end() ) {
                    ms.erase(it);
                } 
            } 
            ms.insert(i[1]);
        }
        return ms.size();
    }
};
