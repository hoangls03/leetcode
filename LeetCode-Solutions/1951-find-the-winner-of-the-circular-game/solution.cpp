class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> check(n+1,false);
        int erease = 0;
        int index = 1;
        int step = 1;
        queue<int> q;
        for ( int i = 1 ; i <= n ; ++i ) {
            q.push(i);
        }
        while ( q.size() > 1 ) {
            if ( step == k ) {
                q.pop();
                step = 1;
            } else {
                step++;
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
        return q.front();
    }
};
