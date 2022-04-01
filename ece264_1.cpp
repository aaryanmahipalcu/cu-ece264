//Aaryan Mahipal, This program creates one base class (for Foobars), and two children classes
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<new>

using namespace std;

//Global Variables
string ifilename;
string ofilename; 

class Foobar{    //This is my Base Class
    public: 
    Foobar(string FoobarInformation);
    '''//constructor
    Foobar::Foobar(string FoobarInformation){
        stringstream FoobarStream(FoobarInformation);
        FoobarStream >> type >> name;}'''
    Foobar(string nm, int pos ){
        setName(z);
        //set name and position=0 in the constructor
    }

    //member functions
    void setName(x){
        name = x;
    }

    void setPosition(y){
        position = y;
    }
    
    //Getters
    string Foobar::getType(){
        return type;
    }
    string Foobar::getName(){
        return name;
    }
    //get the strength
    //get the name
    //memeber function to set position in line
    string type;
    private:
    //name and position
    string name;
    string position;
    protected: 
    //foo and bar will be able to access and use
    string getposition();

};

class Foo: public Foobar{

};

class Bar: public Foobar{

};

void userInput(string ifilename, my_output_file){
    //This function reads each line of the input file
    ifstream my_input_file(ifilename);  
    string line; 
    while(getline(my_input_file, line)){
        stringstream ss(line);
        string type;
        string name;
        ss >> type >> name;
        //up till here, this function is reading the file line by line, now we need to find a way to add each info to a vector of pointers to foobar objects
        cout << type << name
    }
}

void userOutput(string ofilename){
    //This function loops through the vector and writes to the output file
    ofstream my_output_file(ofilename);
}

int main(){
    cout << "Enter input file name: ";
    cin >> ifilename;
    cout << "Your Input Filename is: " << ifilename;
    '''cout << "Enter output file name: ";
    cin >> ofilename;
    cout << "Your Output Filename is: " << ofilename;
    userOutput();'''
    userInput();
}

//use vectors to store the word and its location
