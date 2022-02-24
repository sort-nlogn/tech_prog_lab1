#pragma once 
#include "base_queue.hpp"

class ProtectedQueue: protected Queue{
    private:
        float get_mean();
    public:
        ProtectedQueue();

        ProtectedQueue(const ProtectedQueue &other);

        void enqueue(int val);

        int dequeue();

        bool is_empty();

        void dealloc_nodes();

        void operator=(const ProtectedQueue &other);

        int get_value();

        void display();

        ProtectedQueue operator+(const ProtectedQueue &other);
};