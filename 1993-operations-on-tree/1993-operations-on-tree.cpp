/**
 * @class LockingTree
 * @brief Implements a tree structure that supports lock, unlock, and upgrade operations.
 *
 * Each node can be locked by a specific user. The tree supports:
 *  - Locking a node (only if unlocked)
 *  - Unlocking a node (only by the same user)
 *  - Upgrade: lock a node only if it has locked descendants and no locked ancestors,
 *             and auto-unlocks all locked descendants.
 */
class LockingTree {
private:
    /**
     * @brief parent[i] = parent of node i.
     */
    vector<int> parent;

    /**
     * @brief children[i] = list of children of node i.
     */
    vector<vector<int>> children;

    /**
     * @brief lockedBy[i] = user ID that locked node i, or -1 if unlocked.
     */
    vector<int> lockedBy;

    /**
     * @brief lcd[i] = number of locked descendants under node i.
     */
    vector<int> lcd;

    #define lockedDescendantCount lcd

    /**
     * @brief Checks whether any ancestor of `num` is locked.
     * @param num Node index.
     * @return true if an ancestor is locked, false otherwise.
     */
    bool hasLockedAncestor(int num) {
        int p = parent[num];
        while (p != -1) {
            if (lockedBy[p] != -1) {
                return true;
            }
            p = parent[p];
        }
        return false;
    }

    /**
     * @brief Recursively unlocks all locked descendants of the given node.
     * @param num Node index.
     */
    void unlockDescendants(int num) {
        for (int child : children[num]) {
            unlockDescendants(child);
        }

        if (lockedBy[num] != -1) {
            int user = lockedBy[num];
            unlock(num, user);
        }
    }

public:
    /**
     * @brief Constructor: builds the tree from a parent array.
     * @param parent Parent array where parent[i] = parent of node i.
     */
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        children.resize(n);
        lockedBy.assign(n, -1);
        lcd.assign(n, 0);

        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                children[parent[i]].push_back(i);
            }
        }
    }

    /**
     * @brief Locks a node for a specific user.
     * @param num Node index.
     * @param user User ID.
     * @return true if lock succeeded, false if already locked.
     */
    bool lock(int num, int user) {
        if (lockedBy[num] != -1) {
            return false;
        }

        lockedBy[num] = user;

        int p = parent[num];
        while (p != -1) {
            lcd[p]++;
            p = parent[p];
        }
        return true;
    }

    /**
     * @brief Unlocks a node, only if unlocked by the same user.
     * @param num Node index.
     * @param user User ID.
     * @return true if unlock succeeded, false otherwise.
     */
    bool unlock(int num, int user) {
        if (lockedBy[num] != user) {
            return false;
        }

        lockedBy[num] = -1;

        int p = parent[num];
        while (p != -1) {
            lcd[p]--;
            p = parent[p];
        }
        return true;
    }

    /**
     * @brief Upgrades a node:
     *        - Node must be unlocked.
     *        - Node must have locked descendants.
     *        - No locked ancestors allowed.
     *        - Unlocks all descendants, then locks this node.
     *
     * @param num Node index.
     * @param user User ID.
     * @return true if upgrade succeeded, false otherwise.
     */
    bool upgrade(int num, int user) {
        if (lockedBy[num] != -1) {
            return false;
        }

        if (lcd[num] == 0) {
            return false;
        }

        if (hasLockedAncestor(num)) {
            return false;
        }

        unlockDescendants(num);
        return lock(num, user);
    }
};
