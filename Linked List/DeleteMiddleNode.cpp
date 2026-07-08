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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* prev=nullptr;
        ListNode* fastptr=head;
        ListNode* slowptr=head;

        while(fastptr!=nullptr && fastptr->next!=nullptr){
            fastptr=fastptr->next->next;
            prev=slowptr;
            slowptr=slowptr->next;
        }

        ListNode* temp=slowptr;
        prev->next=temp->next;
        delete temp;
        return head;
    }
};