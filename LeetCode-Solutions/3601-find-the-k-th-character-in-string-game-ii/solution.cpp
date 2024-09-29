class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        long long op = 1;
        int pos = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            op *= 2;
            if ( op >= k ) {
                pos = i;
                break;
            }   
        }
        long long inc = 0;
        op /= 2;
        for ( int i = pos ; i >= 0 ; --i ) {
            if ( k > op ) {
                k -= op;
                if ( operations[i] == 1 ) inc++; 
            }
            op /= 2;
        }
        char ans = inc%26 + 'a';
        return ans;

    }
};
