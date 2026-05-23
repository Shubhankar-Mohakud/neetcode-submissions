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

using ln = ListNode;
class Solution {
public:
    int getLength(ln* head){
        ln* curr = head;
        int count = 0;
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;

        if(getLength(head)<k) return head;

        ln* prev=NULL;
        ln* curr=head;
        int position=0;
        while(position < k){
            ln* fwd = curr->next;
            curr->next = prev;
            prev=curr;
            curr = fwd;
            position++;
        }

        if(curr != NULL){
            head->next = reverseKGroup(curr, k);
        }
        return prev;
    }
};