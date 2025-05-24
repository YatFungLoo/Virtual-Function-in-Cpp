#include <iostream>
#include <string>

class Fruit {
  public:
    Fruit(std::string s) : myName(s) {}
    virtual void whatAmI() { std::cout << myName << std::endl; } // Fruit2 WILL NOT use this and use its own whatAmI
    // void whatAmI() { std::cout << myName << std::endl; } // Fruit2 WILL use this instead of its own whatAmI()

  private:
    std::string myName;
};

class Fruit2 : public Fruit {
    using Fruit::Fruit;

  public:
    void whatAmI() { std::cout << "please dont talk to me again." << std::endl; }
    void whatAmI_plus() { std::cout << "Dont talk to me plase." << std::endl; }
};

// Helper function
void func(Fruit &f) { f.whatAmI(); }
void func(Fruit *f) { f->whatAmI(); }

int main() {
    Fruit fruit("orange");
    fruit.whatAmI();
    Fruit2 *f = new Fruit2("banana");
    func(f);
    Fruit2 f2("Walter White");
    func(f2);
    return 0;
}
