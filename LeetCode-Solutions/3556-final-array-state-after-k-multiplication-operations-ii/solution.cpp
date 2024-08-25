#define ii pair<long long,int>
#define fi first
#define se second
const int oo = 1e9 + 7;
class Solution {
public:
    int mu( long long a, long long b ) {
        if ( b == 0 ) return 1;
        if ( b == 1 ) return a;
        long long tmp = mu(a,b/2)%oo;
        if ( b & 1 ) return (tmp*tmp)%oo*a%oo;
        return tmp*tmp%oo;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if ( multiplier == 1 ) return nums;
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        int n = nums.size();
        int pos_max = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            pq.push({nums[i],i});
            if ( nums[i] >= nums[pos_max] ) pos_max = i;
        }
        
        sort(nums.begin(),nums.end());
        /*for ( auto i : nums ) {
            cout<<i<<" ";
        }
        cout<<'\n';
        cout<<nums[n-1]<<'\n';
        */
        while ( pq.top().fi <= nums[n-1] && k > 0 ) {
            auto val = pq.top();
            pq.pop();
            int temp = nums[n-1]/val.fi;
            pq.push({val.fi*multiplier,val.se});
            k--;
            if ( val.se == pos_max ) break;
        }
        vector<ii> a;
        while ( pq.size() ) {
            auto val = pq.top();
            a.push_back(val);
            pq.pop();
        }
        /*for ( int i = 0 ; i < n ; ++i ) {
            cout<<a[i].fi<<" ";
        }
        cout<<'\n';
        */
        int round = k/n;
        int pos = k%n;
        //cout<<"round = "<<round<<'\n';
        //cout<<"pos = "<<pos<<'\n';
        for ( int i = 0 ; i < n ; ++i ) {
            a[i].fi = (a[i].fi % oo) * mu(multiplier,round) % oo;
            if ( i < pos ) {
                a[i].fi = a[i].fi * multiplier % oo;
            }
        }
        /*for ( int i = 0 ; i < n ; ++i ) {
            cout<<a[i].fi<<" ";
        }
        cout<<'\n';
        */
        for ( int i = 0 ; i < n ; ++i ) {
            nums[a[i].se] = a[i].fi%oo;
        }
        return nums;
    }
};
