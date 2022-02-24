#include "public_queue.hpp"
#include <iostream>

PublicQueue::PublicQueue(): Queue(){

}

PublicQueue::PublicQueue(const PublicQueue &other): Queue(){
    this->operator=(other);
}

void PublicQueue::operator=(const PublicQueue &other){
    dealloc_nodes();
    Node *curr = other.get_head();
    while(curr != nullptr){
        this->enqueue(curr->data);
        curr = curr->next;
    }
}

PublicQueue PublicQueue::operator+(const PublicQueue &other){
    PublicQueue res;
    res = *this;
    Node *curr = other.get_head();
    while(curr != nullptr){
        res.enqueue(curr->data);
        curr = curr->next;
    }
    return res;
}

void PublicQueue::display(){
    Node *h = this->get_head();
    printf("head->");
    while(h != nullptr){
        printf("%d->", h->data);
        h = h->next;
    }
    printf("tail");
}

float PublicQueue::get_mean(){
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

int PublicQueue::get_value(){
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