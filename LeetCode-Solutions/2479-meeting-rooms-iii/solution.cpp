bool compareFunc(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0]; // Sort based on the first column
}
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compareFunc);
        queue<int> q;
        for ( int i = 0 ; i < meetings.size() ; ++i ) {
            //cout<<meetings[i][0]<<" "<<meetings[i][1]<<'\n';
            q.push(i);
        }
        long long mark[n];
        int count[n];
        for ( int i = 0 ; i < n ; ++i ) 
            count[i] = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            mark[i] = 0;
        }
        while ( q.size() ) {
            int pos = q.front();
            q.pop();
            long long temp = 1e18;
            for ( int i = 0 ; i < n ; ++i ) {
                temp = min(temp,mark[i]);
            }
            for ( int i = 0 ; i < n ; ++i ) {
                //cout<<mark[i]<<" "<<pos<<" "<<meetings[pos][1] - meetings[pos][0]<<'\n';
                if ( mark[i] <= meetings[pos][0] || mark[i] == temp ) {
                    long long start = meetings[pos][0];
                    mark[i] = max(mark[i],start) + meetings[pos][1] - meetings[pos][0];
                    //cout<<"update"<<i<<" "<<mark[i]<<'\n';
                    count[i]++;
                    break;
                }
            }
        }
        int compare = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            compare = max(compare,count[i]);
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            //cout<<count[i]<<" ";
            if ( count[i] == compare ) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
