class Solution {
public:
    int bt[20];
    void write( vector<string>& arr, int &ans) {
        int n = arr.size() - 1;
        cout<<arr.size()<<'\n';
        int count[30];
        for ( int i = 0 ; i <= 26 ; ++i ) {
            count[i] = 0;
        }
        bool check = false;
        int tmp = 0;
        for ( int i = 0 ; i <= n ; ++i ) {
            if ( bt[i] == 1 ) {
                check = true;
                tmp += arr[i].size();
                for ( auto j : arr[i] ) {
                    count[j-'a']++;
                }
            }
        }
        for ( int i = 0 ; i <= 26 && check; ++i ) {
            if ( count[i] > 1 ) {
                check = false;
            }
        }
        if ( check ) {
            ans = max(ans,tmp);
        }
    }
    void bk(int i, vector<string>& arr, int &ans) {
        for ( int j = 0 ; j <= 1 ; ++j ) {
            int n = arr.size() - 1;
            bt[i] = j;
            if ( i == n ) write(arr,ans);
            else bk(i+1,arr,ans);
        }
    }
    int maxLength(vector<string>& arr) {
        memset(bt,0,sizeof(bt));
        int ans = 0;
        bk(0,arr,ans);
        return ans;
    }
};
