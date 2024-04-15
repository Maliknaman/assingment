#include <iostream>
#include <vector>
class MenuItem {
protected:
    std::string name;
    double price;
public:
    MenuItem(const std::string& name, double price) : name(name), price(price) {}
    virtual ~MenuItem() {}
    virtual double calculateCost() const {
        return price;
    }
    virtual void display() const {
        std::cout << "Name: " << name << ", Price: $" << price << std::endl;
    }
};
class FoodItem : public MenuItem {
private:
    std::string category;
public:
    FoodItem(const std::string& name, double price, const std::string& category)
      : MenuItem(name, price), category(category) {}
    void display() const override {
        std::cout << "Food Item - ";
        MenuItem::display();
        std::cout << "Category: " << category << std::endl;
    }
};
class Beverage : public MenuItem {
private:
    std::string size;
public:
    Beverage(const std::string& name, double price, const std::string& size)
        : MenuItem(name, price), size(size) {}
    void display() const override {
        std::cout << "Beverage - ";
        MenuItem::display();
        std::cout << "Size: " << size << std::endl;
    }
};
class Dessert : public MenuItem {
public:
    Dessert(const std::string& name, double price) : MenuItem(name, price) {}
};
class Bill {
private:
    std::vector<const MenuItem*> items;
public:
    ~Bill() {
        for (const auto& item : items) {
            delete item;
        }
    }
    void addItem(const MenuItem* item) {
        items.push_back(item);
    }
    double calculateTotalCost() const {
        double total = 0;
        for (const auto& item : items) {
            total += item->calculateCost();
        }
        return total;
    }
    void displayBill() const {
        std::cout << "------ Bill ------" << std::endl;
        for (const auto& item : items) {
            item->display();
        }
        std::cout << "Total: $" << calculateTotalCost() << std::endl;
    }
};
int main() {
    Bill bill;
    bill.addItem(new FoodItem("Burger", 10.99, "Main Course"));
    bill.addItem(new Beverage("Cola", 2.99, "Large"));
    bill.addItem(new Dessert("Cheesecake", 5.99));
    bill.displayBill();
    return 0;
}
