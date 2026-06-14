#ifndef PRODUCT_VIEW_H
#define PRODUCT_VIEW_H

#include "Product.h"
#include <vector>
#include <string>

class ProductView {
public:
    void displayMenu();
    int getUserChoice();

    Product inputNewProduct();
    int inputProductIdForDelete();
    int inputProductIdForUpdate();
    Product inputUpdatedProduct(int productId);

    void displayAllProducts(const std::vector<Product>& productList);
    void displayMessage(const std::string& message);
    int inputProductIdForSearch();
};

#endif
