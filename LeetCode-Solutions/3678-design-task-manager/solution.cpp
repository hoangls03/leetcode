#define ii pair<int,int>
#define fi first
#define se second

class TaskManager {
public:
    map<int,int> taskUser;
    map<int,int> taskPrio;
    priority_queue<ii> tasksPq;
    TaskManager(vector<vector<int>>& tasks) {
        for ( auto i : tasks ) {
            tasksPq.push({i[2],i[1]});
            taskUser[i[1]] = i[0];
            taskPrio[i[1]] = i[2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasksPq.push({priority,taskId});
        taskUser[taskId] = userId;
        taskPrio[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        taskPrio[taskId] = newPriority;
        tasksPq.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        taskPrio[taskId] = -1;
    }
    
    int execTop() {
        while ( tasksPq.size() ) {
            auto u = tasksPq.top();
            tasksPq.pop();
            if ( u.fi == taskPrio[u.se] ) {
                taskPrio[u.se] = -1;
                return taskUser[u.se];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
