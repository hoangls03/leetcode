class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int m = tasks.size();
        int n = workers.size();
        int r = min(m,n);
        int l = 1;
        int ans = 0;
        int savedPills = pills;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1;
            multiset<int,greater<int>> ms;
            for ( auto i : tasks ) {
                ms.insert(i);
            }
            bool check = true;
            pills = savedPills;
            for ( int i = n - mid ; i < n ; ++i ) {
                auto it = ms.lower_bound(workers[i]);
                if ( it == ms.end() ) {
                    if ( pills ) {
                        auto it1 = ms.lower_bound(workers[i] + strength);
                        pills--;
                        if ( it1 == ms.end() ) {
                            check = false;
                            break;    
                        }
                        ms.erase(it1);
                    } else {
                        check = false;
                        break;
                    }
                } else {
                    ms.erase(it);
                }
            }
            if ( check ) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }   
};
