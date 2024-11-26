#include <iostream>
#include <iomanip>

using namespace std;

class complex {
public:
    float real, img;

    complex() {
        real = 0;
        img = 0;
    }

    complex operator+(complex);
    complex operator*(complex);

    friend ostream &operator<<(ostream &, const complex &);
    friend istream &operator>>(istream &, complex &);
};

istream &operator>>(istream &is, complex &obj) {
    cout << "Enter real part: ";
    is >> obj.real;
    cout << "Enter imaginary part: ";
    is >> obj.img;
    return is;
}

ostream &operator<<(ostream &out, const complex &obj) {
    out << obj.real;
    if (obj.img >= 0) {
        out << "+";
    }
    out << obj.img << "i";
    return out;
}

complex complex::operator+(complex obj) {
    complex temp;
    temp.real = real + obj.real;
    temp.img = img + obj.img;
    return temp;
}

complex complex::operator*(complex obj) {
    complex temp;
    temp.real = real * obj.real - img * obj.img;
    temp.img = img * obj.real + real * obj.img;
    return temp;
}

int main() {
    complex a, b, c, d;
    int ch;

    cout << "Enter the first complex number:" << endl;
    cin >> a;

    cout << "Enter the second complex number:" << endl;
    cin >> b;

    do {
        cout << "\n1. Addition\n2. Multiplication\n3. Exit\nEnter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                c = a + b;
                cout << "Addition = " << c << endl;
                break;

            case 2:
                d = a * b;
                cout << "Multiplication = " << d << endl;
                break;

            case 3:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (ch != 3);

    return 0;
}



