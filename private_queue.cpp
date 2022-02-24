#include "private_queue.hpp"
#include <iostream>
#include <limits>

PrivateQueue::PrivateQueue(): Queue(){
}

PrivateQueue::PrivateQueue(const PrivateQueue &other): Queue(){
    this->operator=(other);
}

int PrivateQueue::dequeue(){
    return Queue::dequeue();
}

void PrivateQueue::enqueue(int val){
    Queue::enqueue(val);
}

void PrivateQueue::dealloc_nodes(){
    Queue::dealloc_nodes();
}

void PrivateQueue::operator=(const PrivateQueue &other){
    dealloc_nodes();
    Node *curr = other.get_head();
    while(curr != nullptr){
        this->enqueue(curr->data);
        curr = curr->next;
    }
}

PrivateQueue PrivateQueue::operator+(const PrivateQueue &other){
    PrivateQueue res;
    res = *this;
    Node *curr = other.get_head();
    while(curr != nullptr){
        res.enqueue(curr->data);
        curr = curr->next;
    }
    return res;
}

bool PrivateQueue::is_empty(){
    return Queue::is_empty();
}

void PrivateQueue::display(){
    Node *h = Queue::get_head();
    printf("head->");
    while(h != nullptr){
        printf("%d->", h->data);
        h = h->next;
    }
    printf("tail");
}

float PrivateQueue::get_mean(){
    Node *curr = this->get_head();
    float mean = 0.0;
    int cnt = 0;
    while(curr != nullptr){
        mean += (float)(curr->data);
        cnt ++;
        curr = curr->next;
    }
    return mean / (float)cnt;
}

int PrivateQueue::get_value(){
    float mean = get_mean();
    Node *curr = this->get_head();
    int ans = INT_MAX; 
    while(curr != nullptr){
        if((float)curr->data <= mean)
            ans = curr->data;
        curr = curr->next;
    }
    return ans;
}