#define ii pair<long long,long long>
#define fi first
#define se second
class Solution {
public:
    static bool cmp( ii a, ii b) {
        if ( a.se*b.fi == b.se*a.fi ) {
            return a.fi < b.fi;
        }
        return a.se*b.fi < b.se*a.fi;
    }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<ii> a;
        for ( int i = 0 ; i < n ; ++i ) {
            int temp = health[i]/power;
            if ( power*temp != health[i] ) temp++;
            health[i] = temp;
            a.push_back({damage[i],health[i]});
        }
        sort(a.begin(),a.end(),cmp);
        long long ans = 0,sum = 0;
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            sum += a[i].fi;
            ans += sum*a[i].se;
        }
        return ans;
    }
};
