#include <bits/stdc++.h> 

using namespace std;


    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };


Node<int>* reverseLinkedList(Node<int>* head) {
    Node<int>* prev = nullptr;
    Node<int>* curr = head;

    while (curr != nullptr) {
        Node<int>* nextNode = curr->next; 
        curr->next = prev;           
        prev = curr;                
        curr = nextNode;            
    }

    return prev; 
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    Node<int>* l1 = reverseLinkedList(first);
    Node<int>* l2 = reverseLinkedList(second);

    int carry = 0;

    Node<int>* head = nullptr;
    

    while(l1 || l2){
        int x = (l1) ? l1->data : 0;

        int y = (l2) ? l2->data : 0;

        int sum = x + y + carry;

        carry = sum / 10;

        Node<int>* newNode = new Node(sum % 10);
        newNode->next =nullptr;

        if(head == nullptr){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;


        

        
   }


    if (carry > 0) {
        Node<int>* newNode = new Node<int>(carry);
        newNode->next = head;
        head = newNode;
    }

   return head;

}

Node<int> *oddEvenLinkedList(Node<int> *head) {
    if(head == nullptr || head->next == nullptr){
        return head;
    }


    Node<int>* odd = head;
    Node<int>* even = head->next;
    Node<int>* evenHead = head->next;


    while(even != nullptr && even->next !=nullptr){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;

    }

    odd->next = evenHead;
    return head;
}

int lengthOfLoop(Node<int> *head) {
    if(head == NULL){
        return 0;
    }

    Node<int>* f = head;
    Node<int>* s = head;

    while(f != NULL && f->next!=NULL){
        f = f->next->next;
        s = s->next;

        if(f == s){
            int len = 1;
            s = s->next;

            while(s != f){
                s = s->next;
                len++;
            }
            return len;
        }
    }

    return 0;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

bool isPalindrome(Node<int> *head)
{
    
    if(head == nullptr || head->next == nullptr){
        return true;
    }


    Node<int>* fast = head;
    Node<int>* slow = head;


    while(fast!=nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;

    }
        slow->next = reverseLinkedList(slow->next);

        Node<int>* temp1 = head;

        Node<int>* temp2 = slow->next;

        while(temp2 !=nullptr){
            if(temp1->data != temp2->data){
                return false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    return true;

}

    

 









 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL) return head;

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0 ; i < n ; i++){
            fast = fast->next;
        }

        if(fast == NULL){
            ListNode* del = head;
            head = head->next;
            delete del;

            return head;
        }

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;    
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;

        delete(del);


        
            
        return head;
        
        }


        ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* temp = head;

        while(temp->next != slow){
            temp = temp->next;
        }


        temp->next = slow->next;
        delete(slow);


        return head;


    }

    Node<int> *firstNode(Node<int> *head)
{
    Node<int>* fast = head;
    Node<int>* slow = head;


    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            slow = head;
            while(fast != slow){
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}


    
};