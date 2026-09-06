class Solution {
private:
    ListNode* heads;
public:
    Solution(ListNode* head) {
        heads=head;
    }
    
    int getRandom() {
        int count=1, chosenValue=0;
        ListNode* curr = heads;
        while(curr!=NULL) {
           if(rand()%count<1.0/count) {
               chosenValue=curr->val;
           }
           count++;
           curr=curr->next;
        }
         
        return chosenValue;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */