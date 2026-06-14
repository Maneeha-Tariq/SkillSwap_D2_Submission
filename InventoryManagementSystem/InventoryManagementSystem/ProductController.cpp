#include "ProductController.h"
#include <iostream>

ProductController::ProductController(const string& databaseName)
{
    productModel.connectToDatabase(databaseName);
    productModel.initializeTable();
}

void ProductController::run() {
    while (true) {
        productView.displayMenu();                     
        int userChoice = productView.getUserChoice(); 

        switch (userChoice) {
        case 1:
            addNewProduct();
            break;

        case 2:
            removeExistingProduct();
            break;

        case 3:
            updateExistingProduct();
            break;

        case 4:
            searchProductById();
            break;

        case 5:
            displayAllProducts();
            break;

        case 6:
            productView.displayMessage("Program terminated!"); 
            return;

        default:
            productView.displayMessage("Invalid choice! Please try again."); 
        }
    }
}

void ProductController::addNewProduct()
{
    Product newProduct = productView.inputNewProduct(); 
    if (productModel.insertProduct(newProduct))
        productView.displayMessage("Product added successfully!"); 
    else
        productView.displayMessage("Error: Could not add the product!"); 
}

void ProductController::removeExistingProduct()
{
    int productIdToDelete = productView.inputProductIdForDelete(); 
    if (productModel.removeProduct(productIdToDelete))
        productView.displayMessage("Product deleted successfully!"); 
    else
        productView.displayMessage("Product not found!"); 
}

void ProductController::updateExistingProduct()
{
    int productIdToUpdate = productView.inputProductIdForUpdate();  
    Product updatedProductData = productView.inputUpdatedProduct(productIdToUpdate); 

    if (productModel.modifyProduct(productIdToUpdate, updatedProductData))
        productView.displayMessage("Product updated successfully!"); 
    else
        productView.displayMessage("Error: Could not update the product!"); 
}

void ProductController::searchProductById()
{
    int productIdToSearch = productView.inputProductIdForSearch(); 
    if (productModel.findProductById(productIdToSearch))
        productView.displayMessage("Product found!"); 
    else
        productView.displayMessage("Product not found!"); 
}

void ProductController::displayAllProducts()
{
    vector<Product> productList = productModel.fetchAllProducts();
    productView.displayAllProducts(productList); 
}
