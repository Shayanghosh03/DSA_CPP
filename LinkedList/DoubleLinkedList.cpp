#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node() {
      int value = this -> data;
      if(this -> next != NULL) {
        this -> next = NULL;
        this -> prev = NULL;
      }
      cout<<value<<" is deleted"<<endl;  
    }
};

void insertHead(Node* &Head,Node* &Tail, int data) {
    if(Head == NULL) {
        Node* newNode = new Node(data);
        Head = newNode;
        Tail = newNode;
        return;
    }
    Node* temp = new Node(data);
    temp -> next = Head;
    Head -> prev = temp;
    Head = temp;
}
void insertTail(Node* &Head, Node* &Tail, int data) {
    if(Tail == NULL) {
        Node* newNode = new Node(data);
        Head = newNode;
        Tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode -> prev = Tail;
    Tail -> next = newNode;
    Tail = newNode;
}

void atAnyPosition(Node* &Head, Node* &Tail, int pos, int data) {
    if(Head == NULL && Tail == NULL) {
        Node* newNode = new Node(data);
        Head = newNode;
        Tail = newNode;
    } else {
        if(pos == 1) {
            insertHead(Head, Tail, data);
            return;
        } else {
            Node* temp = Head;
            int count = 1;
            while(count < pos - 1 && temp != NULL) {
                temp = temp -> next;
                count++;
            }
            if(temp == NULL) {
                cout<<"Invalid Position";
                return;
            }
            if(temp -> next == NULL) {
                insertTail(Head, Tail, data);
                return;
            }
            Node* newNode = new Node(data);
            newNode -> prev = temp;
            newNode -> next = temp -> next;
            temp -> next -> prev = newNode;
            temp -> next = newNode;
        } 
    }
}
void deleteNode(Node* &Head, Node* &Tail, int pos) {
    if(Head == NULL && Tail == NULL) {
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    if(pos == 1) {
        Node* temp = Head;
        if(temp -> next == NULL) {
            Head = NULL;
            Tail = NULL;
        } else {
            temp -> next -> prev = NULL;
            Head = temp -> next;
        }
        delete temp;
    } else {
        int count = 1;
        Node* temp = Head;
        while(count < pos && temp != NULL) {
            temp = temp -> next;
            count++;
        }
        if(temp == NULL) {
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(temp -> next == NULL) {
            temp -> prev -> next = NULL;
            Tail = temp -> prev;
            delete temp;
            return;
        }
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        delete temp;
    } 
}

void Print(Node* &Head) {
    if(Head == NULL) {
        cout<<"Empty Linked List"<<endl;
    }
    Node* temp = Head;
    while(temp != NULL) {
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"X"<<endl;
}

int main() {
    Node* Head = NULL;
    Node* Tail = NULL;
    int ch, data, pos;
    do {
        cout<<"1.InsertHead 2.InsertTail 3.InsertAnyPosition 4.DeleteAnyPosition 5.Display 6.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch) {
            case 1:
                cout<<"Enter the value = ";
                cin>>data;
                insertHead(Head, Tail, data);
                break;
            case 2:
                cout<<"Enter the value = ";
                cin>>data;
                insertTail(Head, Tail, data);
                break;
            case 3:
                cout<<"Enter the value = ";
                cin>>data;
                cout<<"Enter the position = ";
                cin>>pos;
                atAnyPosition(Head, Tail, pos, data);
                break;
            case 4:
                cout<<"Enter the position for delete = ";
                cin>>pos;
                deleteNode(Head, Tail, pos);
                break;
            case 5:
                Print(Head);
                break;
            case 6:
                cout<<"Exit...";
                break;
            default :
                cout<<"Enter the valid choice"<<endl;
        }
    } while(ch != 6);
    return 0;
}