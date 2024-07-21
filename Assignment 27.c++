7. Define a C++ class fraction
class fraction
{
long numerator;
long denominator;
Public:
fraction (long n=0, long d=0);
}
Overload the following operators as member or friend:
a) Unary ++ (pre and post both)
b) Overload as friend functions: operators << and >>.
Output-

8. Consider a class Matrix
Class Matrix
{
int a[3][3];
Public:
//methods;
};
Overload the - (Unary) should negate the numbers stored in the object.
Output -

9. Consider the following class mystring
Class mystring
{
char str [100];
Public:
// methods
};
Overload operator “!” to reverse the case of each alphabet in the string
(Uppercase to Lowercase and vice versa).
10.Class Matrix
{
int a[3][3];
Public:
//methods;
};
Let m1 and m2 are two matrices. Find out m3=m1+m2 (use operator
overloading).
Output -

Solution:-

1. #include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator + (const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator - (const Complex &c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator * (const Complex &c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    bool operator == (const Complex &c) const {
        return (real == c.real && imag == c.imag);
    }

    friend ostream& operator << (ostream &out, const Complex &c);
    friend istream& operator >> (istream &in, Complex &c);
};

ostream& operator << (ostream &out, const Complex &c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

istream& operator >> (istream &in, Complex &c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}

int main() {
    Complex c1, c2, c3;
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    c3 = c1 + c2;
    cout << "Sum: " << c3 << endl;

    c3 = c1 - c2;
    cout << "Difference: " << c3 << endl;

    c3 = c1 * c2;
    cout << "Product: " << c3 << endl;

    if (c1 == c2) {
        cout << "The complex numbers are equal." << endl;
    } else {
        cout << "The complex numbers are not equal." << endl;
    }

    return 0;
}

2. #include <iostream>
using namespace std;

class Number {
private:
    int value;
public:
    Number(int v = 0) : value(v) {}

    Number& operator ++ () { // Prefix increment
        ++value;
        return *this;
    }

    Number operator ++ (int) { // Postfix increment
        Number temp = *this;
        value++;
        return temp;
    }

    Number& operator -- () { // Prefix decrement
        --value;
        return *this;
    }

    Number operator -- (int) { // Postfix decrement
        Number temp = *this;
        value--;
        return temp;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number n(10);

    cout << "Initial value: ";
    n.display();

    ++n;
    cout << "After prefix increment: ";
    n.display();

    n++;
    cout << "After postfix increment: ";
    n.display();

    --n;
    cout << "After prefix decrement: ";
    n.display();

    n--;
    cout << "After postfix decrement: ";
    n.display();

    return 0;
}

3. #include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    friend Complex operator + (const Complex &c1, const Complex &c2);
    friend ostream& operator << (ostream &out, const Complex &c);
    friend istream& operator >> (istream &in, Complex &c);
};

Complex operator + (const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

ostream& operator << (ostream &out, const Complex &c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

istream& operator >> (istream &in, Complex &c) {
    cout << "Enter real part: ";
    in >> c.real;
    cout << "Enter imaginary part: ";
    in >> c.imag;
    return in;
}#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;
public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    bool operator == (const Time &t) const {
        return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
    }

    friend ostream& operator << (ostream &out, const Time &t);
    friend istream& operator >> (istream &in, Time &t);
};

ostream& operator << (ostream &out, const Time &t) {
    out << t.hours << " hr " << t.minutes << " min " << t.seconds << " sec";
    return out;
}

istream& operator >> (istream &in, Time &t) {
    cout << "Enter hours: ";
    in >> t.hours;
    cout << "Enter minutes: ";
    in >> t.minutes;
    cout << "Enter seconds: ";
    in >> t.seconds;
    return in;
}

int main() {
    Time t1, t2;
    cout << "Enter first time:\n";
    cin >> t1;
    cout << "Enter second time:\n";
    cin >> t2;

    cout << "First Time: " << t1 << endl;
    cout << "Second Time: " << t2 << endl;

    if (t1 == t2) {
        cout << "The times are equal." << endl;
    } else {
        cout << "The times are not equal." << endl;
    }

    return 0;
}

5. #include <iostream>
using namespace std;

class Numbers {
private:
    int x, y, z;
public:
    Numbers(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}

    void display() const {
        cout << "Numbers: " << x << ", " << y << ", " << z << endl;
    }

    Numbers operator - () const {
        return Numbers(-x, -y, -z);
    }
};

int main() {
    Numbers n1(1, -2, 3);
    Numbers n2 = -n1;

    cout << "Original ";
    n1.display();
    cout << "Negated ";
    n2.display();

    return 0;
}

6. #include <iostream>
#include <cstring>
using namespace std;

class CString {
private:
    char str[100];
public:
    CString(const char *s = "") {
        strcpy(str, s);
    }

    CString operator + (const CString &s) const {
        CString temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    bool operator == (const CString &s) const {
        return strcmp(str, s.str) == 0;
    }

    friend ostream& operator << (ostream &out, const CString &s);
    friend istream& operator >> (istream &in, CString &s);
};

ostream& operator << (ostream &out, const CString &s) {
    out << s.str;
    return out;
}

istream& operator >> (istream &in, CString &s) {
    in >> s.str;
    return in;
}

int main() {
    CString s1("Hello"), s2("World"), s3;

    s3 = s1 + s2;
    cout << "Concatenated string: " << s3 << endl;

    if (s1 == s2) {
        cout << "Strings are equal." << endl;
    } else {
        cout << "Strings are not equal." << endl;
    }

    return 0;
}

7. #include <iostream>
using namespace std;

class Fraction {
private:
    long numerator, denominator;
public:
    Fraction(long n = 0, long d = 1) : numerator(n), denominator(d) {}

    // Prefix increment
    Fraction& operator ++ () {
        numerator += denominator;
        return *this;
    }

    // Postfix increment
    Fraction operator ++ (int) {
        Fraction temp = *this;
        numerator += denominator;
        return temp;
    }

    // Overload << operator for output
    friend ostream& operator << (ostream &out, const Fraction &f) {
        out << f.numerator << '/' << f.denominator;
        return out;
    }

    // Overload >> operator for input
    friend istream& operator >> (istream &in, Fraction &f) {
        cout << "Enter numerator: ";
        in >> f.numerator;
        cout << "Enter denominator: ";
        in >> f.denominator;
        return in;
    }
};

int main() {
    Fraction f1(3, 4), f2;
    
    cout << "Enter a fraction:\n";
    cin >> f2;

    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;

    ++f1;
    cout << "After prefix increment: " << f1 << endl;

    f2++;
    cout << "After postfix increment: " << f2 << endl;

    return 0;
}

8. #include <iostream>
using namespace std;

class Matrix {
private:
    int a[3][3];
public:
    Matrix() {
        // Initialize matrix with zeros
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                a[i][j] = 0;
    }

    void input() {
        cout << "Enter elements of 3x3 matrix:\n";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> a[i][j];
    }

    void display() const {
        cout << "Matrix:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    // Overload unary - operator
    Matrix operator - () const {
        Matrix temp;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp.a[i][j] = -a[i][j];
        return temp;
    }
};

int main() {
    Matrix m1, m2;

    cout << "Input matrix m1:\n";
    m1.input();
    cout << "Matrix m1:\n";
    m1.display();

    m2 = -m1; // Apply unary negation
    cout << "Matrix m2 (negated m1):\n";
    m2.display();

    return 0;
}

9. #include <iostream>
#include <cctype> // For islower(), isupper()
using namespace std;

class mystring {
private:
    char str[100];
public:
    mystring(const char *s = "") {
        strcpy(str, s);
    }

    // Overload unary ! operator
    mystring operator ! () const {
        mystring temp;
        for (int i = 0; str[i]; ++i) {
            if (islower(str[i]))
                temp.str[i] = toupper(str[i]);
            else if (isupper(str[i]))
                temp.str[i] = tolower(str[i]);
            else
                temp.str[i] = str[i];
        }
        return temp;
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    mystring s("Hello World");
    mystring reversedCase;

    cout << "Original string: ";
    s.display();

    reversedCase = !s;
    cout << "String with reversed case: ";
    reversedCase.display();

    return 0;
}

10. #include <iostream>
using namespace std;

class Matrix {
private:
    int a[3][3];
public:
    Matrix() {
        // Initialize matrix with zeros
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                a[i][j] = 0;
    }

    void input() {
        cout << "Enter elements of 3x3 matrix:\n";
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> a[i][j];
    }

    void display() const {
        cout << "Matrix:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    // Overload binary + operator
    Matrix operator + (const Matrix &m) const {
        Matrix temp;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp.a[i][j] = a[i][j] + m.a[i][j];
        return temp;
    }
};

int main() {
    Matrix m1, m2, m3;

    cout << "Input matrix m1:\n";
    m1.input();
    cout << "Input matrix m2:\n";
    m2.input();

    m3 = m1 + m2; // Add two matrices
    cout << "Matrix m3 (result of m1 + m2):\n";
    m3.display();

    return 0;
}


int main() {
    Complex c1, c2, c3;
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    c3 = c1 + c2;
    cout << "Sum: " << c3 << endl;

    return 0;
}

4. 