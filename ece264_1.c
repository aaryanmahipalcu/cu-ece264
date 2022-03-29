//Aaryan Mahipal, This program creates one base class (for Foobars), and two children classes
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

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
}

void userOutput(){
    //This function loops through the vector and writes to the output file
}

//Declaring Functions
std::string get_input_filename()
std::string get_output_filename()
std::string get_file_contents(std::string const& infile)
int main(){

}

//Implementing Functions
std::string get_input_filename(){
    std::string filename;
    cout << "Enter Input filename\n";
    cout << "Filename: ";
    cin >> filename;
    return filename;
}

std::string get_output_filename(){
    std::string filename;
    cout << "Enter Output filename\n";
    cout << "Filename: ";
    cin >> filename;
    return filename;
}

std::string get_file_contents(std::string const& infile){
    std::ifstream inf(infile);
    std::string contents;
    int c;
    while ((c = inf.get()) != EOF){
        contents += c;
    }
    return contents;
}

//use vectors to store the word and its location