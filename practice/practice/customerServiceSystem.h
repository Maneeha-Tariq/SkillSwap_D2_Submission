#ifndef CUSTOMERSERVICESYSTEM_H
#define CUSTOMERSERVICESYSTEM_H

#include <iostream>
#include <String>
#include "Queue.h"   // 👈 aapki di hui Queue class
using namespace std;

// 🎟 Customer Ticket structure
struct Ticket {
    int ticketNumber;
    string customerName;

    Ticket() : ticketNumber(0), customerName("") {}
    Ticket(int t, string name) : ticketNumber(t), customerName(name) {}
};

// 🧾 CustomerServiceSystem class
class CustomerServiceSystem {
private:
    Queue<Ticket> ticketQueue;   // FIFO queue for customers
    int nextTicketNumber;        // ticket numbers auto increment

public:
    CustomerServiceSystem() {
        nextTicketNumber = 1;
    }

    // Customer ko ticket dena (enqueue)
    void issueTicket(const string& name) {
        Ticket t(nextTicketNumber++, name);
        ticketQueue.enQueue(t);
        cout << "✅ Ticket issued to " << name
            << " | Ticket No: " << t.ticketNumber << endl;
    }

    // Next customer ko serve karna (dequeue)
    void serveNextCustomer() {
        if (ticketQueue.isEmpty()) {
            cout << "⚠ No customers in queue.\n";
            return;
        }
        Ticket t = ticketQueue.deQueue();
        cout << "🎧 Serving Customer: " << t.customerName
            << " | Ticket No: " << t.ticketNumber << endl;
    }

    // Queue ka status check karna
    void showPendingCustomers() const {
        cout << "📊 Total Pending Customers: "
            << ticketQueue.getNoOfElements() << endl;
    }

    // All customers ko sequentially serve karna
    void serveAllCustomers() {
        if (ticketQueue.isEmpty()) {
            cout << "⚠ No customers to serve.\n";
            return;
        }
        cout << "\n🚀 Serving all customers in FIFO order...\n";
        while (!ticketQueue.isEmpty()) {
            Ticket t = ticketQueue.deQueue();
            cout << "🎧 Serving: " << t.customerName
                << " | Ticket No: " << t.ticketNumber << endl;
        }
        cout << "✅ All customers have been served.\n\n";
    }

    // Menu-driven interface (for testing)
    void runMenu() {
        int choice;
        do {
            cout << "====== 🧾 Customer Service System ======\n";
            cout << "1. Issue Ticket\n";
            cout << "2. Serve Next Customer\n";
            cout << "3. Serve All Customers\n";
            cout << "4. Show Pending Customers\n";
            cout << "0. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                string name;
                cout << "Enter customer name: ";
                cin >> name;
                issueTicket(name);
                break;
            }
            case 2:
                serveNextCustomer();
                break;
            case 3:
                serveAllCustomers();
                break;
            case 4:
                showPendingCustomers();
                break;
            case 0:
                cout << "👋 Exiting System...\n";
                break;
            default:
                cout << "❌ Invalid choice. Try again.\n";
            }
            cout << endl;
        } while (choice != 0);
    }
};

#endif

