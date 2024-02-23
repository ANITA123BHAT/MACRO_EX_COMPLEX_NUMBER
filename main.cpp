#include <iostream>
#include "./include/complex.h"
using namespace std;

int 
main(int argc, char* argv[]) {
    Complex obj1;
    /*taking the input file through command line argument*/
    if(argc<2){
        cout<<"Usage:<./program_name> <file_name.txt>"<<endl;
        return 1;
    }
    string fileName(argv[1]);
    obj1.read_file_for_multiplication(fileName);//multiplication of two complex number 
    return 0;
}

