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
    public:
        T data;
        Node* next;
    };
    int size = 0;
protected:
    //Add a node to the front
    void push_front(T new_data){
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = head_ref->next;
        head_ref->next = new_node;

        size ++;
    }
    //Add a node at the end, change for head_ref
    void push_back(T new_data){
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = nullptr;
        last->next = new_node;
        last = new_node;
        size ++;
    }
    //Delete a node from the front
    T void pop_front(){
        T new_data = head_ref->next->data;
        Node *temp = head_ref->next->next;
        delete(head_ref->next);
        head_ref->next = temp;
        size --;
        return new_data;
        }
public:
    Node *head_ref;
    Node *last;

    SimpleList(string my_name){
        head_ref = Node();
        name = my_name;
        head_ref->next = nullptr;
        last = head_ref;
    }
    int getLength(){
        return size;
    }
    string getName(){
        return name;
    }
    virtual T pop() = 0;
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

void getFiles(string ifilename, string ofilename){
    cout << "Enter input file name: ";
    cin >> ifilename;
    cout << "Enter output file name: ";
    cin >> ofilename;
    cout << "Your Output Filename is: " << ofilename;
}


template <typename T>
SimpleList<T>* search(list<SimpleList<T>*> &listSL, string list_name){
        for (auto it = listSL.begin(); it != listSL.end(); it++){
                if((*it)->getName() == list_name){
                        return *it;
                 }
        }
    return nullptr;
}


void processCommands(string &ifilename, string &ofilename){
    //List Declerations
    list<SimpleList<int> *> listSLi; // all integer stacks and queues
    list<SimpleList<double> *> listSLd; // all double stacks and queues
    list<SimpleList<string> *> listSLs; // all string stacks and queues

    ifstream my_input_file(ifilename);
    ofstream my_output_file(ofilename);

    string line; //sentence to read
    string command; //command
    string list_name; //name of list
    char list_type; //double, int, string
    string list_struc; //stack or queue
    string third_word; //third word

    while(getline(my_input_file, line)){
        stringstream ss(line);
        ss >> command >> list_name >> third_word;
        //Declaring what type of list it is
        list_type = list_name[0];
        my_output_file << "PROCESSING COMMAND: " << line << "\n";

        if(command == "create"){
            list_struc = third_word;
            if(list_type = 'i'){
                if(search(listSLi, list_name) == nullptr){
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
                    my_output_file << "ERROR: This name already exists!\n";
                }
            }
            else if(list_type = 'd'){
                if(search(listSLd, list_name) == nullptr){
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
                    my_output_file << "ERROR: This name already exists!\n";
                }
            }
            else{
                if(search(listSLs, list_name) == nullptr){
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
                    my_output_file << "ERROR: This name already exists!\n";
                }
            }
        }
        else if(command == "push"){
            if(list_type == 'i'){
                SimpleList<int>* intAddress = search(listSLi, list_name);
                if(intAddress == nullptr){
                    my_output_file << "ERROR: This name does not exist\n";
                }
                else{
                    int new_data = std::stoi(third_word);
                    intAddress->push(new_data);
                }
            }
            else if(list_type == 'd'){
                SimpleList<double>* doubleAddress = search(listSLd, list_name);
                if(doubleAddress == nullptr){
                    my_output_file << "ERROR: This name does not exist\n";
                }
                else{
                    double new_data = std::stod(third_word);
                    doubleAddress->push(new_data);
                }
            }
            else{
                SimpleList<string>* strAddress = search(listSLs, list_name);
                if(strAddress == nullptr){
                    my_output_file << "ERROR: This name does not exist\n";
                }
                else{
                    string new_data = third_word;
                    strAddress->push(new_data);  
                }   
            }
        }
        else{
            if(list_type == 'i'){
                SimpleList<int>* intAddress = search(listSLi, list_name);
                if(intAddress == nullptr){
                    my_output_file << "ERROR: This name does not exist!\n";
                }
                else if(intAddress->getLength() < 1){
                    my_output_file << "ERROR: This list is empty!\n";
                }
                else{
                    my_output_file << "Value popped: " << intAddress->pop() << "\n";
                }
            }
            else if(list_type == 'd'){
                SimpleList<double>* doubleAddress = search(listSLd, list_name);
                if(doubleAddress == nullptr){
                    my_output_file << "ERROR: This name does not exist!\n";
                }
                else if(doubleAddress->getLength() < 1){
                    my_output_file << "ERROR: This list is empty!\n";
                }
                else{
                    my_output_file << "Value popped: " << doubleAddress->pop() << "\n";
                }
            }
            else{
                SimpleList<string>* strAddress = search(listSLs, list_name);
                if(strAddress == nullptr){
                    my_output_file << "ERROR: This name does not exist!\n";
                }
                else if(strAddress->getLength() < 1){
                    my_output_file << "ERROR: This list is empty!\n"
                }
                else{
                    my_output_file << "Value popped: " << strAddress->pop() << "\n";
                }
            }
        }
    }
    my_input_file.close();
    my_output_file.close();
}

int main(){
    string ifilename, ofilename;
    getFiles(ifilename, ofilename);
    processCommands(ifilename, ofilename);
    return 0;
}
