const int base = 31;
const long long MOD = 1000000003;
const long long maxn = 1000111;
long long POW[maxn],hashT[maxn];
long long getHashT(int i,int j)
{
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        map<long long,int> mp;
        long long ans = 0;
        for ( auto s : words ) {
            int p = s.size();
            POW[0] = 1;
            for (int i = 1; i <= p; i++)
                POW[i] = (POW[i - 1] * base) % MOD;

            for (int i = 1; i <= p; i++)
                hashT[i] = (hashT[i - 1] * base + s[i-1] - 'a' + 1) % MOD;
            //cout<<"full = "<<hashT[p]<<'\n';
            for ( int  i = 1 ; i <= s.size() ; ++i ) {
                //cout<<getHashT(1,i)<<" "<<getHashT(p-i+1,p)<<'\n';
                if ( getHashT(1,i) == getHashT(p-i+1,p) ) {
                    
                    ans += mp[getHashT(1,i)];
                }
            }
            mp[hashT[p]]++;
        }
        return ans;
    }
};
