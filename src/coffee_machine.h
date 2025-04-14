#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

#include <string>
#include <vector>

class CoffeeMachine {
private:
    std::vector<std::pair<std::string, double>> cart;

    void showMainMenu();
    void showHotMenu();
    void showColdMenu();
    void showBreadMenu();
    void showCart();
    void checkout();

    void handleHotSelection();
    void handleColdSelection();  // ประกาศฟังก์ชัน handleColdSelection
    void handleBreadSelection(); // ประกาศฟังก์ชัน handleBreadSelection

    void addItemToCart(const std::string& item, double price);

public:
    void run();
};

#endif // COFFEE_MACHINE_H