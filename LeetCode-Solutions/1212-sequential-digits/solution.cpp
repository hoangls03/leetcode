class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums(9);
        for ( int i = 0 ; i < 9 ; ++i ) {
            nums[i] = i+1;
            cout<<nums[i];
        }
        vector<int> ans;
        while ( nums[7] != 0 ) {
            int temp = 0;
            for ( int i = 0 ; i < 9 ; ++i ) 
                temp = temp*10 + nums[i];
            if ( temp <= high && temp >= low ) ans.push_back(temp);
            int check = -1;
            for ( int i = 0 ; i < 9 ; ++i ) {
                cout<<nums[i];
                if ( nums[i] != 0 ) {
                    if ( nums[i] == 1 ) {
                        check = i;
                    }
                    nums[i]--;
                }
            }
            if ( check != -1) {
                nums[8] = 9;
                for ( int i = 7 ; i > check ; --i ) {
                    if ( nums[i+1] != 0 ) nums[i] = nums[i+1] - 1;
                    else nums[i] = 0;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
