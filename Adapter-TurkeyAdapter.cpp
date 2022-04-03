#include <iostream>


class Duck
{
public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class MallardDuck : public Duck
{
public:
    void quack() {
        std::cout << "Quack\n";
    }
    void fly() {
        std::cout << "I'm flying\n";
    }
};

class Turkey
{
public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey : public Turkey
{
public:
    void gobble() {
        std::cout << "Gobble gobble\n";
    }
    void fly() {
        std::cout << "I'm flying a short distance\n";
    }
};

class TurkeyAdapter : public Duck
{
public:
    Turkey* turkey;

    TurkeyAdapter(Turkey* _turkey) {
        this -> turkey = _turkey;
    }
    void quack() {
        turkey -> gobble();
    }
    void fly() {
        for (int i = 0; i < 5; i++) {
            turkey -> fly();
        }
    }
};

static void testDuck(Duck* duck) {
    duck -> quack();
    duck -> fly();
}


int main() {
    MallardDuck* duck = new MallardDuck;

    WildTurkey* turkey = new WildTurkey;
    Duck* turkeyAdapter = new TurkeyAdapter(turkey);

    std::cout << "\nThe Turkey says...\n";
    turkey -> gobble();
    turkey -> fly();

    std::cout << "\nThe Duck says...\n";
    testDuck(duck);

    std::cout << "\nThe TurkeyAdapter says...\n";
    testDuck(turkeyAdapter);
}
