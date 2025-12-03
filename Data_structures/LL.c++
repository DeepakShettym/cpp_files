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