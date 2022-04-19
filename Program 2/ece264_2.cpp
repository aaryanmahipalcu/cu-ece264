#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<new>

using namespace std;

//Global Variables
string ifilename;
string ofilename;

template <typename NODETYPE>
template <typename PUSHTYPE>

class SimpleList {
private:
    string name;
    class Node {
        NODETYPE data;
        Node *next;

    };
protected:
    //Add a node to the front
    void push_front(Node** head_ref, NODETYPE new_data){
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }
    //Add a node at the end
    void push_back(Node** head_ref, NODETYPE new_data){
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
    void pop_front(Node** head_ref, NODETYPE new_data){
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
    virtual void pop() = 0;
    virtual void push() = 0;
};

class Stack: public SimpleList {
    public:

};

class Queue: public SimpleList {
    public:

};

void getFiles(){
    cout << "Enter input file name: ";
    cin >> ifilename;
    cout << "Your Input Filename is: " << ifilename << "\n";
    cout << "Enter output file name: ";
    cin >> ofilename;
    cout << "Your Output Filename is: " << ofilename;
}

void userInput(string ifilename){
    string action, name;
    ifstream my_input_file(ifilename);
    string line;
    while(getline(my_input_file, line)){
        stringstream ss(line);
        ss >> action >> name;
        if(action == "create"){
            string type;
            ss >> action >> name >> type;
        }
        else if(action == "push"){
            PUSHTYPE value;
            ss >> action >> name >> value;
        }
    }
    my_input_file.close();
}

void userOutput(string ofilename){
    ofstream my_output_file(ofilename);
}

int main(){
    getFiles();
}
