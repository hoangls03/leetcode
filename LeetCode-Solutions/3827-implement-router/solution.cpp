#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Packet {
    int s, d, t;
};

struct KeyHash {
    size_t operator()(const array<int,3>& a) const noexcept {
        // simple hash combine
        long long h =  (((ll)a[0] << 40) | ((ll)a[1] << 20) | (ll)a[2]); 
        return h;
    }
};

struct KeyEq {
    bool operator()(const array<int,3>& a, const array<int,3>& b) const noexcept {
        return a[0]==b[0] && a[1]==b[1] && a[2]==b[2];
    }
};

class Router {
public:
    queue<Packet> q;
    // Track duplicates of (source,destination,timestamp)
    unordered_set<array<int,3>, KeyHash, KeyEq> seen;
    int limit = 1;

    // For each destination -> timestamps (in arrival order for that destination)
    unordered_map<int, vector<int>> mark;

    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        array<int,3> k{source, destination, timestamp};
        if (seen.find(k) != seen.end()) return false;

        // evict if full
        if ((int)q.size() >= limit) {
            const Packet &u = q.front();
            // remove from seen and per-destination list
            seen.erase(array<int,3>{u.s, u.d, u.t});
            auto &lst = mark[u.d];
            if (!lst.empty()) {
                // oldest for this destination is at front
                lst.erase(lst.begin());
                if (lst.empty()) mark.erase(u.d);
            }
            q.pop();
        }

        // add new
        seen.insert(k);
        mark[destination].push_back(timestamp);
        q.push(Packet{source, destination, timestamp});
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet cur = q.front(); q.pop();
        // remove from seen
        seen.erase(array<int,3>{cur.s, cur.d, cur.t});
        // remove oldest timestamp for this destination
        auto &lst = mark[cur.d];
        if (!lst.empty()) {
            lst.erase(lst.begin());
            if (lst.empty()) mark.erase(cur.d);
        }
        return {cur.s, cur.d, cur.t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = mark.find(destination);
        if (it == mark.end()) return 0;
        const vector<int> &items = it->second; // no copy

        // NOTE: This relies on items being non-decreasing by timestamp.
        // If timestamps can arrive out-of-order, switch to a multiset<int>
        // for each destination and use lower_bound/upper_bound on that.
        int r = int(upper_bound(items.begin(), items.end(), endTime) - items.begin());
        int l = int(lower_bound(items.begin(), items.end(), startTime) - items.begin());
        return r - l;
    }
};
