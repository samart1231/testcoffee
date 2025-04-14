#include "coffee_machine.h"
#include <iostream>
#include <iomanip>

// ฟังก์ชันที่แสดงเมนูเครื่องดื่มเย็น
void CoffeeMachine::handleColdSelection() {
    int coldChoice;
    do {
        std::cout << "Cold Drinks Menu:" << std::endl;
        std::cout << "1. Iced Espresso - $3.00" << std::endl;
        std::cout << "2. Iced Cappuccino - $3.50" << std::endl;
        std::cout << "3. Iced Latte - $4.00" << std::endl;
        std::cout << "4. Back to Main Menu" << std::endl;

        std::cout << "Select an option: ";
        std::cin >> coldChoice;

        switch (coldChoice) {
            case 1:
                addItemToCart("Iced Espresso", 3.00);
                break;
            case 2:
                addItemToCart("Iced Cappuccino", 3.50);
                break;
            case 3:
                addItemToCart("Iced Latte", 4.00);
                break;
            case 4:
                std::cout << "Returning to main menu..." << std::endl;
                return;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (coldChoice != 4);
}

// ฟังก์ชันที่แสดงเมนูขนมปัง
void CoffeeMachine::handleBreadSelection() {
    int breadChoice;
    do {
        std::cout << "Bread Menu:" << std::endl;
        std::cout << "1. Whole Wheat - $2.00" << std::endl;
        std::cout << "2. Croissant - $2.50" << std::endl;
        std::cout << "3. Bagel - $1.50" << std::endl;
        std::cout << "4. Back to Main Menu" << std::endl;

        std::cout << "Select an option: ";
        std::cin >> breadChoice;

        switch (breadChoice) {
            case 1:
                addItemToCart("Whole Wheat", 2.00);
                break;
            case 2:
                addItemToCart("Croissant", 2.50);
                break;
            case 3:
                addItemToCart("Bagel", 1.50);
                break;
            case 4:
                std::cout << "Returning to main menu..." << std::endl;
                return;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (breadChoice != 4);
}

// ฟังก์ชันเพิ่มรายการสินค้าในตะกร้า
void CoffeeMachine::addItemToCart(const std::string& item, double price) {
    cart.emplace_back(item, price);
    std::cout << item << " added to your cart for $" << std::fixed << std::setprecision(2) << price << "." << std::endl;
}