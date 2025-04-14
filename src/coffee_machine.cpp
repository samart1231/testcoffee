#include "coffee_machine.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

void CoffeeMachine::showMenu() {
    std::cout << "Welcome to the Coffee Machine!" << std::endl;
    std::cout << "1. Select Coffee" << std::endl; // อัปเดตข้อความเป็น "Select Coffee"
    std::cout << "2. Bread Menu" << std::endl;
    std::cout << "3. Checkout" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

void CoffeeMachine::run() {
    int choice;
    do {
        showMenu();
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleCoffeeSelection();
                break;
            case 2:
                handleBreadSelection();
                break;
            case 3:
                checkout();
                break;
            case 4:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (choice != 4);
}

void CoffeeMachine::handleCoffeeSelection() {
    int coffeeChoice;
    std::cout << "Select your coffee type: " << std::endl;
    std::cout << "1. Espresso - $2.50" << std::endl;
    std::cout << "2. Cappuccino - $3.00" << std::endl;
    std::cout << "3. Latte - $3.50" << std::endl;
    std::cout << "Select an option: ";
    std::cin >> coffeeChoice;

    std::string coffee = (coffeeChoice == 1) ? "Espresso" : (coffeeChoice == 2) ? "Cappuccino" : "Latte";
    double basePrice = (coffeeChoice == 1) ? 2.50 : (coffeeChoice == 2) ? 3.00 : 3.50;

    int sizeChoice;
    std::cout << "Select cup size: " << std::endl;
    std::cout << "1. Small (+$0.00)" << std::endl;
    std::cout << "2. Medium (+$0.50)" << std::endl;
    std::cout << "3. Large (+$1.00)" << std::endl;
    std::cout << "Select an option: ";
    std::cin >> sizeChoice;

    double sizeCost = (sizeChoice == 2) ? 0.50 : (sizeChoice == 3) ? 1.00 : 0.00;

    int additionChoice;
    std::cout << "Would you like to add milk or sugar?" << std::endl;
    std::cout << "1. Add Milk (+$0.30)" << std::endl;
    std::cout << "2. Add Sugar (+$0.20)" << std::endl;
    std::cout << "3. Add Both Milk and Sugar (+$0.50)" << std::endl;
    std::cout << "4. None (+$0.00)" << std::endl;
    std::cout << "Select an option: ";
    std::cin >> additionChoice;

    double milkCost = (additionChoice == 1 || additionChoice == 3) ? 0.30 : 0.00;
    double sugarCost = (additionChoice == 2 || additionChoice == 3) ? 0.20 : 0.00;

    double totalCost = basePrice + sizeCost + milkCost + sugarCost;

    std::string description = coffee + " (";
    description += (sizeChoice == 1) ? "Small" : (sizeChoice == 2) ? "Medium" : "Large";
    if (additionChoice == 1 || additionChoice == 3) description += ", Milk";
    if (additionChoice == 2 || additionChoice == 3) description += ", Sugar";
    description += ")";

    addItemToCart(description, totalCost);
    std::cout << "You added: " << description << " - $" << std::fixed << std::setprecision(2) << totalCost << std::endl;
}

void CoffeeMachine::showBreadMenu() {
    std::cout << "Bread Menu:" << std::endl;
    std::cout << "1. Whole Wheat - $2.00" << std::endl;
    std::cout << "2. Croissant - $2.50" << std::endl;
    std::cout << "3. Bagel - $1.50" << std::endl;
    std::cout << "4. Back to Main Menu" << std::endl;
}

void CoffeeMachine::handleBreadSelection() {
    int breadChoice;
    do {
        showBreadMenu();
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

void CoffeeMachine::addItemToCart(const std::string &item, double price) {
    cart.emplace_back(item, price);
    std::cout << item << " added to your cart for $" << std::fixed << std::setprecision(2) << price << "." << std::endl;
}

void CoffeeMachine::checkout() {
    if (cart.empty()) {
        std::cout << "Your cart is empty. Add items before checking out." << std::endl;
        return;
    }

    double totalCost = 0.0;
    std::cout << "Cart Summary:" << std::endl;
    for (const auto& item : cart) {
        std::cout << "- " << item.first << " - $" << std::fixed << std::setprecision(2) << item.second << std::endl;
        totalCost += item.second;
    }
    std::cout << "Total: $" << std::fixed << std::setprecision(2) << totalCost << std::endl;

    writeCartToFile("cart.txt", totalCost);
    generatePaymentQR();

    cart.clear();
    std::cout << "Thank you for your purchase!" << std::endl;
}

void CoffeeMachine::writeCartToFile(const std::string &filename, double totalCost) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to create file for cart details." << std::endl;
        return;
    }
    for (const auto& item : cart) {
        file << item.first << "," << std::fixed << std::setprecision(2) << item.second << std::endl;
    }
    file << "Total," << std::fixed << std::setprecision(2) << totalCost << std::endl;
    file.close();
    std::cout << "Cart details written to " << filename << std::endl;
}

void CoffeeMachine::generatePaymentQR() {
    int result = system("python ../scripts/generate_payment_qr.py");
    if (result != 0) {
        std::cerr << "Error: Failed to execute Python script." << std::endl;
    }
}