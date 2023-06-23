#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
     int val;
     Node* next;
    Node(int val) {
        this->val=val;
        this->next=NULL;

    }
};
void input(Node *&head, Node *&tail,int val){
    Node * newNode = new Node(val);
    if(head==NULL){
        head= newNode;
        tail= newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
    
}
void print(Node * head){
    Node * tmp= head;
    while(tmp!=NULL){
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
int main(){
    Node * head = NULL;
    Node * tail= NULL;
    int val;
    while(true){
        cin>>val;
        if(val==-1) break;
        input(head, tail, val);
    }
    Node* tmp= head;
    while(tmp!=NULL && tmp->next!=NULL){
        Node * tmp2=tmp;
        while(tmp2->next!=NULL){
            if(tmp->val==tmp2->next->val){
                Node * deleteNode= tmp2->next;
                tmp2->next=tmp2->next->next;
                delete deleteNode;
            }
            else{
                tmp2=tmp2->next;
            }

        }
        tmp=tmp->next;
    }
    for(Node * i=head; i->next!=NULL; i=i->next){
        for(Node * j=i->next; j!=NULL; j=j->next){
            if(i->val>j->val){
                swap(i->val, j->val);
            }
           

        }
    }
    print(head);
    return 0;
}