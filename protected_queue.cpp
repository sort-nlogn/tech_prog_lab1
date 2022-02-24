#include "protected_queue.hpp"
#include <iostream>

ProtectedQueue::ProtectedQueue(): Queue(){
}

ProtectedQueue::ProtectedQueue(const ProtectedQueue &other): Queue(){
    this->operator=(other);
}

int ProtectedQueue::dequeue(){
    return Queue::dequeue();
}

void ProtectedQueue::enqueue(int val){
    Queue::enqueue(val);
}

void ProtectedQueue::dealloc_nodes(){
    Queue::dealloc_nodes();
}

void ProtectedQueue::operator=(const ProtectedQueue &other){
    dealloc_nodes();
    Node *curr = other.get_head();
    while(curr != nullptr){
        this->enqueue(curr->data);
        curr = curr->next;
    }
}

ProtectedQueue ProtectedQueue::operator+(const ProtectedQueue &other){
    ProtectedQueue res;
    res = *this;
    Node *curr = other.get_head();
    while(curr != nullptr){
        res.enqueue(curr->data);
        curr = curr->next;
    }
    return res;
}

bool ProtectedQueue::is_empty(){
    return Queue::is_empty();
}

void ProtectedQueue::display(){
    Node *h = Queue::get_head();
    printf("head->");
    while(h != nullptr){
        printf("%d->", h->data);
        h = h->next;
    }
    printf("tail");
}

float ProtectedQueue::get_mean(){
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

int ProtectedQueue::get_value(){
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