/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

         if(head == nullptr)
          return nullptr;

        Node* temp=head;
        while(temp){
            Node* nextNode=temp->next;
            temp->next=new Node(temp->val);
            temp->next->next=nextNode;
            temp = nextNode;
        }

        temp=head;
        while(temp){
            Node* nextNode=temp->next;
            if(temp->random){
                nextNode->random=temp->random->next;
            }
           
            temp=temp->next->next;
        }



        temp=head;
        Node* newHead=head->next;

        while(temp){
            if(temp->next){
                Node* copyNode=temp->next;
                Node* nextNode=copyNode->next;

                if(nextNode){
                    copyNode->next=nextNode->next;
                }
                temp->next=nextNode;

                temp=nextNode;
            }
        }

        return newHead;
    }
};