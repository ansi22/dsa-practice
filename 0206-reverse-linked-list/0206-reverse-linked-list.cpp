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
    ListNode* iteration(ListNode* head) {
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

    ListNode* recursive(ListNode* head) {
        if(!head or !head->next) {
            return head;
        }

        ListNode* newHead = recursive(head->next);
        ListNode* prev = head->next;
        prev->next=head;
        head->next=NULL;
        return newHead;

    }

    ListNode* reverseList(ListNode* head) {
        // return iteration(head);
        return recursive(head);
    }
};