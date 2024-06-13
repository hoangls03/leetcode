class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if ( flowerbed.size() == 1 ) {
            if ( n == 0 || (flowerbed[0] == 0 && n == 1) ) return true;
            return false;
        }
        for ( int i = 0 ; i < flowerbed.size() && n > 0 ; ++i ) {
            if ( flowerbed[i] == 0 ) {
                if ( i == 0 ) {
                    if ( flowerbed[i+1] == 0 ) {
                        flowerbed[i] = 1;
                        n--;
                    }
                } else if ( i == flowerbed.size() - 1 ) {
                    if ( flowerbed[i-1] == 0 ) {
                        n--;
                        flowerbed[i] = 1;
                    }
                }
                else {
                    if ( flowerbed[i-1] == 0 && flowerbed[i+1] == 0 ) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            }
        }
        if ( n == 0 ) return true;
        return false;
    }
};
