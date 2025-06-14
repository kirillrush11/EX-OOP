#include <iostream>

using namespace std;
class Car{
    string data;
public:
    Car() : data(""){};

    string getData(){
        return data;
    }

    void updateData(string tmp){
        data+=tmp;
    }
};

class Developer{
public:
    virtual void createMotor() = 0;
    virtual void putOil() = 0;
    virtual Car* getCar() = 0;
};

class LuxuryCarDeveloper : public Developer{
    Car* car;
public:
    LuxuryCarDeveloper(){
        car = new Car();
    }

    ~LuxuryCarDeveloper(){
        delete car;
    }
    void createMotor() override{
        car->updateData("Luxury Motor created");
    }

    void putOil() override{
        car->updateData("Luxury Oil put");
    }

    Car* getCar() override{
        return car;
    }
};

class BichCarDeveloper : public Developer{
    Car* car;
public:
    BichCarDeveloper(){
        car  = new Car();
    }

    ~BichCarDeveloper(){
        delete car;
    }

    void createMotor() override{
        car->updateData("Buch Motor created");
    }

    void putOil() override{
        car->updateData("Bich oil put");
    }

    Car* getCar() override{
        return car;
    }
};

class Director{
    Developer* developer;
public:
    Director(Developer* dev) : developer(dev){};
    void setDeveloper(Developer* dev){
        developer = dev;
    }

    Car* putOnlyOil(){
        developer->putOil();
        return developer->getCar();
    }

    Car* createOnlyMotor(){
        developer->createMotor();
        return developer->getCar();
    }
};

int main()
{
    Developer* luxDeveloper = new LuxuryCarDeveloper();
    Director director(luxDeveloper);
    Car* luxCar = director.createOnlyMotor();
    cout << luxCar->getData() << endl;
    luxCar->updateData("+++++");
    cout << luxCar->getData() << endl;
    return 0;
}
#include <iostream>

using namespace std;
class Car{
    string data;
public:
    Car() : data(""){};

    string getData(){
        return data;
    }

    void updateData(string tmp){
        data+=tmp;
    }
};

class Developer{
public:
    virtual void createMotor() = 0;
    virtual void putOil() = 0;
    virtual Car* getCar() = 0;
};

class LuxuryCarDeveloper : public Developer{
    Car* car;
public:
    LuxuryCarDeveloper(){
        car = new Car();
    }

    ~LuxuryCarDeveloper(){
        delete car;
    }
    void createMotor() override{
        car->updateData("Luxury Motor created");
    }

    void putOil() override{
        car->updateData("Luxury Oil put");
    }

    Car* getCar() override{
        return car;
    }
};

class BichCarDeveloper : public Developer{
    Car* car;
public:
    BichCarDeveloper(){
        car  = new Car();
    }

    ~BichCarDeveloper(){
        delete car;
    }

    void createMotor() override{
        car->updateData("Buch Motor created");
    }

    void putOil() override{
        car->updateData("Bich oil put");
    }

    Car* getCar() override{
        return car;
    }
};

class Director{
    Developer* developer;
public:
    Director(Developer* dev) : developer(dev){};
    void setDeveloper(Developer* dev){
        developer = dev;
    }

    Car* putOnlyOil(){
        developer->putOil();
        return developer->getCar();
    }

    Car* createOnlyMotor(){
        developer->createMotor();
        return developer->getCar();
    }
};

int main()
{
    Developer* luxDeveloper = new LuxuryCarDeveloper();
    Director director(luxDeveloper);
    Car* luxCar = director.createOnlyMotor();
    cout << luxCar->getData() << endl;
    luxCar->updateData("+++++");
    cout << luxCar->getData() << endl;
    return 0;
}
