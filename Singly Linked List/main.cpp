#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

struct SLL{
    Node *head=NULL;
    void InsertAtHead(int d);
    void InsertAtEnd(int d);
    void InsertAtAnyposition(int d, int position);
    void DeleteHead();
    void DeleteTail();
    void DeleteAnyPosition(int position);
    int MaximumValue();
    int MinimumValue();
    void SearchItem(int value);


    void print();
};

void SLL::print(){
    if(head==NULL){
        cout<<"List is empty";
    }
    else{
        Node*h=head;
        while(h!=NULL){
            cout<<h->data<<endl;
            h=h->next;
        }
    }
}

void SLL::InsertAtHead(int d){
    Node *n=new Node(d);

    if(head==NULL){
        head=n;
    }
    else{
        n->next=head;
        head=n;
    }
}

void SLL::InsertAtEnd(int d){
    Node *n=new Node(d);
    if(head==NULL){
        head=n;
    }
    else{
        Node *h=head;
        while(h->next!=NULL){
            h=h->next;
        }
        h->next=n;
    }
}

void SLL::InsertAtAnyposition(int d, int position){
    Node *n=new Node(d);
    if(position==1){
        n->next=head;
        head=n;
    }
    else{
        Node *h=head;
        for(int i=1; i<=position-2;i++){
            h=h->next;

        }
        n->next = h->next;
        h->next = n;
    }

}

void SLL::DeleteHead(){
    if(head==NULL){
        cout<<"The List Is Empty";
    }
    else{
        Node *h=head;
        head=head->next;
        delete h;
    }
}

void SLL::DeleteTail(){
    if(head==NULL){
        cout<<"The List is empty";
    }
    else if(head->next==NULL){
        delete head;
        head=NULL;
    }
    else{
        Node *h=head;
        while(h->next->next!=NULL){
            h=h->next;
        }
        Node *g=h->next;
        h->next=NULL;
        delete g;
    }
}
void SLL::DeleteAnyPosition(int position){
    if(head==NULL){
        cout<<"List is empty";
    }
    else if(position==1){
        Node *h = head;
        head = head->next;
        delete h;
    }
    else{
        Node *h=head;
        for(int i=0; i<=position-2;i++){
            h=h->next;
        }
        Node *g;
        g=h->next;
        h->next=g->next;
        delete g;
    }


}

int SLL::MaximumValue(){
    if (head == NULL) {
        cout << "The list is empty" << endl;


    }

    Node *h=head;

    int maxvalue= head->data;
    while(h!=NULL){
        if(h->data>maxvalue){
            maxvalue=h->data;
        }
        h=h->next;
    }
    cout<<"Max Value: "<<maxvalue<<endl;
}
int SLL::MinimumValue(){
    if (head == NULL) {
        cout << "The list is empty" << endl;


    }

    Node *h=head;

    int minvalue= head->data;
    while(h!=NULL){
        if(h->data<minvalue){
            minvalue=h->data;
        }
        h=h->next;
    }
    cout<<"Min value "<<minvalue<<endl;
}

void SLL::SearchItem(int value) {
    Node* h = head;
    int position = 1;
    while (h != NULL) {
        if (h->data == value) {
            cout << "Value " << value << " found at position " << position << endl;
            return;
        }
        h = h->next;
        position++;
    }
    cout << "Value " << value << " not found in the list" << endl;
}


int main(){
    SLL lists;
    lists.InsertAtHead(10);
    lists.InsertAtHead(14);
    lists.InsertAtHead(1);
    lists.InsertAtHead(1);
    lists.InsertAtEnd(599);
    lists.InsertAtAnyposition(333,2);
    lists.DeleteAnyPosition(3);
    lists.MaximumValue();
    lists.MinimumValue();
    lists.SearchItem(599);




    lists.print();
}
