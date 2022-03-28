#pragma once
#include <iostream>
#include <vector>

//#include "leaker.h"
using namespace std;

template <typename T>
class LinkedList {

    public:
    
        struct Node {

            public:
                Node* prev;
                Node* next;
                T data;
            
                Node() {
                    prev = nullptr;
                    next = nullptr;
                }

                Node(T value) {
                    prev = nullptr;
                    next = nullptr;
                    data = value;
                }

                Node(T value, Node* after) {
                    data = value;
                    next = after;
                }

                Node(T value, Node* after, Node* previous) {
                    data = value;
                    prev = previous;
                    next = after;
                }

                /*
                Node* getNext() {
                    return next;
                }

                Node* getPrevious() {
                    return previous;
                }

                T getData() {
                    return data;
                }
                */

                void setNext(Node* node) {
                    this->next = node;
                }

                void setPrevious(Node* node) {
                    prev = node;
                }

                void setData(T value) {
                    data = value;
                } 
        };

    public:
        Node* head; // Head is the FIRST item in the linked list
        unsigned int count;

    // Constructors

    LinkedList() {
        count = 0;
        head = nullptr;
    }

    // Copy Constructor

    LinkedList(const LinkedList<T> &d) {
        cout << "Copy Constructor Called" << endl;
        this->Clear();
        cout << "List Cleared" << endl;
        LinkedList<T> list;
        AddHead(d.head->data);
        cout << "Copy Constructor Called" << endl;
        for(unsigned int i = 1; i < d.count; i += 1) {
            //cout << "Loop Started" << endl;
            AddTail(d.GetNode(i)->data);
        }
        //list.PrintForward();
    }

    // Destructor

    ~LinkedList() {
        Node* current = head;
        if (head == nullptr) {
            delete head;
        }
        else {
           for (int i = count; i > 0; i -= 1) {
               Node* nextHolding = current->next;
                delete current;
                current = nextHolding;
                count -= 1;
           }
        }
    }

    // Overloaded Operators

    // Array Notation Operators
    const T& operator[](unsigned int index) const{
        /*
        if(index == 0) {
            return head;
        }
        */
        //else {
            Node* current = head;
            for(unsigned int i = 0; i < index; i += 1) {
                current = current->next;
            }
            return current->data;

        //}
    }

    T& operator[](unsigned int index) {
        this->GetNode(index)->data;  
    }

    // Copy Assignment Operator
    LinkedList<T>& operator=(const LinkedList<T>& rhs) {
        /* Attempt 1
        LinkedList<T> sample;
        LinkedList<T>& hold = sample;
        for(unsigned int i = 0; i < rhs.NodeCount(); i += 1) {
            sample.AddHead(rhs[i]);
        }
        return hold;
        */

       /* Attempt 2
       this->Clear();
       //this->PrintForward();
       cout << "List Cleared" << endl;
       for(unsigned int i = 0; i < rhs.NodeCount(); i += 1) {
           cout << "Loop Started" << endl;
           cout << rhs.GetNode(i)->data << endl;
           this->AddTail(rhs.GetNode(i)->data);
       }
       cout << "Loop Ended" << endl;
       */

       // Attempt 3
        cout << "Copy Assignment Operator Called" << endl;
        LinkedList<T> sample;
        LinkedList<T> &hold = sample;
        cout << "Vars created" << endl;

        for(unsigned int i = 0; i < rhs.NodeCount(); i += 1) {
            sample.AddTail(rhs.GetNode(i)->data);
        }
        return hold;
    }

    // Boolean Comparison Operator
    // MUST FINISH
    bool operator==(const LinkedList<T>& rhs) const{
        if(this->NodeCount() != rhs.NodeCount())
            return false;
        Node* comp1 = head;
        Node* comp2 = rhs.head;
        for(unsigned int i = 0; i < rhs.NodeCount(); i += 1) {
            if(comp1->data != comp2->data)
                return false;
            comp1 = comp1->next;
            comp2 = comp2->next;
        }
        return true;
    }

    // Accessors

    Node* Head() {
        return head;
    }

    const Node* Head() const {
        return head;
    }

    Node* Tail() {
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        return current;
    }

    const Node* Tail() const {
        Node* current = head;
        while(current->next != nullptr) {
            current = current->next;
        }
        return current;
    }

    unsigned int NodeCount() const{return count;}
    


    void FindAll(vector<Node*>& vec, const T& value) const{
        Node* current = head;
        for(int i = 0; i < count; i += 1) {
            if(current->data == value)
                vec.push_back(current);
            current = current->next;
        }
    }


