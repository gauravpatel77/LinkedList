
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

Node* rotateRight(Node* head, int k) {
        if(head==NULL) return head;
        if(head->next==NULL) return head;
        int n=0;
        Node* gp=head;
        while(gp!=NULL){
            gp=gp->next;
            n++;
        }
        cout<<"n: "<<n<<endl;
        k=k%n;
        cout<<"k: "<<k<<endl;
        if(k==0) return head;
        Node* temp=head;
        for(int i=1;i<(n-k);i++){
            temp=temp->next;
            cout<<"temp: "<<temp->data<<endl;
        }

        Node* nh=temp->next;
        cout<<"nh: "<<nh->data<<endl;
        temp->next=NULL;

        Node* nt=nh;
        for(int i=1;i<k;i++){
            nt=nt->next;
        }
        nt->next=head;

        return nh;
    }


int main(){
    Node* head=new Node(10);
    Node* tail = head;
    insertatTail(head,tail,20);
    insertatTail(head,tail,30);
    insertatTail(head,tail,40);
    insertatTail(head,tail,50);
    print(head);
    cout<<endl;
    Node* a=rotateRight(head,2);
    print(a);
}