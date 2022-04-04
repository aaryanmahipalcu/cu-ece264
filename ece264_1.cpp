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
    //constructor
    Foobar(string n, int p){
        name = n;
        position = p;
        }

    void setPosition(p){
        position = p;
    }
    
    //Getters
    virtual int getStrength(){
        return position;
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
    int position;
    protected: 
    //getter to get position
    int getPosition(){
        return position;
    }
};

class Foo: public Foobar{
    public:
    virtual int getStrength(){
        return position*3;
    }
    
};

class Bar: public Foobar{
    public:
    virtual int position+15;
};

void getFiles(){
    cout << "Enter input file name: ";
    cin >> ifilename;
    cout << "Your Input Filename is: " << ifilename;
    cout << "Enter output file name: ";
    cin >> ofilename;
    cout << "Your Output Filename is: " << ofilename;
}

void userInput(string ifilename, string type, string name){
    //This function reads each line of the input file
    ifstream my_input_file(ifilename);  
    string line; 
    my_input_file.open(ifilename);
    while(getline(my_input_file, line)){
        stringstream ss(line);
        ss >> type >> name;
        if(type == "foobar"){
            Foobar*p = new Foobar(name, 0);
            mainvector.push_back(p);
        }
        else if(type == "foo"){
            Foobar*p = new Foo(name, 0);
            mainvector.push_back(p);
        }
        else(type == "bar"){
            Foobar*p = new Bar(name, 0);
            mainvector.push_back(p);
        }
    }
    my_input_file.close();
}

void update_strength(){

}

void userOutput(string ofilename){
    //This function loops through the vector and writes to the output file
    ofstream my_output_file(ofilename);
}

int main(){
    getFiles();
    vector<Foobar *> mainvector;
    userInput(ifilename," "," ");
    update_strength();
    userOutput(ofilename);
}

//use vectors to store the word and its location
