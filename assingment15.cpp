#include <iostream>
class ClassB;
class ClassA {
private:
    int numA;
public:
    ClassA(int num) : numA(num) {}
    friend int sum(const ClassA& a, const ClassB& b);
};
class ClassB {
private:
    int numB;
public:
    ClassB(int num) : numB(num) {}
    friend int sum(const ClassA& a, const ClassB& b);
};
int sum(const ClassA& a, const ClassB& b) {
    return a.numA + b.numB;
}
int main() {
    ClassA objA(5);
    ClassB objB(10);
    std::cout << "Sum of private members: " << sum(objA, objB) << std::endl;
    return 0;
}
