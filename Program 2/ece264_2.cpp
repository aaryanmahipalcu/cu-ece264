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


template <typename T>
SimpleList< T >* search(list<SimpleList<T>*> &listSL, string list_name){
        for (auto it = listSL.begin(); it != listSL.end(); it++){
                if((*it)->getName() == list_name){
                        return *it;
                 }
        }
    return nullptr;
}


void processCommands(const string& readFile, const string& writeFile){
    //List Declerations
    list<SimpleList<int> *> listSLi; // all integer stacks and queues
    list<SimpleList<double> *> listSLd; // all double stacks and queues
    list<SimpleList<string> *> listSLs; // all string stacks and queues

    ifstream ifilename(readFile);
    ofstream ofilename(writeFile);

    string line; //sentence to read
    string command; //command
    string list_name; //name of list
    char list_type; //double, int, string
    string list_struc; //stack or queue
    string third_word; //third word

    while(getline(ifilename, line)){
        stringstream ss(line);
        ss >> command >> list_name >> third_word;
        //Declaring what type of list it is
        list_type = list_name[0];
        cout << "PROCESSING COMMAND: " << line << "\n";

        if(command == "create"){
            list_struc = third_word;
            if(list_type = 'i'){
                if(search(list_name, listSLi) == nullptr){
                    SimpleList<int> *pSLi;
                    if(list_struc == "queue"){
                        pSLi = new Queue<int>(list_name);
                    }
                    else{
                        pSLi = new Stack<int>(list_name);
                    }
                    listSLi.push_front(pSLi);
                }
                else{
                    cout << "ERROR: This name already exists!\n";
                }
            }
            else if(list_type = 'd'){
                if(search(list_name, listSLd) == nullptr){
                    SimpleList<double> *pSLd;
                    if(list_struc == "queue"){
                        pSLd = new Queue<double>(list_name);
                    }
                    else{
                        pSLd = new Stack<double>(list_name);
                    }
                    listSLd.push_front(pSLd);
                }
                else{
                    cout << "ERROR: This name already exists!\n";
                }
            }
            else{
                if(search(list_name, listSLs) == nullptr){
                    SimpleList<string> *pSLs;
                    if(list_struc == "queue"){
                        pSLs = new Queue<string>(list_name);
                    }
                    else{
                        pSLs = new Stack<string>(list_name);
                    }
                    listSLs.push_front(pSLs);
                }
                else{
                    cout << "ERROR: This name already exists!\n";
            }
        }
        else if(command == "push"){
            if(list_type == 'i'){
                SimpleList<int>* intAddress = search(list_name, listSLi);
                if(intAddress == nullptr){
                    cout << "ERROR: This name does not exist\n";
                }
                else{
                    int new_data = std::stoi(third_word);
                    intAddress->push(new_data);
                }
            }
            else if(list_type == 'd'){
                SimpleList<double>* doubleAddress = search(list_name, listSLd);
                if(doubleAddress == nullptr){
                    cout << "ERROR: This name does not exist\n";
                }
                else{
                    double new_data = std::stob(third_word);
                    doubleAddress->push(new_data);
                }
            }
            else{
                SimpleList<string>* strAddress = search(list_name, listSLs);
                if(strAddress == nullptr){
                    cout << "ERROR: This name does not exist\n";
                }
                else{
                    string new_data = third_word;
                    strAddress->push(new_data);  
                }   
            }
        }
        else{
            
        }

    }

}

int main(){
    getFiles();
}
