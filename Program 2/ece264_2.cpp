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

void getFiles(){
    cout << "Enter input file name: ";
    cin >> ifilename;
    cout << "Your Input Filename is: " << ifilename;
    cout << "Enter output file name: ";
    cin >> ofilename;
    cout << "Your Output Filename is: " << ofilename;
}

int main(){
    getFiles();
}