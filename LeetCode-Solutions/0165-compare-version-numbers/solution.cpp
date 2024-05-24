class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();
        queue<int> vt1,vt2;
        int temp = 0;
        for ( auto i : version1 ) {
            if ( i == '.') {
                vt1.push(temp);
                temp = 0;
            }
            else temp = temp*10 + (i - '0');
        }
        vt1.push(temp);
        temp = 0;
        for ( auto i : version2 ) {
            if ( i == '.') {
                vt2.push(temp);
                temp = 0;
            }
            else temp = temp*10 + (i - '0');
        }
        vt2.push(temp);
        while( vt2.size() != 0 || vt1.size() != 0 ) {
            if ( vt1.size() != 0 ) {
                if ( vt2.size() != 0 ) {
                    if ( vt1.front() < vt2.front() ) {
                        return -1;
                    } 
                    else if ( vt1.front() > vt2.front() ) {
                        return 1;
                    }
                    else {
                        vt1.pop();
                        vt2.pop();
                    }
                }
                else {
                    if ( vt1.front() == 0 ) {
                        vt1.pop();
                    } else {
                        return 1;
                    }
                }
            } else {
                if ( vt2.size() != 0 ) {
                    if ( vt2.front() == 0 ) {
                        vt2.pop();
                    } else {
                        return -1;
                    }
                }
            }
        }
        return 0;
    }
};
