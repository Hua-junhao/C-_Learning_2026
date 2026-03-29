class EventManager {
private:
    unordered_map<int,int>priority;
    set<pair<int,int>>activeEvents;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto event : events)
        {
            int id=event[0],pri=event[1];
            priority[id]=pri;
            activeEvents.insert({-pri,id});
        }
        
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(priority.find(eventId)!=priority.end())
        {
            int pri=priority[eventId];
            activeEvents.erase({-pri,eventId});
            priority[eventId]=newPriority;
            activeEvents.insert({-newPriority,eventId});

        }
        
    }
    
    int pollHighest() { 
        if(activeEvents.empty())
        {
            return -1;
        }
        auto it=activeEvents.begin();
        int id=it->second;
        activeEvents.erase(it);
        priority.erase(id);
        return id;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */©leetcode