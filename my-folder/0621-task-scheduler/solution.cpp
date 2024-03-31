class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for ( auto i : tasks ) {
            count[i-'A']++;
        }
        sort(count.begin(),count.end());
        int nums = (count[25] - 1)*n;
        for ( int i = 24 ; i >= 0 ; --i ) {
            nums -= min(count[i],count[25] - 1);
        } 
        return (nums < 0) ? tasks.size() : tasks.size() + nums; 
    }
};
