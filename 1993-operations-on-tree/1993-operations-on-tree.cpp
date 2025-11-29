class LockingTree {
private: 
   vector<int> parent;
   vector<vector<int>> children;
   vector<int> lockedby;
   vector<int> lcd;

   bool haslockedancestors(int num) {
        int p=parent[num];
        while(p!=-1) {
            if(lockedby[p]!=-1) {
                return true;
            }
        }
        return false;
   }

   void unlockdescendants(int num) {
        for(int child: children[num]) {
            unlockdescendants(child);
            if(lockedby[child]!=-1) {
                int user=lockedby[child];
                unlock(child, user);
            }
        }
   }

public:
    LockingTree(vector<int>& parent) {
        int n=parent.size();
        this->parent=parent;
        children.resize(n);
        lockedby.assign(n, -1);
        lcd.assign(n, 0);

        for(int i=0;i<n;i++) {
            if(parent[i]!=-1) {
                children[parent[i]].push_back(i);
            }
        }
    }
    
    bool lock(int num, int user) {
        if(lockedby[num]!=-1) {
            return false;
        }

        lockedby[num]=user;
        int p=parent[num];
        while(p!=-1) {
            lcd[p]++;
            p=parent[p];
        }
        return true;
    }
    
    bool unlock(int num, int user) {
        if(lockedby[num]!=user) {
            return false;
        }

        lockedby[num]=-1;

        int p=parent[num];
        while(p!=-1) {
            lcd[p]--;
            p=parent[p];
        }
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (lockedby[num] != -1) {
            return false;
        }
        if (lcd[num] == 0) {
            return false;
        }

        if (haslockedancestors(num)) {
            return false;
        }

        unlockdescendants(num);
        return lock(num, user);
    }
};