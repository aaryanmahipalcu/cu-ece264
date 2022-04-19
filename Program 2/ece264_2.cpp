#include<iostream>
#include<string>
#include<new>
#include<fstream>
#include<sstream>
#include<list>

using namespace std;


template <typename T>
class SimpleList {
private:
    string name;
    class Node {
        T data;
        Node* next;
    };
protected:
    //Add a node to the front
    void push_front(Node** head_ref, T new_data){
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }
    //Add a node at the end
    void push_back(Node** head_ref, T new_data){
        Node* new_node = new Node();
        Node* last = *head_ref;
        new_node->data = new_data;
        new_node->next = NULL;
        if (*head_ref == NULL){
            *head_ref = new_node;
            return;
        }
        while (last->next != NULL){
            last = last->next;
        }
        last->next = new_node;
        return;
    }
    //Delete a node from the front
    void pop_front(Node** head_ref, T new_data){
        if (*head_ref != NULL){
            Node* temp = *head_ref;
            *head_ref = *head_Ref->next;
            free(temp);
        }
    }
public:
    
    string getName(){
        return name;
    }
    virtual void pop(T) = 0;
    virtual void push(T) = 0;
};

template <typename T>
class Stack: public SimpleList<T> {
    public:
        void push(T new_data){
            this->push_front(new_data);
        }
        T pop(){
            return this->pop_front();
        }
        Stack(string stackname):SimpleList<T>(stackname){

        }
};

template <typename T>
class Queue: public SimpleList<T> {
    public:
        void push(T new_data){
            this->push_back(new_data);
        }
        T pop(){
            return this->pop_front();
        }
        Queue(string stackname):SimpleList<T>(stackname){

        }
};

void getFiles(){
    cout << "Enter input file name: ";
    cin >> ifilename;
    cout << "Enter output file name: ";
    cin >> ofilename;
    cout << "Your Output Filename is: " << ofilename;
}

list<SimpleList<int> *> listSLi; // all integer stacks and queues
list<SimpleList<double> *> listSLd; // all double stacks and queues
list<SimpleList<string> *> listSLs; // all string stacks and queues

template <typename T>
SimpleList< T >* getlistSL(list<SimpleList< T > > &listSL, string list_name)
{
        for (typename list<SimpleList< T >>::const_iterator it = listSL.begin(); it != listSL.end(); it++)
        {
                if(((it)->getName() == list_name))
                        returnit;
        }
        return nullptr;
}


void processCommands(){

}

int main(){
    getFiles();
}
