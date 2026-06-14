#ifndef PRODUCT_MODEL_H
#define PRODUCT_MODEL_H

#include "Product.h"
#include <vector>
#include "sqlite3.h"

class ProductModel {
    sqlite3* database;  // SQLite database pointer

public:
    ProductModel() : database(nullptr) {}

    bool connectToDatabase(const string& dbName);
    void initializeTable();
    bool insertProduct(const Product& product);
    bool findProductById(int productId);
    bool removeProduct(int productId);
    bool modifyProduct(int productId, const Product& product);
    vector<Product> fetchAllProducts();

    ~ProductModel();
};

#endif
