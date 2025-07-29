class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> mark(35,0);
        int bitCount = 0;
        for ( auto i : nums ) {
            while ( i > 0 ) {
                int tmp = log2(i);
                bitCount += (mark[tmp] == 0);
                mark[tmp]++;
                i -= (1 << tmp);
            }
        }
        int tmpCount = 0, pos = 0;
        int val = nums[0];
        vector<int> tmpMark(35,0);
        while ( val > 0 ) {
            int tmp = log2(val);
            if ( tmpMark[tmp] == 0 ) {
                tmpCount++;
            }
            tmpMark[tmp]++;
            val -= ( 1 << tmp );
        }
        vector<int> ans;
        for ( int i = 0 ; i < n ; ++i ) {
            while ( tmpCount < bitCount && pos + 1 < n ) {
                pos++;
                val = nums[pos];
                while ( val > 0 ) {
                    int tmp = log2(val);
                    if ( tmpMark[tmp] == 0 ) {
                        tmpCount++;
                    }
                    tmpMark[tmp]++;
                    val -= ( 1 << tmp );
                }
            }
            pos = max(pos,i);
            ans.push_back(pos - i + 1);
            val = nums[i];
            while ( val > 0 ) {
                int tmp = log2(val);
                if ( tmpMark[tmp] == 1 ) {
                    tmpCount--;
                }
                mark[tmp]--;
                tmpMark[tmp]--;
                if ( mark[tmp] == 0 ) {
                    bitCount--;
                }
                val -= ( 1 << tmp );
            }

        }
        return ans;
    }
};
