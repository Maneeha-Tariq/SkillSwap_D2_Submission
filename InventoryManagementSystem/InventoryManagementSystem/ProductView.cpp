#include "ProductView.h"
#include <iostream>
using namespace std;

void ProductView::displayMenu() {
    cout << "==============================\n";
    cout << "      Product Management       \n";
    cout << "==============================\n";
    cout << "1. Add Product\n";
    cout << "2. Delete Product\n";
    cout << "3. Update Product\n";
    cout << "4. Search Product\n";
    cout << "5. Show All Products\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int ProductView::getUserChoice() {
    int choice;
    cin >> choice;
    return choice;
}

Product ProductView::inputNewProduct()
{
    int productId, productQuantity;
    string productName, productType;
    double productPrice;

    cout << "Enter Product ID: ";
    cin >> productId;
    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, productName);
    cout << "Enter Product Price: ";
    cin >> productPrice;
    cout << "Enter Product Quantity: ";
    cin >> productQuantity;
    cin.ignore();  // clear newline before reading type
    cout << "Enter Product Type: ";
    getline(cin, productType);

    return Product(productId, productName, productPrice, productQuantity, productType);
}

int ProductView::inputProductIdForSearch() {
    int productId;
    cout << "Enter Product ID to Search: ";
   cin >> productId;
    return productId;
}

int ProductView::inputProductIdForDelete() {
    int productId;
    cout << "Enter Product ID to Delete: ";
    cin >> productId;
    return productId;
}

int ProductView::inputProductIdForUpdate() {
    int productId;
    cout << "Enter Product ID to Update: ";
    cin >> productId;
    return productId;
}

Product ProductView::inputUpdatedProduct(int productId)
{
    string updatedName, updatedType;
    double updatedPrice;
    int updatedQuantity;

    cout << "Enter New Product Name: ";
    cin.ignore();
    getline(cin, updatedName);
    cout << "Enter New Product Price: ";
    cin >> updatedPrice;
    cout << "Enter New Product Quantity: ";
    cin >> updatedQuantity;
    cin.ignore(); 
    cout << "Enter New Product Type: ";
    getline(cin, updatedType);

    return Product(productId, updatedName, updatedPrice, updatedQuantity, updatedType);
}


void ProductView::displayAllProducts(const std::vector<Product>& productList) {
    std::cout << "\n=== Product List ===\n";

    for (const auto& product : productList) {
       cout << "ID: " << product.getId()<< "\n";
       cout << "Name: " << product.getName() << "\n";
       cout << "Price: " << product.getPrice()<< "\n";
       cout << "Quantity: " << product.getQuantity() << "\n";
       cout << "------------------------\n";
    }
}

void ProductView::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}
