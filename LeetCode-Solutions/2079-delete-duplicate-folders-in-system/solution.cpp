#define fi first
#define se second

class Solution {
public:
    struct Trie {
        map<string,Trie*> child;
        string id = "";
        bool mark = false;
        
        Trie(string id = "") : id(id) {
        };

        void insert(vector<string>& path ) {
            Trie* Node = this;
            for ( auto s : path ) { 
                if ( Node->child[s] == NULL ) {
                    Node->child[s] = new Trie(s);
                }
                Node = Node -> child[s];
            }

        }
    };
    Trie trie;
    map<string,Trie*> mp;
    
    string DFS(Trie* Node ) {
        if ( Node->child.empty() ) {
            return "";
        }
        vector<pair<string,Trie*>> nodes(Node->child.begin(),Node->child.end());

        sort(nodes.begin(),nodes.end());

        string cur;
        for ( auto i : nodes ) {
            cur += "(" + i.fi + DFS(i.se) + ")";
        }

        if ( mp[cur] ) {
            mp[cur] -> mark = true;
            Node -> mark = true;
        } else {
            mp[cur] = Node;
        }
        return cur;
    }
    
    void addAns(Trie* Node, vector<string>& path, vector<vector<string>>& ans) {
        for ( auto i : Node -> child ) {
            if ( i.se -> mark ) {
                continue;
            }
            path.push_back(i.fi);
            ans.push_back(path);
            addAns(i.se,path,ans);
            path.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for ( auto path : paths ) {
            trie.insert(path);
        }
        DFS(&trie);
        vector<string> path;
        vector<vector<string>> ans;
        addAns(&trie,path,ans);
        return ans;
    }
};
