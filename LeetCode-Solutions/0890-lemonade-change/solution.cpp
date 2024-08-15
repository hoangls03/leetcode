class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;
        for ( auto i : bills ) {
            int j = i;
            i -= 5;
            int temp = min(count10,i/10);
            i -= temp*10;
            count10 -= temp;
            temp = min(count5,i/5);
            i -= temp*5;
            count5 -= temp;
            if ( i > 0 ) return false;
            count5 += ( j == 5 );
            count10 += ( j == 10);
        }
        return true;
    }
};
