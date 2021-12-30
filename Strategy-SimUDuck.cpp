//SimUDuck
#include <iostream>


class FlyBehavior
{
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior 
{
public:
    void fly() {
        std::cout << "I'm flying!\n";
    }
};

class FlyNoWay : public FlyBehavior 
{
public:
    void fly() {
        std::cout << "I can't fly\n";
    }
};

class FlyRocketPowered : public FlyBehavior
{
public:
    void fly() {
        std::cout << "I'm flying with a rocket!\n";
    }
};


class QuackBehavior
{
public:
    virtual void quack() = 0;
};

class Quack : public QuackBehavior 
{
public:    
    void quack() {
        std::cout << "Quack!\n";
    }
};

class MuteQuack : public QuackBehavior 
{
public:
    void quack() {
        std::cout << "<< Silence >>\n";
    }
};

class Squeak : public QuackBehavior 
{
public:
    void quack() {
        std::cout << "Squeak!\n";
    }
};


class Duck
{
public:
    FlyBehavior* pFlyBehavior;
    QuackBehavior* pQuackBehavior;

    virtual void display() = 0;
    void performFly() {
        pFlyBehavior -> fly();
    }
    void performQuack() {
        pQuackBehavior -> quack();
    }
    void swim() {
        std::cout<<"All ducks float, even decoys!"<<'\n';
    }
    void setFlyBehavior(FlyBehavior* fb) {
        pFlyBehavior = fb;
    }
    void setQuackBehavior(QuackBehavior* qb) {
        pQuackBehavior = qb;
    }
};

class MallardDuck : public Duck 
{
public:
    MallardDuck() {
        pFlyBehavior = new FlyWithWings;
        pQuackBehavior = new Quack;
    }
    void display() {
        std::cout << "I'm a real Mallard duck!\n";
    }
    
};

class ModelDuck : public Duck
{
public:
    ModelDuck() {
        pFlyBehavior = new FlyNoWay;
        pQuackBehavior = new Quack;
    }
    void display() {
        std::cout << "I'm a model duck!\n";
    }
};



int main() {
    Duck* mallard = new MallardDuck;
    mallard -> performQuack();
    mallard -> performFly();

    Duck* model = new ModelDuck;
    model -> performFly();
    model -> setFlyBehavior(new FlyRocketPowered);
    model -> performFly();

    return 1;
}
