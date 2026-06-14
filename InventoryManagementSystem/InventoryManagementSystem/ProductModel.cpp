#include "ProductModel.h"
#include <iostream>


bool ProductModel::connectToDatabase(const string& dbName) {
    if (sqlite3_open(dbName.c_str(), &database) != SQLITE_OK) {
        cout << "Error opening database: " << sqlite3_errmsg(database) << endl;
        return false;
    }
    cout << "Database connected successfully." << endl;
    return true;
}

void ProductModel::initializeTable() {
    const char* createTableSQL =
        "CREATE TABLE IF NOT EXISTS products ("
        "id INTEGER PRIMARY KEY, "
        "name TEXT NOT NULL, "
        "price REAL NOT NULL, "
        "quantity INTEGER NOT NULL, "
        "type TEXT NOT NULL);";

    char* errorMessage = nullptr;
    if (sqlite3_exec(database, createTableSQL, nullptr, nullptr, &errorMessage) != SQLITE_OK) {
        cout << "Table creation failed: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    }
    else {
        cout << "Table is ready." << endl;
    }
}

bool ProductModel::insertProduct(const Product& product)
{
    const char* sqlInsert = "INSERT INTO products (id, name, price, quantity, type) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(database, sqlInsert, -1, &statement, nullptr) != SQLITE_OK) {
        cout << "Failed to prepare INSERT: " << sqlite3_errmsg(database) << endl;
        return false;
    }

    sqlite3_bind_int(statement, 1, product.getId());
    sqlite3_bind_text(statement, 2, product.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(statement, 3, product.getPrice());
    sqlite3_bind_int(statement, 4, product.getQuantity());
    sqlite3_bind_text(statement, 5, product.getType().c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(statement) != SQLITE_DONE) {
        cout << "Insert failed: " << sqlite3_errmsg(database) << endl;
        sqlite3_finalize(statement);
        return false;
    }

    sqlite3_finalize(statement);
    return true;
}

bool ProductModel::findProductById(int productId) {
    if (!database) {
        cout << "Database not initialized." << endl;
        return false;
    }

    const char* sqlSelect = "SELECT * FROM products WHERE id = ?;";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(database, sqlSelect, -1, &statement, nullptr) != SQLITE_OK) {
        cout << "Prepare failed: " << sqlite3_errmsg(database) << endl;
        return false;
    }

    sqlite3_bind_int(statement, 1, productId);
    bool exists = (sqlite3_step(statement) == SQLITE_ROW);

    sqlite3_finalize(statement);
    return exists;
}

bool ProductModel::removeProduct(int productId) {
    if (!database) {
        cout << "Database not initialized." << endl;
        return false;
    }

    const char* sqlDelete = "DELETE FROM products WHERE id = ?;";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(database, sqlDelete, -1, &statement, nullptr) != SQLITE_OK) {
        cout << "Failed to prepare DELETE: " << sqlite3_errmsg(database) << endl;
        return false;
    }

    sqlite3_bind_int(statement, 1, productId);

    if (sqlite3_step(statement) != SQLITE_DONE) {
        cout << "Delete failed: " << sqlite3_errmsg(database) << endl;
        sqlite3_finalize(statement);
        return false;
    }

    sqlite3_finalize(statement);
    return true;
}

bool ProductModel::modifyProduct(int productId, const Product& product) {
    if (!database) {
        cout << "Database not initialized." << endl;
        return false;
    }

    const char* sqlUpdate =
        "UPDATE products SET name = ?, price = ?, quantity = ?, type = ? WHERE id = ?;";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(database, sqlUpdate, -1, &statement, nullptr) != SQLITE_OK) {
        cout << "Failed to prepare UPDATE: " << sqlite3_errmsg(database) << endl;
        return false;
    }

    sqlite3_bind_text(statement, 1, product.getName().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_double(statement, 2, product.getPrice());
    sqlite3_bind_int(statement, 3, product.getQuantity());
    sqlite3_bind_text(statement, 4, product.getType().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(statement, 5, productId);

    if (sqlite3_step(statement) != SQLITE_DONE) {
        cout << "Update failed: " << sqlite3_errmsg(database) << endl;
        sqlite3_finalize(statement);
        return false;
    }

    sqlite3_finalize(statement);
    return true;
}

vector<Product> ProductModel::fetchAllProducts() {
    vector<Product> productList;
    const char* sqlSelectAll = "SELECT * FROM products;";
    sqlite3_stmt* statement;

    if (sqlite3_prepare_v2(database, sqlSelectAll, -1, &statement, nullptr) != SQLITE_OK) {
        cout << "Failed to prepare SELECT: " << sqlite3_errmsg(database) << endl;
        return productList;
    }

    while (sqlite3_step(statement) == SQLITE_ROW) {
        int id = sqlite3_column_int(statement, 0);
        string name = (char*)sqlite3_column_text(statement, 1);
        double price = sqlite3_column_double(statement, 2);
        int quantity = sqlite3_column_int(statement, 3);
        string type = (char*)sqlite3_column_text(statement, 4);

        productList.push_back(Product(id, name, price, quantity, type));
    }

    sqlite3_finalize(statement);
    return productList;
}

ProductModel::~ProductModel() {
    if (database) {
        sqlite3_close(database);
        database = nullptr;
        cout << "Database closed successfully." << endl;
    }
}
