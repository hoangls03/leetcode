class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> spot;
        int n = boxes.size();
        int sumSpot = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( boxes[i] == '1' ) {
                spot.push_back(i);
                sumSpot += i;
            }
        }
        vector<int> ans;
        if ( spot.size() == 0 ) {
            for ( int i = 0 ; i < n ; ++i ) {
                ans.push_back(0);
            }
            return ans;
        }
        int pos = 0;
        int localSum = 0;
        int sz = spot.size();
        for ( int i = 0 ; i < n ; ++i ) {
            while ( pos < sz && i >= spot[pos] ) {
                localSum += spot[pos];
                pos++;
            }
            int greater = pos > 0 ? sz - pos - 1 : sz;
            int less = pos > 0 ? pos - 1 : -1;
            int left = 0;
            if ( less != -1 ) left = i*less - localSum; 
            int res = sumSpot - localSum - greater*i + left;
            ans.push_back(res);
        }
        return ans;
    }
};
