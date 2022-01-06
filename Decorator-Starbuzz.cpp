#include <iostream>
#include <string>

class Beverage
{
public:
    virtual double cost() = 0;
    std::string description = "Unknown Beverage";
    virtual std::string getDescription() {
        return description;
    }
};

class CondimentDecorator : public Beverage
{
public:
    virtual std::string getDescription() = 0;
};

class Espresso : public Beverage
{
public:
    Espresso() {
        description = "Espresso";
    }
    double cost() {
        return 1.99;
    }
};

class HouseBlend : public Beverage
{
public:
    HouseBlend() {
        description = "House Blend Coffee";
    }
    double cost() {
        return 0.89;
    }
};

class DarkRoast : public Beverage
{
public:
    DarkRoast() {
        description = "Dark Roast";
    }
    double cost() {
        return 0.99;
    }
};

class Decaf : public Beverage
{
public:
    Decaf() {
        description = "Decaf";
    }
    double cost() {
        return 1.05;
    }
};

class Mocha : public CondimentDecorator
{

public:
    Beverage* beverage;

    Mocha(Beverage* bvr) {
        this -> beverage = bvr;
    }
    std::string getDescription() {
        return beverage -> getDescription() + ", Mocha";
    }
    double cost() {
        return 0.20 + beverage -> cost();
    }
};

class Soy : public CondimentDecorator
{
public:
    Beverage* beverage;

    Soy(Beverage* bvr) {
        this -> beverage = bvr;
    }
    std::string getDescription() {
        return beverage -> getDescription() + ", Soy";
    }
    double cost() {
        return 0.15 + beverage -> cost();
    }
};

class Whip : public CondimentDecorator
{
public:
    Beverage* beverage;

    Whip(Beverage* bvr) {
        this -> beverage = bvr;
    }
    std::string getDescription() {
        return beverage -> getDescription() + ", Whip";
    }
    double cost() {
        return 0.10 + beverage -> cost();
    }
};


int main() {
    Beverage* beverage1 = new Espresso;
    std::cout << beverage1 -> getDescription() << " $" << beverage1 -> cost() << "\n";

    Beverage* beverage2 = new DarkRoast;
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    std::cout << beverage2 -> getDescription() << " $" << beverage2 -> cost() << "\n";

    Beverage* beverage3 = new HouseBlend;
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    std::cout << beverage3 -> getDescription() << " $" << beverage3 -> cost() << "\n";
    
    delete beverage1;
    delete beverage2;
    delete beverage3;
}
