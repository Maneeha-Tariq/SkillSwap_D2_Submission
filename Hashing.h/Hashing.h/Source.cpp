//#include <iostream>
//#include "Hashing.h" // Ensure this filename matches your header
//
//using namespace std;
//
//void showMenu() {
//    cout << "\n========== HASH TABLE TEST MENU ==========" << endl;
//    cout << "1. Insert Element" << endl;
//    cout << "2. Search Element" << endl;
//    cout << "3. Remove Element" << endl;
//    cout << "4. Show Stats (Size, Count, Load Factor)" << endl;
//    cout << "5. Exit" << endl;
//    cout << "===========================================" << endl;
//    cout << "Enter choice: ";
//}
//
//int main() {
//    HashTable ht;
//    int choice, value;
//
//    while (true) {
//        showMenu();
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter value to insert: ";
//            cin >> value;
//            ht.insert(value);
//            cout << "Inserted " << value << endl;
//            break;
//
//        case 2:
//            cout << "Enter value to search: ";
//            cin >> value;
//            if (ht.search(value))
//                cout << "Result: Value " << value << " FOUND in table." << endl;
//            else
//                cout << "Result: Value NOT found." << endl;
//            break;
//
//        case 3:
//            cout << "Enter value to remove: ";
//            cin >> value;
//            ht.remove(value);
//            cout << "Attempted removal of " << value << endl;
//            break;
//
//        case 4:
//            cout << "\n--- Current Statistics ---" << endl;
//            cout << "Entries Count: " << ht.getNoOfElements() << endl;
//            cout << "Load Factor:   " << ht.loadFactor() << " / 0.75" << endl;
//            break;
//
//        case 5:
//            cout << "Exiting program..." << endl;
//            return 0;
//
//        default:
//            cout << "Invalid choice! Try again." << endl;
//        }
//    }
//
//    return 0;
//}