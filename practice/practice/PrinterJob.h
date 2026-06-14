#ifndef PRINTERJOB_H
#define PRINTERJOB_H
#include <iostream>
#include <string>
using namespace std;

class PrinterJob {
    string jobName;
    int totalPages;
public:
    PrinterJob(string name = "", int pages = 0) {
        jobName = name;
        totalPages = pages;
    }

    void printJob() const {
        cout << "Printing Job: " << jobName
            << " (" << totalPages << " pages)" << endl;
    }

    int getPages() const {
        return totalPages;
    }

    string getName() const {
        return jobName;
    }
};
#endif

