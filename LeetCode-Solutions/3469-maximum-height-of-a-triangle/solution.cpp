class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
       
        bool check = false;
        int temp_red = red;
        int temp_blue = blue;
        int ans = 0;
        while ( red >= 0 && blue >= 0 ) {
            if ( !check ) {
                if ( red >= ans + 1 ) {
                    ans++;
                    red -= ans;
                }
                else red = -1;
            } else {
                if ( blue >= ans + 1 ) {
                    ans++;
                    blue -= ans;
                }
                else blue = -1;
            }
            //cout<<red<<" "<<blue<<" "<<ans<<'\n';
            check ^= 1;
        }
        check = false;
        int ans1 = 0;
        red = temp_red;
        blue = temp_blue;
        while ( red >= 0 && blue >= 0 ) {
            if ( check ) {
                if ( red >= ans1 + 1 ) {
                    ans1++;
                    red -= ans1;
                }
                else red = -1;
            } else {
                if ( blue >= ans1 + 1 ) {
                    ans1++;
                    blue -= ans1;
                }
                else blue = -1;
            }
            //cout<<red<<" "<<blue<<" "<<ans1<<'\n';
            check ^= 1;
        }
        cout<<ans<<" "<<ans1<<'\n';
        return max(ans,ans1);
    }
};
