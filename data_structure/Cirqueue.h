#ifndef CIRQUEUE_H
#define CIRQUEUE_H

enum Error_code { underflow, overflow, success };

const int maxqueue = 100;

template<class Queue_entry>
class Cirqueue
{
public:
    Cirqueue();
    bool isEmpty() const;
    Error_code append_front(const Queue_entry& item);
    Error_code serve_rear();
    Error_code serve_front();
    Error_code append_rear(const Queue_entry& item);
    Error_code retrieve_front(Queue_entry& item) const;
    Error_code retrieve_rear(Queue_entry& item) const;
    Queue_entry show(int i) const;
    void exchage(int a, int b);
    bool full();
    int size();
    void clear();
    int currentPosition();
    Error_code serve_and_retrieve(Queue_entry& item);

private:
    int count;
    int front, rear;
    Queue_entry entry[maxqueue];
};

template<class Queue_entry>
Cirqueue<Queue_entry>::Cirqueue() {
    count = 0;
    front = 0;
    rear = 0;
}

template<class Queue_entry>
bool Cirqueue<Queue_entry>::isEmpty() const {
    return count == 0;
}

template<class Queue_entry>
Error_code Cirqueue<Queue_entry>::append_front(const Queue_entry& item) {
    if (count == maxqueue) return overflow;
    front = (front - 1 + maxqueue) % maxqueue;
    entry[front] = item;
    count++;
    return success;
}

template<class Queue_entry>
Error_code Cirqueue<Queue_entry>::serve_rear() {
    if (isEmpty()) {
        return underflow;
    }
    rear = (rear - 1 + maxqueue) % maxqueue;
    count--;
    return success;
}

template<class Queue_entry>
Error_code Cirqueue<Queue_entry>::serve_front() {
    if (isEmpty()) {
        return underflow;
    }
    front = (front + 1) % maxqueue;
    count--;
    return success;
}

template<class Queue_entry>
Error_code Cirqueue<Queue_entry>::append_rear(const Queue_entry& item) {
    if (count >= maxqueue) {
        return overflow;
    }
    entry[rear] = item;
    rear = (rear + 1) % maxqueue;
    count++;
    return success;
}

template<class Queue_entry>
Error_code Cirqueue<Queue_entry>::retrieve_front(Queue_entry& item) const {
    if (isEmpty()) {
        return underflow;
    }
    item = entry[front];
    return success;
}

template<class Queue_entry>
Error_code Cirqueue<Queue_entry>::retrieve_rear(Queue_entry& item) const {
    if (isEmpty()) {
        return underflow;
    }
    item = entry[(rear - 1 + maxqueue) % maxqueue];
    return success;
}


template<class Queue_entry>
void Cirqueue<Queue_entry>::exchage(int a, int b) {
    Queue_entry tmp;
    tmp = entry[a];
    entry[a] = entry[b];
    entry[b] = tmp;
}

template<class Queue_entry>
bool Cirqueue<Queue_entry>::full() {
    return count == maxqueue;
}

template<class Queue_entry>
int Cirqueue<Queue_entry>::size() {
    return count;
}

template<class Queue_entry>
void Cirqueue<Queue_entry>::clear() {
    count = 0;
    front = 0;
    rear = 0;
}

template<class Queue_entry>
Error_code Cirqueue<Queue_entry>::serve_and_retrieve(Queue_entry& item) {
    if (isEmpty()) {
        return underflow;
    }
    item = entry[front];
    front = (front + 1) % maxqueue;
    count--;
    return success;
}

template<class Queue_entry>
int Cirqueue<Queue_entry>::currentPosition() {
    return (front + count) % maxqueue;
}

template<class Queue_entry>
Queue_entry Cirqueue<Queue_entry>::show(int i) const {
    return entry[i];
}


#endif
//这里实现的是deque双端队列！只是改动太麻烦，就没改类名。注意 甄别。。。