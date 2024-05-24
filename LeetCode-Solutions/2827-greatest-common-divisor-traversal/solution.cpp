class Solution {
public:
    void DFS( int start, map<int,vector<int>>& prime_factor,  map<int,vector<int>>& num_factor, map<int,bool>& mark, map<int,bool>& factor ) {
        //cout<<start<<" "<<mark[start]<<'\n';
        if ( mark[start] == true ) return ;
        mark[start] = true;
        for ( auto u : prime_factor[start] ) {
            if ( !factor[u] ) {
                factor[u] = true;
                for ( auto v : num_factor[u] ) {
                    if ( !mark[v] ) {
                        DFS(v,prime_factor,num_factor,mark,factor);
                    }
                }
            }
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> prime_factor;
        map<int,vector<int>> num_factor;
        map<int,bool> mark;
        map<int,bool> factor;
        for ( int i = 0 ; i < n ; ++i ) {
            int temp = nums[i];
            for ( int j = 2 ; j <= trunc(sqrt(nums[i])) ; ++j ) {
                if ( temp % j == 0 ) {
                    prime_factor[i].push_back(j);
                    num_factor[j].push_back(i);
                }
                while ( temp % j == 0 ) {
                    temp /= j;
                }
            }
            if ( temp != 1 ) {
                prime_factor[i].push_back(temp);
                num_factor[temp].push_back(i);
            }
        }
        DFS(0,prime_factor,num_factor,mark,factor);
        for ( int i = 0 ; i < n ; ++i ) {
            if ( !mark[i] ) return false;
        }
        return true;
    }
};
