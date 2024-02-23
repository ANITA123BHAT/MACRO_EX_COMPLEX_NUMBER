#include <iostream>
#include "../include/complex.h"
using namespace std;

/* Memebr Function of class Complex to read the data from file to perform multiplication  */

// void 
// Complex::read_file_for_multiplication(const string& filename){
//      /* check whether file is opened or not */
//     ifstream inputFile(filename);
//     if (!inputFile) {
//         cerr << "Failed to open the input file." << endl;
//         exit(0);
//     }
//     int input=1;
//     float complex_num[SIZE];
//     string line;
//     while (getline(inputFile, line)) {
//         int count=0;
//         istringstream iss(line);
//         while(iss >>complex_num[count]){
//             count++;
//         }
//         if(count!=SIZE){
//             cout<<"INVALID DATA "<<input <<") "<<line<<endl;
//             cout<<"\n";
//         }
        
//         else{
//             Complex num1(complex_num[0],complex_num[1]);
//             Complex num2(complex_num[2],complex_num[3]);
//             Complex result=multiply_complex(num1, num2);
//             cout << "(" << complex_num[0] << "+i*" << complex_num[1] << ")" << "(" << complex_num[2] << "+i*" << complex_num[3] << ")" << endl;
//             result.display_result();
//         }
//         input++;
//     }
//     inputFile.close();//close file
// }

bool 
isValidComplexFormat(const std::string& input) {
    // Validate the format of the complex number input
    // Assuming the format: (real imaginary)
    std::istringstream iss(input);
    char openBracket, closeBracket;
    float real, imaginary;
    if (iss >> openBracket >> real >> imaginary >> closeBracket) {
        return ((openBracket == '(') && (closeBracket == ')'));
    }
    return false;
}

void 
Complex::read_file_for_multiplication(const std::string& filename) {
    char openBracket, closeBracket;
    float real, imaginary;
    std::ifstream inputFile(filename);
    if (!inputFile) {
        exit(0);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') {
            // Skip empty lines and lines starting with '#'
            continue;
        }

        if (!isValidComplexFormat(line)) {
            continue;
        }
        else{
            std::istringstream iss(line);
            iss >> openBracket >> real >> imaginary >> closeBracket;
            // cout<<real<<" "<<imaginary<<endl;
            Complex num1(real,imaginary);
            // store_input.push_back(real);
            // store_input.push_back(imaginary);
            std::string secondLine;
            std::getline(inputFile, secondLine);
            if (secondLine.empty() || secondLine[0] == '#') {
                // Skip empty lines and lines starting with '#'
                continue;
            }
            if (!isValidComplexFormat(secondLine)) {
                continue;
            }
            else{
                std::istringstream iss(secondLine);
                iss >> openBracket >> real >> imaginary >> closeBracket;
                // cout<<real<<" "<<imaginary<<endl;
                Complex num2(real,imaginary);
                cout<<num1.real<<" "<<num1.imginary<<endl;
                cout<<num2.real<<" "<<num2.imginary<<endl;
                Complex result=multiply_complex(num1, num2);
                // store_input.push_back(real);
                // store_input.push_back(imaginary);
                result.display_result();
            }
        }
    }
    inputFile.close();
}




