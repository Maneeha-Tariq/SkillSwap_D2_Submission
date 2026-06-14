#include "ProductController.h"
#include <iostream>

int main() {
    ProductController controller("inventory.db");
    controller.run();

    return 0;
}
