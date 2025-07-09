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
void val(Fruit f) { f.whatAmI(); }  // Pass by value

template <typename T> struct temp_a {
    template <typename U> void print() { std::cout << "template a" << std::endl; } // Cannot be virtual!
};

class a {
  public:
    a() = default;
    virtual void print() { std::cout << "class a" << std::endl; }
    virtual void printWithDef(char c = 'a' ) { std::cout << "class a, def: " << c << std::endl; }
};

class b : public a {
  public:
    b() = default;
    virtual void print() { std::cout << "class b" << std::endl; }
    virtual void printWithDef(char c = 'b' ) { std::cout << "class b, def: " << c << std::endl; }
};

int main() {
    /* static vs dymainc */
    a *A = new a();
    A->printWithDef();

    a *B1 = new b();
    B1->printWithDef();

    b B2;
    B2.printWithDef();

    /*
    output:
    class a, def: a
    class b, def: a
    class b, def: b
     */

    /* template */
    temp_a<int> A1;
    A1.print<int>();

    /* virtual */
    Fruit fruit("fruit");
    fruit.whatAmI();

    Fruit2 f("fruit 2");
    ref(f);
    val(f);

    return 0;
}
