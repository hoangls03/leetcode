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
    }

    int find(string s) {
        Node *p = root;
        int count = 0;
        for ( auto f : s ) {
            int c = f -'a';
            if ( p->child[c] == NULL ) return count;
            p = p->child[c];
            count += p -> cnt;
        } 
        return count;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for ( auto s : words ) {
            trie.add(s);
        }
        vector<int> ans;
        for ( auto s : words ) {
            ans.push_back(trie.find(s));
        }
        return ans;
    }
};
