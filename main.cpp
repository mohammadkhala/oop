#include <iostream>
#include <string>
#include <cctype>

class Product {
public:
    Product(const std::string& name, double price, int stock) {
        if (!isValidName(name)) {
            std::cerr << "Invalid name. Name must contain only letters and spaces, and be at least 3 characters long" << std::endl;
            exit(1);
        }
        productName = capitalize(name);
        if (price <= 10) {
            std::cerr << "Invalid price. Price must be greater than 10" << std::endl;
            exit(1);
        }
        if (stock < 0) {
            std::cerr << "Invalid stock. Stock cannot be negative" << std::endl;
            exit(1);
        }
        this->price = price;
        this->stock = stock;
    }

    ~Product() {
        std::cout << "Product " << productName << " removed from inventory" << std::endl;
    }

    void setProductName(const std::string& name) {
        if (!isValidName(name)) {
            std::cerr << "Invalid name. Name must contain only letters and spaces, and be at least 3 characters long" << std::endl;
            return;
        }
        productName = capitalize(name);
    }

    void setPrice(double price) {
        if (price <= 10) {
            std::cerr << "Invalid price. Price must be greater than 10" << std::endl;
            return;
        }
        this->price = price;
    }

    void setStock(int stock) {
        if (stock < 0) {
            std::cerr << "Invalid stock. Stock cannot be negative" << std::endl;
            return;
        }
        this->stock = stock;
    }

    std::string getProductName() const {
        return productName;
    }

    double getPrice() const {
        return price;
    }

    int getStock() const {
        return stock;
    }

    void addStock(int quantity) {
        if (quantity <= 0) {
            std::cerr << "Invalid quantity. Quantity must be greater than 0" << std::endl;
            return;
        }
        stock += quantity;
        std::cout << "Added " << quantity << " units of " << productName << " to stock." << std::endl;
    }

    void sell(int quantity) {
        if (quantity <= 0) {
            std::cerr << "Invalid quantity. Quantity must be greater than 0" << std::endl;
            return;
        }
        if (quantity > stock) {
            std::cerr << "Not enough stock available for " << productName << "." << std::endl;
            return;
        }
        stock -= quantity;
        std::cout << "Sold " << quantity << " units of " << productName << "." << std::endl;
    }

    void displayProductDetails() const {
        std::cout << "Product Name: " << productName << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;
        std::cout << "--------------------" << std::endl;
    }

private:
    bool isValidName(const std::string& name) {
        if (name.length() < 3) {
            return false;
        }
        for (char c : name) {
            if (!isalpha(c) && !isspace(c)) {
                return false;
            }
        }
        return true;
    }

    std::string capitalize(const std::string& str) {
        std::string result = str;
        if (!result.empty()) {
            result[0] = toupper(result[0]);
        }
        return result;
    }

    std::string productName;
    double price;
    int stock;
};

int main() {
    // Create products
    Product product1("laptop", 1500.0, 10);
    Product product2("smartphone", 800.0, 20);

    // Display product details
    product1.displayProductDetails();
    product2.displayProductDetails();

    // Add stock
    product1.addStock(5);

    // Sell product
    product2.sell(3);

    // Try selling more than available stock
    product2.sell(50);

    // Update product name
    product1.setProductName("la"); // Invalid name
    product1.setProductName("gaming laptop");

    // Update price
    product2.setPrice(-100); // Invalid price
    product2.setPrice(750);

    // Display updated details
    product1.displayProductDetails();
    product2.displayProductDetails();

    return 0;
}
