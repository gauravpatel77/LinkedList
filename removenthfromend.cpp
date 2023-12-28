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

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<", ";
        temp = temp->next;
    }
}

int getlength(Node* head){
        Node* temp=head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }

Node* removenthnode(Node* head,int n){
        if(head==NULL){
            return NULL;
        }

        if(head->next==NULL && n>0){
            return NULL;
        }
        int len = getlength(head);
        cout<<"Len: "<<len<<endl;
        int x=len-n;
        
        if(n>=len){
            head=head->next;
        }

        Node* curr=head;
        for(int i=0;i<x-1;i++){
            curr=curr->next;
        }
        if(curr->next!=NULL && len>n)
            curr->next=curr->next->next;
        return head;
}

void insertatTail(Node* &head,Node* &tail,int data){
    Node* newnode = new Node(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    tail->next=newnode;
    tail=newnode;
}

int main(){
    Node* head= new Node(1);
    Node* tail = head;
    insertatTail(head,tail,2);
    insertatTail(head,tail,3);
    insertatTail(head,tail,4);
    insertatTail(head,tail,5);
    print(head);
    int n=2;

    removenthnode(head,n);
    print(head);
}