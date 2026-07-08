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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* NthPtr=head;
        ListNode* fastptr=head;
        for(int i=0;i<n;i++){
            fastptr=fastptr->next;
        }

        if (fastptr == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(fastptr->next!=nullptr){
            fastptr=fastptr->next;
            NthPtr=NthPtr->next;
        }

        ListNode* temp=NthPtr->next;

        NthPtr->next=temp->next;

        delete(temp);

        return head;

    }
};
