class Solution {
public:
    int pivotInteger(int n) {
        int m = (n*(n+1))/2;
        int ans = sqrt(m);
        if ( ans*ans == m ) return ans;
        return -1;
    }
};
