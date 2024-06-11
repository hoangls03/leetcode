class Solution {
public:
    static bool cmp(int a, int b, vector<int>& pos) {
        return (pos[a] < pos[b]);
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> pos(1005,1001);
        for ( int i = 0 ; i < arr2.size() ; ++i ) {
            pos[arr2[i]] = i;
        }
        for ( auto i : arr1 ) {
            if ( pos[i] == 1001 ) {
                pos[i] = 1001 + i;
            }
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
        return cmp(a, b, pos);
        });
        return arr1;
    }
};
