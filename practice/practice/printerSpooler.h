#ifndef PRINTERSPOOLER_H
#define PRINTERSPOOLER_H

#include "Queue.h"      // your queue implementation
#include "PrinterJob.h"
#include <iostream>
using namespace std;

class PrinterSpooler {
    Queue<PrinterJob> jobQueue;
    bool isPrinting;
public:
    PrinterSpooler() {
        isPrinting = false;
    }

    // Add a new job to queue
    void addJob(const PrinterJob& job) {
        jobQueue.enQueue(job);
        cout << "Job added: " << job.getName()
            << " (" << job.getPages() << " pages)" << endl;
    }

    // Process jobs in FIFO order
    void processJobs() {
        if (jobQueue.isEmpty()) {
            cout << "No jobs in the queue.\n";
            return;
        }

        isPrinting = true;
        while (!jobQueue.isEmpty()) {
            PrinterJob current = jobQueue.deQueue();
            current.printJob();

            // Print pages (just messages — no delay)
            for (int i = 1; i <= current.getPages(); i++) {
                cout << "   >> Printing page " << i
                    << " of " << current.getPages() << endl;
            }
            cout << "✅ Job completed: " << current.getName() << "\n\n";
        }
        isPrinting = false;
    }

    bool hasJobs() const {
        return !jobQueue.isEmpty();
    }
};
#endif

