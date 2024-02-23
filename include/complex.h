#ifndef COMPLEX_H
#define COMPLEX_H
#define SIZE 4
#include <fstream>
#include<sstream>
#include<string>
#include<vector>

class Complex {
    float real, imginary;
    public:
    //Complex();//defult construtor.
    Complex(float real = 0, float imginary = 0);//parametrized constructor
    void display_result();
    void read_file_for_multiplication(const std::string&);
};
/*macros*/
#define multiply_complex(num1, num2) \
    Complex((num1.real * num2.real) - (num1.imginary * num2.imginary), \
            (num1.imginary * num2.real) + (num1.real * num2.imginary))

#endif // COMPLEX_H


