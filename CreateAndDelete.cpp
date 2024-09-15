#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
     //constructor 
    node(int value){
        data=value;
        next= nullptr;
    }
};
void insertAtNode(node*& head,  int element){
    node* newN= new node(element);
    if(head==nullptr){
        head=newN;
        return;
    }
    node* temp= head;
    //transversing to the last node
    while(temp->next!= nullptr){
        temp= temp->next;
    }
    temp->next=newN;
}
void display(node* head){
    node* tem= head;
    while(tem!=nullptr){
        cout<<tem->data<<"->";
        tem=tem->next;
    }
    cout<<"NULL"<<endl;
}
void deleteTheF(node*& head){
    node* del= head;
    head=head->next;
    delete del;
}
void deleteTheL(node*& head){
    //if list has no elements
    if(head==nullptr){
        return;
    }
    //if list has only one element
    if(head->next==nullptr){
        delete head;
        head= nullptr;
        return;
    }
    node* temp= head;
    //We have to transverse to the last second
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    node* del = temp->next;
    temp->next=nullptr;
    delete del;
}
void deleteAtP(node*& head, int position){
    //If list is empty
    node* temp= head;
    if(head==nullptr){
        return;
    }
    //if it is on 0th position element
    if(position==0){
        head= temp->next;//change head to the next node
        delete temp;//delete the old memory
        return;
    }
    //iterating to position last element---
    for(int i = 0 ; temp != nullptr && i<position-1; i++){
        temp=temp->next;
    }
    //node to be deleted is the node next to the node at which we currently are
    if(temp== nullptr || temp->next== nullptr){
        cout<<"Position out of range"<<endl;
        return;
    }
    node* delp= temp->next;
    //jo node delete krna hain uske phele wale ko uske agle se agle mtlb ki n node k n+1 se link kr rha
    temp-> next= temp->next->next;
    delete delp;
    
}
int main(){
    node* head= nullptr;
    int n;
    cout<<"Number of elements in the linked list: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++){
        int element;
        cin>>element;
        insertAtNode(head, element);
    }
    int valueP;
    cout<<"enter the position to be deleted: ";
    cin>>valueP;
    display(head);
    cout<<"Delete the first-->"<<endl;
    deleteTheF(head);
    display(head);
    cout<<"Delete the last-->"<<endl;
    deleteTheL(head);
    display(head);
    cout<<"Delete at the "<<valueP<<"th position -->"<<endl;
    deleteAtP(head,valueP);
    display(head);
    return 0;

}
