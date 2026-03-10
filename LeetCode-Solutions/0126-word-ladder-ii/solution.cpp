#define ii pair<string,vector<vector<string>>>
#define fi first
#define se second
class Solution {
public:
    unordered_map<string,bool> mark; 
    unordered_map<string,vector<string>> neighbor;
    unordered_map<string,int> vis;
    int shortest = 0;
    void BFS( string& start, string& end, vector<vector<string>>& ans ) {
        int n = start.size();
        queue<string> q;
        q.push(start);
        vis[start] = 1;

        while ( q.size() ) {
            auto u = q.front();
            string s = u;
            q.pop();
            if ( s == end ) {
                break;
            }
            string tmp = s;
            for ( int i = 0 ; i < n ; ++i ) {
                char ch = s[i];
                for ( char j = 'a' ; j <= 'z' ; ++j ) {
                    if ( s[i] != j ) {
                        s[i] = j;
                        if ( mark[s] && (vis[s] == 0 || vis[s] >= vis[tmp] + 1) ) {
                            if ( vis[s] == 0 ) {
                                neighbor[s].push_back(tmp);
                                q.push(s);
                            } else{
                                if ( vis[s] > vis[tmp] + 1) {
                                    neighbor[s].clear();
                                }
                                neighbor[s].push_back(tmp);
                            }
                            vis[s] = vis[tmp] + 1;
                        }
                    }
                    s[i] = ch;
                }
            }
        }
    }
    vector<vector<string>> travel(string start, string cur) {
        vector<vector<string>> ans;
        if ( cur == start ) {
            return {{start}};
        }
        for ( auto s : neighbor[cur] ) {
            cout<<cur<<" "<<s<<'\n';
            auto paths = travel(start,s);
            for ( auto path : paths ) {
                path.push_back(cur);
                ans.push_back(path);
            }
        }
        return ans;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        mark.clear();
        neighbor.clear();
        vis.clear();
        for ( auto s : wordList ) {
            mark[s] = true;
        }
        vector<vector<string>> ans = {};
        BFS(beginWord, endWord, ans);
        return travel(beginWord, endWord);
    }
};
