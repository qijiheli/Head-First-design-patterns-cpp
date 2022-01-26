#include <iostream>
#include <string>
#include <vector>


class Pizza
{
public:
    void prepare() {
        std::cout << "Preparing " + name << "\n";
        std::cout << "Tossing dough..." << "\n";
        std::cout << "Adding soure..." << "\n";
        std::cout << "Adding toppings: " << "\n";
        for (auto topping : toppings) {
            std::cout << "   " + topping << "\n";
        }
    }
    void bake() {
        std::cout << "Bake for 25 minutes at 350\n";
    }
    void cut() {
        std::cout << "Cutting the pizza into diagonal slices\n";
    }
    void box() {
        std::cout << "Place pizza in official PizzaStore box\n";
    }
    std::string getName() {
        return name;
    }


    std::string name;
    std::string dough;
    std::string sauce;
    std::vector<std::string> toppings;
};

class NYStyleCheesePizza : public Pizza
{
public:
    NYStyleCheesePizza() {
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        toppings.push_back("Grated Reggiano Cheese");
    }
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
    ChicagoStyleCheesePizza() {
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";;
        toppings.push_back("Shredded Mozzarella Cheese");
    }
    void cut() {
        std::cout << "Cutting the pizza into square slices\n";
    }
};

class PizzaStore
{
public:
    Pizza* orderPizza(std::string type) {
        Pizza* pizza;
        pizza = createPizza(type);

        pizza -> prepare();
        pizza -> bake();
        pizza -> cut();
        pizza -> box();
        return pizza; 
    }
private:
    virtual Pizza* createPizza(std::string type) = 0;
};

class NYPizzaStore : public PizzaStore
{
public:
    Pizza* createPizza(std::string item) {
        if (item == "cheese") {
            return new NYStyleCheesePizza;
        }
        /*
        else if (item == "veggie") {
            return new NYStyleVeggiePizza;
        }
        else if (item == "clam") {
            return new NYStyleClamPizza;
        }
        else if (item == "pepperoni") {
            return new NYStylePepperoniPizza;
        }
        */
        else {
            return nullptr;
        }
    }
};

class ChicagoPizzaStore : public PizzaStore
{
public:
    Pizza* createPizza(std::string item) {
        if (item == "cheese") {
            return new ChicagoStyleCheesePizza;
        }
        /*
        else if (item == "veggie") {
            return new ChicagoStyleVeggiePizza;
        }
        else if (item == "clam") {
            return new ChicagoStyleClamPizza;
        }
        else if (item == "pepperoni") {
            return new ChicagoStylePepperoniPizza;
        }
        */
        else {
            std::cout << "nothing created" << "\n";
            return nullptr;
        }
    }
};



int main () {
    PizzaStore* nyStore = new NYPizzaStore;
    PizzaStore* chicagoStore = new ChicagoPizzaStore;

    Pizza* pizza = nyStore -> orderPizza("cheese");
    std::cout << "Ethan ordered a " << pizza -> getName() << "\n";

    pizza = chicagoStore -> orderPizza("cheese");
    std::cout << "Joel ordered a " << pizza -> getName() << "\n";
}
