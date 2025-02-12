
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL) {}
};

Node* separate_ones_and_zeroes(Node* head){
    if(!head) return nullptr;
    
    Node* ones_head = nullptr;
    Node* zeroes_head = nullptr;
    Node* curr = head;
    Node* ones_curr = nullptr;
    Node* zeroes_curr = nullptr;

    while(curr){
        if(curr->val == 1){
            if(ones_head == nullptr){
                ones_head = new Node(1);
                ones_curr = ones_head;
            } else {
                ones_curr->next = new Node(1);
                ones_curr = ones_curr->next;
            }
        } else if(curr->val == 0){
            if(zeroes_head == nullptr){
                zeroes_head = new Node(0);
                zeroes_curr = zeroes_head;
            } else {
                zeroes_curr->next = new Node(0);
                zeroes_curr = zeroes_curr->next;
            }
        } 
        curr = curr->next;
    }

    curr = head;
    while(curr){
        if(curr->val != 1 && curr->val != 0){
            if(ones_head == nullptr){
                ones_head = new Node(curr->val);
                ones_curr = ones_head;
            } else {
                ones_curr->next = new Node(curr->val);
                ones_curr = ones_curr->next;
            }
        }
        curr = curr->next;
    }

    if(ones_curr){
        ones_curr->next = zeroes_head;
        return ones_head;
    }
    return zeroes_head;    
}

int main(){
    struct Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next = new Node(5);
    Node* newHead = separate_ones_and_zeroes(head);
    while(newHead){
        cout << newHead->val << " ";
        newHead = newHead->next;
    }

    return 0;
}