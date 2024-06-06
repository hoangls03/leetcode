class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,vector<int>> mp;
        map<int,int> check;
        int n = hand.size();
        sort(hand.begin(),hand.end());
        for ( int i = n - 1; i >= 0 ; --i ) {
            mp[hand[i]].push_back(i);
        }
        int count = 0;
        /*for ( auto i : hand ) {
            cout<<i<<" ";
        }
        cout<<'\n';
        */
        for ( int i = 0 ; i < n ; ++i ) {
            if ( check[i] == groupSize - 1 ) {
                count++;
            }
            if ( check[i] < groupSize - 1 ) {
                if ( mp[hand[i]+1].size() == 0 ) {
                    //cout<<hand[i]+1<<" "<<check[i]<<'\n';
                    return false;
                }
                
                int temp = mp[hand[i]+1].back();
                mp[hand[i]+1].pop_back();
                check[temp] = check[i] + 1;
                //cout<<hand[i]<<" "<<hand[i]+1<<" "<<mp[hand[i]].size()<<" "<<mp[hand[i]+1].size()<<" "<<check[i]<<" "<<check[temp]<<" "<<temp<<'\n';
            }
        }
        if ( count*(groupSize) != n ) return  false;
        return true;
    }
};
