#pragma once 
#include "base_queue.hpp"

class PrivateQueue: private Queue{
    private:
        float get_mean();
    public:
        PrivateQueue();

        PrivateQueue(const PrivateQueue &other);

        void enqueue(int val);

        int dequeue();

        bool is_empty();

        void dealloc_nodes();

        void operator=(const PrivateQueue &other);

        void display();

        int get_value();

        PrivateQueue operator+(const PrivateQueue &other);
};