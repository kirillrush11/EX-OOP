#include <iostream>

using namespace std;

class A{
private:
    int* value;
public:
    A() : value(){cout << "base constr 0" << endl;}; // base constr

    A(int val) : value(new int(val)){cout << "base constr val" << endl;}; // base constr with value

    A(const A &other) { // copy constr
        value = new int(*other.value);
        cout << "copy constr" << endl;
    }

    A& operator=(const A& other){ // copy asigment operation
        if(this != &other){
            delete value;
            value = new int(*other.value);
        }
        return *this;
    }

    A(A&& other) noexcept { // replace constr
        value = other.value;
        other.value = nullptr;
        cout << "replace constr" << endl;
    }

    A& operator=(A&& other) noexcept { // replace asigment operation
        if (this!=&other){
            delete value;
            value = other.value;
            other.value = nullptr;
        }
        return *this;
    }

    int* getValue(){ // getter
        return value;
    }

    ~A(){ // destructor
        delete value;
        cout << "Destructor" << endl;

    }
};

int main()
{
    A a1; // base constr
    A a2(10); // base value constr
    A a3(a2); // copy constr
    A a4(move(a1)); // replace constr
    return 0;
}
