#include "iostream"
class Mage{
protected:
    int health;
    int damage;
public:
    virtual void attack() const;
};

class FireMage : public Mage{
private:
    int health;
    int damage;
public:
    void attack() const override{
        std::cout << "Summer";
    }
};

class FrostMage : public Mage{
private:
    int health;
    int damage;
public:
    void attack() const override{
        std::cout << "Winter";
    }
};

class MageCreator{
public:
    virtual void createMage() = 0;
        virtual ~MageCreator() = default;
};

class FireMageCreator : public MageCreator{
public:
    virtual void createMage(){
        int hp, damage;
        std::cout << "12312313";
        std:: cin >> hp >> damage;
    }
    virtual ~FireMageCreator() = default;
};

class FrostMageCreator : public MageCreator{
public:
    virtual void createMage(){
        int hp, damage;
        std::cout << "123131";
        std:: cin >> hp >> damage;
    }
    virtual ~FrostMageCreator() = default;
};


class MageManager{
public:
    void add_fireMage(){
        fireCreator.createMage();
        std::cout << "Fire good";
    }
    void add_frostMage(){
        frostCreator.createMage();
        std::cout << "Frost good";
    }
private:
    FireMageCreator fireCreator;
    FrostMageCreator frostCreator;
};

int main(){
    std::cout << "choose character: \n"
                 "1. FireMage \n"
                 "2. FrostMage \n";
    int type;
    std::cin >> type;
    MageManager man;
    if (type == 1){
        man.add_fireMage();
    } else if (type == 2){
        man.add_frostMage();
    }
    return 0;
}




