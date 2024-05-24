class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int pos = 0;
        int ans = 0;
        for ( int i = n - 1 ; i >= pos ; --i ) {
            if ( i > pos ) {
                if ( people[i] + people[pos] <= limit ) {
                    pos++;
                } 
                ans++;
            }
            else if ( i == pos ) {
                pos++;
                ans++;
            }
        }
        return ans;
    }
};
