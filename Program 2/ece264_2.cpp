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

class SimpleList {
private:
    class Node {


    };
protected:

public:

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
    string action, name, type;
    ifstream my_input_file(ifilename);
    string line;
    while(getline(my_input_file, line)){
        stringstream ss(line);
        ss >> action >> name;
        if(action == "create"){
            ss >> action >> name >> type;
        }
        else if(action == "push"){
            
        }
    }

}

void userOutput(){

}

int main(){
    getFiles();
}
