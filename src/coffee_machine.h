#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

#include <vector>
#include <string>
#include <utility>

class CoffeeMachine {
private:
    std::vector<std::pair<std::string, double>> cart;

    static void showMenu();
    void showBreadMenu();
    void addItemToCart(const std::string &item, double price);
    void writeCartToFile(const std::string &filename, double totalCost);
    void generatePaymentQR();

    void handleCoffeeSelection(const std::string &coffee, double basePrice);
    void handleBreadSelection();
    void checkout();

public:
    void run();
};

#endif // COFFEE_MACHINE_H