    const Node* Find(const T& comparison) const{
        Node* pointer = nullptr;
        Node* current = head;
        while(current->next != nullptr) {
            if(current->data == comparison){
                pointer = current;
                break;
            }
            else {
                current = current->next;
            }
        }
        return pointer;
    }

    Node* Find(const T& comparison) {
        Node* pointer = nullptr;
        Node* current = head;
        while(current->next != nullptr) {
            if(current->data == comparison){
                pointer = current;
                break;
            }
            else {
                current = current->next;
            }
        }
        return pointer;
    }    

    const Node* GetNode(unsigned int index) const{
        Node* current = head;
        try {
            if(index >= this->count)
                throw out_of_range("Index is out of range");
            for(unsigned int i = 0; i < index; i += 1) {
                current = current->next;
            }
        }
        catch(const std::out_of_range &e) {
            cout << "Index is out of range" << endl;
        }

        return current;
    }

    Node* GetNode(unsigned int index) {
        Node* current = head;
        try {
            if(index >= this->count)
                throw out_of_range("Index is out of range");
            for(unsigned int i = 0; i < index; i += 1) {
                current = current->next;
            }
        }
        catch(const std::out_of_range &e) {
            cout << "Index is out of range" << endl;
        }

        return current;
    }

    // Insertion Operations
    
    void AddHead(T param)  {
        Node* tmp = new Node(param);
        if (head == nullptr) {
            head = tmp;
            count += 1;
        }
        else {
            tmp->setNext(head);
            head->setPrevious(tmp);
            head = tmp;
            count += 1;
        }
    }
    
    void AddTail(T param) {
        Node* tmp = new Node(param);
        if (head == nullptr) {
            head = tmp;
            count += 1;
        }
        else {
            Node* current = head;
            while(current -> next != nullptr) {
                current = (current -> next);
            }
            current->setNext(tmp);
            tmp->setPrevious(current);
            count += 1;
        }
        
    }

    void AddNodesHead(T vals[], int len) {
        for (int i = 1; i <= len ; i += 1) {
           this->AddHead(vals[len-i]);
        }
    }

    void AddNodesTail(T vals[], int len) {
       for (int i = 0; i < len ; i += 1) {
           this->AddTail(vals[i]);
       }
    }

    void InsertBefore(Node* node) {
        
    }

    void InsertAfter(Node* node) {

    }

    void InsertAt(const T* data, unsigned int index) {
        
    }

    // Removal Operations

    bool RemovedHead() {
        cout << to_string(count) << endl;
        Node* temp = head;
        if (count == 0) {
            return false;
        }
        else if (count == 1){
            head->next = nullptr;
            // head->prev = nullptr;
            head = nullptr;
            count -= 1;
            return true;
        }
        else {
            head = head->next;
            head->prev = nullptr;
            delete temp;
            count -= 1;
            return true;
        }
    }

    bool RemoveTail() {
        return true;
    }

    unsigned int Remove(T param) {
        unsigned int counter = 0;
        return counter;
    }

    bool RemoveAt() {
        return true;
    }

    void Clear() {
        /*
       cout << "Clear Called" << endl;
        if(head == nullptr) {
            return;
        }
        this->PrintForward(); // Problem in this line
        Node* temp = head;
        cout << "Temp Node Created" << endl;
        while(head != nullptr) {
            cout << "Loop Iteration" << endl;
            temp = head->next;
            delete head;
            head = temp;
        }
        */
       cout << "Clear Called" << endl;
       for(unsigned int i = 0; i < count; i += 0) {
           cout << "iteration" << endl;
           RemovedHead();
       }
        
    }
        
    // Behaviours

    void PrintForward() const{ // Problem with this function
        Node* current = head;
        /*
        for(unsigned int i = 0; i < this->count; i += 1) {
            cout << to_string((current->data)) << endl;
            current = current->next;
        }
        */
       if(count == 0){
           return;
       }
       for(unsigned int i = 0; i < count; i += 1) {
           //cout << "Loop Iteration" << endl;
           cout << current->data << endl;
           current = current->next;
       }

    }

    void PrintReverse() const{
        Node* current = head;
        for(unsigned int i = 0; i < count-1; i += 1) {
            current = current->next;
        }
        for(unsigned int i = count; i > 0; i -= 1) {
            cout << current->data << endl; // Problem in this line
            current = current->prev;
        }
    }

    void PrintForwardRecursive() const{

    }

    void PrintReverseRecursive() const{
        return;
    }
};