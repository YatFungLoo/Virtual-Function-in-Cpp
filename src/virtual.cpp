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
  public:
    Fruit2(std::string s) : Fruit(s) {}
    void whatAmI() { std::cout << "please dont talk to me again." << std::endl; }
};

// Function overloading
void func(Fruit &f) { f.whatAmI(); }
void func(Fruit *f) { f->whatAmI(); }

void ref(Fruit &f) { f.whatAmI(); } // Pass by reference
void val(Fruit f) { f.whatAmI(); } // Pass by value

int main() {
    // Fruit fruit("fruit");
    // fruit.whatAmI();
    Fruit2 f("fruit 2");
    f.whatAmI();
    ref(f);
    val(f);
    // Fruit2 f2("fruit 3");
    // func(f2);
    return 0;
}
