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

One can create a new (sub)class that inheriate properties of another class (base class), which allow the new (sub)class access/ call the functions that exist within the base class.

C++ allows (sub)class function to be overwritten, in condition that the base class markes that specific overwritten function with the `virtual` keywards.

``` cpp
  public:
    Fruit(std::string s) : myName(s) {}
    virtual void whatAmI() { std::cout << myName << std::endl; } // subclass WILL NOT use this and use its own whatAmI
    void whatAmI() { std::cout << myName << std::endl; } // subclass WILL use this instead of its own whatAmI()
```

Play around with the provided code and see for yourself.

## The Diamond Pattern Problem

C++ supports multiple class inheritance, a new subclass can inherate multiple classes that can have base classes.

> This problem can also be resolved by using unique name for inherated function.

``` cpp
class base {
	public: 
	  func() { std::println("Hello"); }
}

class class1 : public base { ... } // --> Ambiguity error if func() is called!
class class2 : public base { ... }

class class1 : public base { ... } // --> Okay!!!
class class2 : public base { ... }

class subclass : public class1 : public clsas2 { ... }

int main() {
	subclass *sb = new subclass();
	sb->func();
	return 0;
}
```
## How To Run The Code

Tested with Apple clang 16.0.0.

First `cd`/ visit the base directory.

To compile/recompile the program and run the exectable, run

```bash
make && ./Virtual
```

To delete the exectable, run

```bash
make clean
```
