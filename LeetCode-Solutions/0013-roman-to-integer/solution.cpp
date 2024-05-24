class Solution {
public:
    int romanToInt(string s) {
        int ans = 0,n,temp = 0;
        n = s.size();
        s = " " + s;
        for ( int i = 1 ; i <= n ; ++i )
        {
            temp = 0;
            if ( s[i] == 'I' )
            {
                if ( i + 1 <= n )
                {
                    if ( s[i+1] == 'V' )
                    {
                        ans += 4;
                        temp = 1;
                    }
                    else if ( s[i+1] == 'X' )
                    {
                        ans += 9;
                        temp = 1;
                    }
                    else ans += 1;
                }
                else ans += 1;
            }
            if ( s[i] == 'X' )
            {
                if ( i + 1 <= n )
                {
                    if ( s[i+1] == 'L' )
                    {
                        ans += 40;
                        temp = 1;
                    }
                    else if ( s[i+1] == 'C' )
                    {
                        ans += 90;
                        temp = 1;
                    }
                    else ans += 10;
                }
                else ans += 10;
            }
            if ( s[i] == 'C' )
            {
                if ( i + 1 <= n )
                {
                    if ( s[i+1] == 'D' )
                    {
                        ans += 400;
                        temp = 1;
                    }
                    else if ( s[i+1] == 'M' )
                    {
                        ans += 900;
                        temp = 1;
                    }
                    else ans += 100;
                }
                else ans += 100;
            }
            if ( s[i] == 'V' ) ans += 5;
            if ( s[i] == 'L' ) ans += 50;
            if ( s[i] == 'D' ) ans += 500;
            if ( s[i] == 'M' ) ans += 1000;
            i += temp;
            
        }
        return ans;
    }
};
