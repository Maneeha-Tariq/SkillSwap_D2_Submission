#ifndef Monotonic_H
#define Monotonic_H

template <typename T>

class MonotonicQueue
{
    DECK<T> dq;

    bool increasing; // true = monotonic increasing, false = decreasing

    bool compareMonotonicOrder(const T& qValue, const T& newValue)
    {
        if (increasing)

        {
            return qValue > newValue;
        }
        else
            return qValue < newValue;

    }
public:

    MonotonicQueue(bool monotonicIncreasing = true)
    {
        increasing = monotonicIncreasing;

    }
    void enQueue(T x)
    {
        while (!dq.isEmpty() && compareMonotonicOrder(dq.getElementAtRear(), x))

            dq.removeElementFromRear();

        dq.insertElementAtRear(x);

    }



    T deQueue()
    {

        if (dq.isEmpty())

            exit(0);

        return dq.removeElementFromFront();

    }

    T getElementAtFront()

    {

        if (dq.isEmpty())

            exit(0);

        return dq.getElementAtFront();

    }

    T getElementAtRear()

    {

        if (dq.isEmpty())

            exit(0);

        return dq.getElementAtRear();

    }

    bool isEmpty()

    {
        return dq.isEmpty();

    }

    int getCapacity()

    {

        return dq.getCapacity();

    }

    int getNoOfElements()

    {

        return dq.getNoOfElements();

    }

    bool isIncreasing()
    {

        return increasing;

    }
};
#endif


