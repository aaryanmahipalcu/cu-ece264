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
    protected:

    private:

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

void userInput(){

}

void userOutput(){

}

int main(){
    getFiles();
}
