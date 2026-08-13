class Solution {
public:
    struct st {
        int pref, suf, maxVal, tot;
    };

    st cal(st a, st b) {
        st ans;
        ans.pref = a.pref;
        ans.suf = b.suf;
        ans.tot = a.tot + b.tot;
        if ( a.pref == a.tot ) {
            ans.pref += b.pref;
        }

        if ( b.suf == b.tot ) {
            ans.suf += a.suf; 
        }
        ans.maxVal = max({ans.pref,ans.suf,a.maxVal,b.maxVal,a.suf + b.pref});
        
        return ans;
    }

    void update(int id, int l, int r, int pos, int val, vector<st>& seg) {
        if ( pos < l || pos > r ) return ;
        if ( l == r ) {
            seg[id].pref = seg[id].suf = seg[id].maxVal = val;
            seg[id].tot = 1;
            return ;
        }
        int mid = (l + r)>>1;
        update(id*2,l,mid,pos,val,seg);
        update(id*2 + 1,mid + 1,r,pos,val,seg);
        seg[id] = cal(seg[id*2],seg[id*2 + 1]);
    }

    st get(int id, int l, int r, int u, int v, vector<st>& seg){
        if ( v < l || r < u ) {
            return {0,0,0,0};
        }

        if ( u <= l && r <= v ) {
            return seg[id];
        }

        int mid = (l + r)>>1;
        
        st left = get(id*2,l,mid,u,v,seg);
        st right = get(id*2+1,mid + 1,r,u,v,seg);
        return cal(left,right);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        s = " " + s;
        s += " ";
        vector<st> seg(4*(n + 2),{0,0,0});
        for ( int i = 1 ; i <= n ; ++i ) {
            update(1,1,n,i,(s[i] == s[i-1]),seg);
           
        }
        vector<int> ans;
        for ( int i = 0 ; i < queryIndices.size() ; ++i ) {
            int index = queryIndices[i] + 1;
            s[index] = queryCharacters[i];
            update(1,1,n,index,(s[index] == s[index - 1]),seg);
            if ( index + 1 <= n ) {
                update(1,1,n,index + 1,(s[index] == s[index + 1]),seg);
            }
            ans.push_back(get(1,1,n,1,n,seg).maxVal + 1);
        }
        return ans;
    }
};
