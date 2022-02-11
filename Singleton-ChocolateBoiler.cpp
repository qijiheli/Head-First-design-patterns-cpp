#include <iostream>


class ChocolateBoiler
{
private:
    bool empty;
    bool boiled;
    static ChocolateBoiler* uniqueInstance;
    ChocolateBoiler() {
        empty = true;
        boiled = false;
    }
public:
    static ChocolateBoiler* getInstance() {
        if (uniqueInstance == nullptr) {
            uniqueInstance = new ChocolateBoiler;
        }
        return uniqueInstance;
    }
    void fill() {
        if (isEmpty()) {
            empty = false;
            boiled = false;
        }
    }
    void drain() {
        if (!isEmpty() && isBoiled()) {
            empty = true;
        }
    }
    void boil() {
        if(!isEmpty() && !isBoiled()) {
            boiled = true;
        }
    }
    bool isEmpty() {
        return empty;
    }
    bool isBoiled() {
        return boiled;
    }
};
