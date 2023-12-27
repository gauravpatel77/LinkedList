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

void insertatHead(Node* &head,Node* &tail,int data){
    Node* newnode = new Node(data);
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    newnode->next=head;
    head=newnode;
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
    newnode->next=temp->next;
    temp->next=newnode;
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
    }

    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}

void deleteattail(Node* &head,Node* &tail){
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=NULL;
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
    cout<<"temp data: "<<temp->data<<endl;
    Node* forward=temp->next;
    temp->next=forward->next;
    forward->next=NULL;
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
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* ford=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ford;
    }
    head=prev;
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