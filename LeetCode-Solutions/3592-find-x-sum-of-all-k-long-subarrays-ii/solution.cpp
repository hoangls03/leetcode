#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        set<ii> st;
        set<ii,greater<ii>> st1;
        map<int,int> mp;
        int n = nums.size();
        vector<long long> ans;
        long long res = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            auto it = st.find({mp[nums[i]],nums[i]});
            mp[nums[i]]++;
            
            if ( st.size() < x || it != st.end() ) {
                if ( it != st.end() ) {
                    
                    auto val = (*it);
                    st.erase(it);
                    res -= 1LL*val.fi*val.se;
                }
                res += 1LL*nums[i]*mp[nums[i]];
                st.insert({mp[nums[i]],nums[i]});
            } else {
                auto it1 = st1.find({mp[nums[i]] - 1,nums[i]}); 
                if ( it1 != st1.end() ) {
                    st1.erase(it1);
                }
                st1.insert({mp[nums[i]],nums[i]});
                auto val = *st.begin();
                auto val1 = *st1.begin();
                if ( val.fi <= val1.fi ) {
                    if ( val.fi < val1.fi || val.se < val1.se ) {
                        res -= 1LL*val.fi*val.se;
                        res += 1LL*val1.fi*val1.se;
                        st.erase(val);
                        st1.erase(val1);
                        if (val.fi > 0 ) st1.insert(val);
                        st.insert(val1);
                    }
                }
            }
            if ( i + 1 >= k ) {
                ans.push_back(res);
                auto it = st.find({mp[nums[i+1-k]],nums[i+1-k]});
                if ( it != st.end() ) {
                    auto val = (*it);
                    st.erase(it);
                    res -= val.se;
                    st.insert({val.fi - 1,val.se});
                } else {
                    it = st1.find({mp[nums[i+1-k]],nums[i+1-k]});
                    auto val = (*it);
                    st1.erase(val);
                    if ( val.fi - 1 > 0 ) st1.insert({val.fi - 1,val.se});
                }
                mp[nums[i+1-k]]--;
                if ( st1.size() ) {
                    auto val = *st.begin();
                    auto val1 = *st1.begin();
                    if ( val.fi <= val1.fi ) {
                        if ( val.fi < val1.fi || val.se < val1.se ) {
                            res -= 1LL*val.fi*val.se;
                            res += 1LL*val1.fi*val1.se;
                            st.erase(val);
                            st1.erase(val1);
                            if ( val.fi > 0 ) st1.insert(val);
                            st.insert(val1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
