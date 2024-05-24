class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> mst;
        int n = heights.size();
        int sum = 0;
        int ans = 0;
        for ( int i = 0 ; i < n - 1 ; ++i ) {
            int diff = heights[i+1] - heights[i];
            //cout<<mst.size()<<" "<<diff<<" "<<'\n';
            if ( diff > 0 ) {
                if ( mst.size() >= ladders ) {
                    if ( mst.size() != 0 ) {
                        auto it = mst.begin();
                        if ( *it < diff ) {
                            sum += *it;
                            mst.erase(it);
                            mst.insert(diff);
                        }
                        else sum += diff;
                    }
                    else sum += diff;
                }
                if ( mst.size() < ladders ) {
                    mst.insert(diff);
                }
                if ( sum > bricks ) {
                    break;
                }
            }
            ans = i + 1;
        }
        return ans;
    }
};
