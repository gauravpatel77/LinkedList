#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertatTail(Node* &head,Node* &tail,int data){
    Node* newnode = new Node(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    tail->next=newnode;
    tail=newnode;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<", ";
        temp = temp->next;
    }
}
Node* swapPairs(Node* head) {
        if (head==NULL) return head;
        if(head->next==NULL) return head;
        Node* hh=new Node(0);
        hh->next=head;
        Node* pre=hh;
        Node* curr=head;

        while(pre->next!=NULL && curr->next!=NULL){
            pre->next=curr->next;
            curr->next=curr->next->next;
            pre->next->next=curr;

            pre=curr;
            curr=curr->next;
        }
    return hh->next;
}


int main(){
    Node* head=new Node(10);
    Node* tail = head;
    insertatTail(head,tail,20);
    insertatTail(head,tail,30);
    insertatTail(head,tail,40);
    print(head);
    cout<<endl;
    Node* a=swapPairs(head);
    print(a);
}