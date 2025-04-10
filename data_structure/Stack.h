#ifndef STACK_H
#define STACK_H

enum Error_code { underflow, overflow, success };

template <typename T>
class Stack
{
public:
    Stack() {
        count = 0;
    }

    bool isEmpty() const {
        bool outcome = true;
        if (count > 0) outcome = false;
        return outcome;
    }

    Error_code pop() {
        Error_code outcome = success;
        if (count == 0) {
            outcome = underflow;
        }
        else {
            count--;
        }
        return outcome;
    }

    Error_code push(const T& item) {
        Error_code outcome = success;
        if (count == maxStack) {
            outcome = overflow;
        }
        else {
            entry[count] = item;
            count++;
        }
        return outcome;
    }

    Error_code top(T& item) const {
        Error_code outcome = success;
        if (count == 0) {
            outcome = underflow;
        }
        else {
            item = entry[count - 1];
        }
        return outcome;
    }

private:
    static const int maxStack = 10;
    int count;
    T entry[maxStack];
};

#endif // STACK_H