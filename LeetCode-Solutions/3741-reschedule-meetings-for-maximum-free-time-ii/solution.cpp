class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        multiset<int,greater<int>> ms;
        int n = startTime.size();
        startTime.push_back(eventTime);
        vector<int> freeSpace;
        for ( int i = 0 ; i <= n ; ++i ) {
            if ( i == 0 ) {
                freeSpace.push_back(startTime[i]);
            } else {
                freeSpace.push_back(startTime[i] - endTime[i-1]);
            }
        }
        for ( auto i : freeSpace ) {
            ms.insert(i);
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            int meet = endTime[i] - startTime[i];
            int res = freeSpace[i] + freeSpace[i+1];
            auto it1 = ms.find(freeSpace[i]);
            ms.erase(it1);
            auto it2 = ms.find(freeSpace[i+1]);
            ms.erase(it2);
            int val = *ms.begin();
            if ( val >= meet ) {
                res += meet;
            }
            ms.insert(freeSpace[i]);
            ms.insert(freeSpace[i+1]);
            ans = max(ans,res);
        }
        return ans;
    }
};
