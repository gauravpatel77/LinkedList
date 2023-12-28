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
    head->prev=tail;
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
    tail->prev=head;
}

int findLength(Node *&head,Node *&tail)
{
    int len = 1;
    Node *temp = head;
    while (temp != tail)
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
    int len=findLength(head,tail);
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

void print(Node* &head,Node* &tail){
    Node* temp = head;
    while(temp != tail){
        cout<<temp->data<<", ";
        temp = temp->next;
    }
    cout<<tail->data<<", ";
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
    head->prev=tail;
    tail->next=head;
}

void deleteattail(Node* &head,Node* &tail){
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next=NULL;
    tail->prev=NULL;
    Node* x=tail;
    temp=tail;
    delete x;
    head->prev=tail;
    tail->next=head;
}

void deleteatmiddle(Node* &head,Node* &tail){
    Node* temp = head;
    int len=findLength(head,tail);
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

Node* search(Node* head,int data,Node* tail){
    Node* search=head;
    while(search!=tail){
        if(search->data==data){
            return search;
        }
        search=search->next;
    }
}


int main(){
    Node* head=new Node(10);
    Node* snd=new Node(20);
    Node* trd=new Node(30);
    Node* frth=new Node(40);
    head->next=snd;
    snd->prev=head;
    snd->next=trd;
    trd->prev=snd;
    trd->next=frth;
    frth->prev=trd;
    head->prev=frth;
    frth->next=head;
    Node* tail=frth;

    cout<<"Length: "<<findLength(head,tail)<<endl;
    
    // insertatHead(head,tail,5);
    // insertatTail(head,tail,50);
    // insertatmiddle(head,tail,411);

    // deleteathead(head,tail);
    // deleteattail(head,tail);
    // deleteatmiddle(head,tail);

    print(head,tail);
}