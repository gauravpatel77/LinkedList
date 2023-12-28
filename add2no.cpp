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

Node* sum(Node* l1, Node* l2){
    int sum=0;
    int carry=0;
    Node* anshead=new Node(0);
    Node* anstail=anshead;
    while(l1!=NULL && l2!=NULL){
        sum=l1->data+l2->data+carry;
        // cout<<"l1data: "<<l1->data<<endl;
        // cout<<"l2data: "<<l2->data<<endl;
        // cout<<"carry: "<<carry<<endl;
        // cout<<"sum: "<<sum<<endl;
        carry=sum/10;
        sum=sum%10;
        Node* newnode=new Node(sum);
        anstail->next=newnode;
        anstail=newnode;
        cout<<"anstail: "<<anstail->data<<endl;

        l1=l1->next;
        l2=l2->next;
    }

    while(l1!=NULL){
        sum=l1->data+carry;
        sum=sum%10;
        carry=sum/10;
        Node* newnode=new Node(sum);
        anstail->next=newnode;
        anstail=newnode;
        cout<<"ddanstail: "<<anstail->data<<endl;
        l1=l1->next;
    }

    while(l2!=NULL){
        sum=l2->data+carry;
        sum=sum%10;
        carry=sum/10;
        Node* newnode=new Node(sum);
        anstail->next=newnode;
        anstail=newnode;
        l2=l2->next;
    }

    while(carry!=0){
        sum=carry;
        sum=sum%10;
        carry=sum/10;
        Node* newnode=new Node(sum);
        anstail->next=newnode;
        anstail=newnode;
    }
    cout<<"ans: ";
    print(anshead->next);
    cout<<endl;
    return anshead->next;
}

int main(){
    Node* l1=new Node(2);
    Node* l12=new Node(4);
    Node* l13=new Node(3);
    l1->next=l12;
    l12->next=l13;
    l13->next=NULL;

    Node* l2=new Node(9);
    Node* l22=new Node(4);
    // Node* l13=new Node(3);
    l2->next=l22;
    // l12->next=l13;
    l22->next=NULL;

    sum(l1,l2);
    print(l1);
    cout<<endl;
    print(l2);
    cout<<endl;
    
}