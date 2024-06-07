struct Trie{
    struct Node {
        Node* child[26];
        int exist, cnt;

        Node() {
            for ( int i = 0 ; i < 26 ; ++i ) {
                child[i] = NULL;
            }
            exist = 0;
            cnt = 0;
        }
    };

    int cur;
    Node* root;
    Trie() : cur(0) {
        root = new Node();
    };
    
    void add(string s) {
        Node *p = root;
        for ( auto f : s ) {
            int c = f -'a';
            if ( p->child[c] == NULL ) p->child[c] = new Node();

            p = p->child[c];
            p->cnt++;
        }
        p->exist++;
    }

    string find(string s) {
        Node *p = root;
        string temp;
        for ( auto f : s ) {
            int c = f -'a';
            if ( p->child[c] == NULL ) return s;
            temp += f;
            p = p->child[c];
            if ( p->exist ) {
                return temp;
            }
        } 
        return s;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for ( auto s : dictionary ) {
            trie.add(s);
        }

        stringstream list(sentence);
        string s;
        string ans;
        while( list >> s) {
            if ( ans.size() ) {
                ans += " ";
            }
            ans += trie.find(s);
        }
        return ans;
    }
};
