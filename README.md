# Virtual Function in Cpp

Short write up on two function the `virtual` keywords has when dealing with inheritance within c++

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Virtual Function in Cpp](#virtual-function-in-cpp)
  - [Short Summary](#short-summary)
  - [The Diamond Pattern Problem](#the-diamond-pattern-problem)
  - [How To Run The Code](#how-to-run-the-code)

<!-- markdown-toc end -->

## Short Summary

One can create a new (sub)class that inherit properties of another class (base class), allowing (sub)class access/ call to the functions that exist the base class.

Base class function can be overwritten in subclass, in condition that the function is marked with the `virtual` keyword.

``` cpp
  public:
    Fruit(std::string s) : myName(s) {}
    virtual void whatAmI() { std::cout << myName << std::endl; } // subclass WILL NOT use this and use its own whatAmI
    void whatAmI() { std::cout << myName << std::endl; } // subclass WILL use this instead of its own whatAmI()
```

## The Diamond Pattern Problem

C++ supports multiple class inheritance, a new subclass can inherit multiple classes that can have base classes.

Problem occurs when sub-class inherit two copies of the same base class, which can be addressed by virtual inheritance, ensuring only one copy of the base class exist.

> This problem can also be resolved by using unique name for inherited function.

``` cpp
class base {
	public: 
	  void func() { std::println("Hello"); }
};

class class1 : public base { ... }
class class2 : public base { ... } // --> Ambiguity error if func() is called!

class class1 : virtual public base { ... }
class class2 : virtual public base { ... } // --> Okay!!!

class subclass : public class1, public class2 { ... }

int main() {
  subclass obj;
  obj.func();
  return 0;
}
```
## How To Run The Code

Tested with Apple clang 16.0.0.

First `cd`/ visit the base directory.

To compile/recompile the program and run the executable, run

```bash
make && ./Virtual
```

To delete the executable, run

```bash
make clean
```
