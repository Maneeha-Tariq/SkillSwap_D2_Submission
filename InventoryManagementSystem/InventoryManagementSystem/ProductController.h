#ifndef PRODUCT_CONTROLLER_H
#define PRODUCT_CONTROLLER_H

#include "ProductModel.h"
#include "ProductView.h"

class ProductController {
    ProductModel productModel;
    ProductView productView;

public:
    ProductController(const string& databaseName);

    void run();
    void addNewProduct();
    void removeExistingProduct();
    void updateExistingProduct();
    void searchProductById();
    void displayAllProducts();
};

#endif
