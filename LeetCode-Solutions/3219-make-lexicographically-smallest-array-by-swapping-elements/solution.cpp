class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> cloneNum = nums;
        sort(cloneNum.begin(),cloneNum.end());
        map<int,int> mark;
        int n = nums.size();
        mark[cloneNum[0]] = 0;
        queue<int> q;
        q.push(cloneNum[0]);
        int pos = 0;
        vector<queue<int>> vq;
        for ( int i = 1 ; i < n ; ++i ) {
            if ( cloneNum[i] - cloneNum[i-1] > limit ) {
                vq.push_back(q);
                while ( q.size() ) {
                    q.pop();
                }
                pos++;
            }
            mark[cloneNum[i]] = pos;
            q.push(cloneNum[i]);
        }
        vq.push_back(q);
        vector<int> ans;
        for ( int i = 0 ; i < n ; ++i ) {
            ans.push_back(vq[mark[nums[i]]].front());
            vq[mark[nums[i]]].pop();
        }
        return ans;
    }
};
