class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2];
        int ans = 0;
        int n = students.size();
        for ( auto i : students ) {
            count[i]++;
        }
        for ( auto i : sandwiches ) {
            if ( count[i] == 0 ) break;
            if ( count[i] != 0 ) {
                ans++;
                count[i]--;
            }
        }
        ans = n - ans;
        return ans;
    }
};
