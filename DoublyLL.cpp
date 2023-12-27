#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void insertatHead(Node* &head,Node* &tail,int data){
    Node* newnode = new Node(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void insertatTail(Node* &head,Node* &tail,int data){
    Node* newnode = new Node(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}
int findLength(Node *&head)
{
    int len = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertatmiddle(Node* &head,Node* &tail,int data){
    Node* newnode = new Node(data);
    if(head==NULL || tail==NULL){
        head=newnode;
        tail=newnode;
    }

    Node* temp = head;
    int len=findLength(head);
    temp=head;
    for(int i=1;i<(len/2);i++){
        temp=temp->next;
    }
    Node* x=temp->next;
    newnode->next=x;
    x->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<", ";
        temp = temp->next;
    }
}

void deleteathead(Node* &head,Node* &tail){
    if(head==NULL){
        cout<<"Linkedksit is empty"<<endl;
        return;
    }

    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    head->prev=NULL;
    delete temp;
}

void deleteattail(Node* &head,Node* &tail){
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=NULL;
    tail->prev=NULL;
    Node* x=tail;
    temp=tail;
    delete x;
}

void deleteatmiddle(Node* &head,Node* &tail){
    Node* temp = head;
    int len=findLength(head);
    temp=head;
    for(int i=1;i<(len/2);i++){
        temp=temp->next;
    }

    Node* forward=temp->next;
    Node* mff=forward->next;
    temp->next=forward->next;
    mff->prev=temp;
    forward->next=NULL;
    forward->prev=NULL;
    delete forward;
}

Node* search(Node* head,int data){
    Node* search=head;
    while(search!=NULL){
        if(search->data==data){
            return search;
        }
        search=search->next;
    }
}

void reverse(Node* &head,Node* &tail){
    Node* pre=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* ford=curr->next;
        curr->next=pre;
        if(pre!=NULL) pre->prev=curr;
        pre=curr;
        curr=ford;
    }
    head=pre;
}

int main(){
    Node* head=new Node(10);
    Node* tail = head;
    insertatTail(head,tail,20);
    insertatTail(head,tail,30);
    insertatTail(head,tail,40);
    insertatTail(head,tail,50);
    insertatmiddle(head,tail,500);
    // deleteathead(head,tail);
    // deleteattail(head,tail);
    // deleteatmiddle(head,tail);
    reverse(head,tail);
    print(head);
}