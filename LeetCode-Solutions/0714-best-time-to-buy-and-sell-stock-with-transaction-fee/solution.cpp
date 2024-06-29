class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int pre_sell = -1e9;
        int current_buy = 1e9;
        int pre_buy = prices[0];
        int temp_sell = -1e9;
        int ans = 0;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( pre_sell != -1e9 ) {
                if ( prices[i] - current_buy - fee > 0 ) {
                    if ( temp_sell > current_buy + fee ) {
                        ans = max(ans,pre_sell - pre_buy - fee + prices[i] - current_buy - fee);
                        pre_sell = prices[i] + pre_sell;
                        pre_buy += current_buy + fee;
                        temp_sell = prices[i];
                    } else {
                        ans = max(ans,pre_sell - temp_sell + prices[i] - pre_buy - fee);
                        pre_sell = pre_sell - temp_sell + prices[i];
                        temp_sell = prices[i];
                        

                    }
                    current_buy = 1e9;
                } else {
                    //cout<<"here ";
                    if ( prices[i] > temp_sell ) {
                        pre_sell = pre_sell - temp_sell + prices[i];
                        temp_sell = prices[i];
                        ans = max(ans,pre_sell - pre_buy - fee);
                    } else {
                        current_buy = min(current_buy,prices[i]);
                    }
                }
            } else {
                if ( prices[i] - pre_buy - fee > 0 ) {
                    ans = max(ans,prices[i] - pre_buy - fee);
                    pre_sell = prices[i];
                    temp_sell = prices[i];
                } else {
                    pre_buy = min(pre_buy,prices[i]);
                }
            }
            //cout<<"pre_buy: "<<pre_buy<<" "<<"pre_sell "<<pre_sell<<" "<<"temp_sell "<<temp_sell<<" "<<"current_buy "<<current_buy<<" "<<prices[i]<<" "<<ans<<'\n';
            //cout<<ans<<'\n';
        }
        return ans;
    }
};
