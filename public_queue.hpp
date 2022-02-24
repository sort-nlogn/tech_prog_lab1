#pragma once 
#include "base_queue.hpp"

class PublicQueue: public Queue{
    private:
        float get_mean();
    public:
        PublicQueue();

        PublicQueue(const PublicQueue &other);

        void operator=(const PublicQueue &other);

        int get_value();

        void display();

        PublicQueue operator+(const PublicQueue &other);
};
