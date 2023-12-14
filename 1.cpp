#include<iostream>
using namespace std;
class Complex{
    private:
    int real,img;
    public:
    Complex(int real=0,int img=0){
        this->real=real;
        this->img=img;
    }
    Complex operator+(Complex obj){
        Complex ans;
        ans.real=real+obj.real;
        ans.img=img+obj.img;
        return ans;
    }
    Complex operator*(Complex obj){
        Complex ans;
        ans.real=real * obj.real - img * obj.img;
        ans.img=real * obj.img + img * obj.real;
        return ans;
    }
    friend ostream &operator<<(ostream &os, Complex &obj){
        os<<"Real : "<<obj.real<<" Img : "<<obj.img<<endl;
        return os;
    }
    friend istream &operator>>(istream &is, Complex &obj){
        is>>obj.real;
        is>>obj.img;
        return is;
    }
};

int main()
{
    Complex one;
    Complex two;
    cout << "Enter the real and img for first number";
    cin >> one;
    cout << "Enter the real and img for second number";
    cin >> two;
    Complex add = one + two;
    Complex mul = one * two;
    cout << "Sum : " << add << endl
         << "Mul : " << mul;

    return 0;
}
