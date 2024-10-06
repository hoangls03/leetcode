class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        sentence1 += " ";
        sentence2 += " ";
        sentence1 = " " + sentence1;
        sentence2 = " " + sentence2;
        int n = sentence1.size();
        int m = sentence2.size();
        int pre = 0,suf = 0,count = 0;
        string s = "";
        if ( m > n ) swap(sentence1,sentence2);
        queue<string> q;
        for ( auto i : sentence2 ) {
            if ( i == ' ' ) {
                if ( s != "" ) q.push(s);
                s = "";
            }
            else s += i;
        }  
        count = q.size();
        s = "";
        for ( auto i : sentence1 ) {
            if ( i == ' ' ) {
                if ( s != "" ) {
                    if ( q.size() ) {
                        if ( q.front() == s ) {
                            q.pop();
                            pre++;
                        } else {
                            break;
                        }
                    }
                }
                s = "";
            } else {
                s += i;
            }
        }
        while ( q.size() ) {
            q.pop();
        }
        s = "";
        reverse(sentence1.begin(),sentence1.end());
        reverse(sentence2.begin(),sentence2.end());
        for ( auto i : sentence2 ) {
            if ( i == ' ' ) {
                if ( s != "" ) q.push(s);
                s = "";
            }
            else s += i;
        }  
        s = "";
        for ( auto i : sentence1 ) {
            if ( i == ' ' ) {
                if ( s != "" ) {
                    if ( q.size() ) {
                        if ( q.front() == s ) {
                            q.pop();
                            suf++;
                        } else {
                            break;
                        }
                    }
                }
                s = "";
            } else {
                s += i;
            }
        }
        if ( pre + suf >= count ) return true;
        return false;
    }
};
