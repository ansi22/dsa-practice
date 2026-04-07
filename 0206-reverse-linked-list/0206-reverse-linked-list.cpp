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
    ListNode* iterative(ListNode* head) {
        ListNode* prev=NULL, *cur=head, *next_p;

        while(cur) {
            next_p=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next_p;
        }

        head=prev;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        return iterative(head);
    }
};