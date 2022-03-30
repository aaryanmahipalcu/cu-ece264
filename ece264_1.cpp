//Aaryan Mahipal, This program creates one base class (for Foobars), and two children classes
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

//Global Variables
string ifilename;
string ofilename; 

class Foobar{    //This is my Base Class
    public: 
    //getter function
    //get function
    private:
    //name and position
    protected: 
    //foo and bar will be able to access and use

};

class Foo: public Foobar{

};

class Bar: public Foobar{

};

void userInput(){
    //This function reads each line of the input file
    ifstream my_input_file(ifilename);  
    string line; 
    while(getline(my_input_file, line)){
        stringstream ss(line);
        string type;
        string name;
        ss >> type >> name;
        my_output_file << name << line;
    }
}

void userOutput(){
    //This function loops through the vector and writes to the output file
    ofstream my_output_file(ofilename);
}

int main(){
    cout << "Enter input file name: ";
    cin >> ifilename;
    cout << "Your Input Filename is: " << ifilename;
    cout << "Enter output file name: ";
    cin >> ofilename;
    cout << "Your Output Filename is: " << ofilename;
    userOutput();
    userInput();
}

//use vectors to store the word and its location
