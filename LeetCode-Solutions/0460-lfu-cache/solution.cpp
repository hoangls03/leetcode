#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first 
#define se second
class LFUCache {
public:
    int counter[100001], cache[100001], lastUsed[100001];
    int maxCap = 0, currentCap = 0, timeLine = 0;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    LFUCache(int capacity) {
        maxCap = capacity;
        currentCap = 0;
        for (int i = 0 ; i <= 100000 ; ++i ) {
            counter[i] = 0;
            cache[i] = -1;
        }
    }
    
    int get(int key) {
        
        timeLine += 1;
        if ( cache[key] != -1 ) {
            counter[key] += 1;
            lastUsed[key] = timeLine;
        }
        return cache[key];
    }
    
    void put(int key, int value) {
        timeLine += 1;
        
        if ( cache[key] == -1 ) {
            if ( currentCap < maxCap ) {
            currentCap += 1;
            } else {
            while ( true ) {
                auto val = pq.top();
                pq.pop();
                int freq = val.fi.fi;
                int time = val.fi.se;
                int keyVal = val.se;
                if ( lastUsed[keyVal] != -1 ) {
                    pq.push({{counter[keyVal],lastUsed[keyVal]},keyVal});
                    lastUsed[keyVal] = -1;
                } else {
                    counter[keyVal] = 0;
                    cache[keyVal] = -1;
                    break;
                    } // O(log(total_elemnts of the queue)) -> O(nlog(n)) , avarage (O(n))
                }
            }
            
            pq.push({{1,timeLine},key});
        }

        counter[key] += 1;
        lastUsed[key] = timeLine;
        
        cache[key] = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
