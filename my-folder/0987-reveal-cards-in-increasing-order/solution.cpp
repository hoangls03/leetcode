class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        int n = deck.size();
        vector<int> ans(n);
        for ( int i = 0 ; i < n ; ++i ) {
            dq.push_back(i);
        }
        sort(deck.begin(),deck.end());
        for ( auto i : deck ) {
            int pos = dq.front();
            dq.pop_front();
            ans[pos] = i;
            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
        return ans;
    }
};
