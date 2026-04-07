/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head==NULL or head->next==NULL) {
            return head;
        }

        ListNode *cur=head, *prev=NULL, *nex;

        while(cur) {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }

        head=prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) {
            return 1;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next and fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        slow->next=reverse(slow->next);
        slow=slow->next;

        while(slow) {
            if(head->val!=slow->val) {
                return false;
            }
            slow=slow->next;
            head=head->next;
        }

        return true;
    }
};