class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int num = arr.size()/4;
        if ( num < 1 ) return arr[0]; 
        int count = 1;
        for ( int i = 1 ; i < arr.size() ; ++i ) {
            if ( arr[i] == arr[i-1] ) {
                count++;
            }
            else {
                count = 1;
            }
            if ( count > num ) return arr[i];
        }
        return arr[0];
    }
};
