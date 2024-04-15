#include <iostream>
class largerUnit;
class smallUnit {
private:
    int inches;
public:
    smallUnit(int inches) : inches(inches) {}
    operator largerUnit();
    int getInches() const { return inches; }
};
class largerUnit {
private:
    int feet;
public:
    largerUnit() : feet(0) {}
    largerUnit(int feet) : feet(feet) {}

    int getFeet() const { return feet; }
    void display(int inches) const { std::cout << "Inches: " << inches << std::endl; }

    friend class smallUnit;
};
smallUnit::operator largerUnit() {
    return largerUnit(inches / 12);
}
int main() {
    smallUnit small(36);
    largerUnit large = small;
    large.display(small.getInches());
    return 0;
}
