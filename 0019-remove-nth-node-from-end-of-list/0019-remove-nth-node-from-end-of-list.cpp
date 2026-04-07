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
    ListNode* brute(ListNode* head, int n) {
        if(head==NULL) {
            return head;
        }
        ListNode* temp=head;
        int cnt=0;

        while(temp) {
            cnt++;
            temp=temp->next;
        }

        if(cnt==n) {
            ListNode* nextNode=head->next;
            delete(head);
            return nextNode;
        }

        int st=cnt-n;
        temp=head;

        while(temp) {
            st--;
            if(st==0) {
                break;
            }

            temp=temp->next;
        }

        ListNode* reqNode=temp->next;
        temp->next=temp->next->next;
        delete(reqNode);
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return brute(head, n);
    }
};