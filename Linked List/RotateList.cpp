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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* temp=head;
        int length=1;
        while(temp->next!=nullptr){
            temp=temp->next;
            length++;
        }

        k = k % length;

        if(k == 0)
            return head;

        temp->next=head;
        int steps=length-k-1;
        ListNode* newTail=head;
        while(steps--){
            newTail=newTail->next;
        }

        ListNode* newHead=newTail->next;
        newTail->next=nullptr;

        return newHead;
    }
};