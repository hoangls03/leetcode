class Solution {
public:
    
    bool cmp( int a, int b, map<long long,int>& mp, map<long long,int>& pos ) {
        if ( mp[a] == mp[b] ) return pos[a] < pos[b];
        return mp[a] < mp[b];
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<long long,int> mp,pos;
        mp.clear();
        pos.clear();
        for ( auto i : nums ) {
            long long temp = i;
            long long num = 0;
            stack<int> st;
            while ( temp > 0 ) {
                st.push(mapping[temp%10]);
                temp /= 10;
            }
            while ( st.size() ) {
                num = num*10 + st.top();
                st.pop();
            }
            if ( i == 0 ) mp[i] = mapping[0];
            else mp[i] = num;
        }
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            pos[nums[i]] = i;
        }
        sort(nums.begin(),nums.end(),[&](int a, int b){
            return cmp(a,b,mp,pos);
        });
        return nums;
    }
};
