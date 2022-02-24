#include "base_queue.hpp"
#include <stdexcept>
#include <iostream>

Node::Node(int val): next(nullptr), data(val){
}

Queue::Queue(): tail(nullptr), head(nullptr){
}

Queue::Queue(const Queue &other): tail(nullptr), head(nullptr){
    this->operator=(other);
}

void Queue::enqueue(int val){
    Node *n = new Node(val);
    if(tail == nullptr){
        head = n;
        tail = n;
    }else{
        tail->next = n;
        tail = n;
    }
}

int Queue::dequeue(){
    if(head == nullptr)
        throw std::runtime_error("Empty queue!");

    int ans = head->data;
    Node *new_head = head->next;
    delete head;
    head = new_head;
    if(new_head == nullptr)
        tail = nullptr; 
    return ans;
}

void Queue::dealloc_nodes(){
    Node *curr = head, *nxt = nullptr;
    while(curr != nullptr){
        nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    head = nullptr, tail = nullptr;
}

void Queue::operator=(const Queue &other){
    dealloc_nodes();
    Node *curr = other.head;
    while(curr != nullptr){
        this->enqueue(curr->data);
        curr = curr->next;
    }
}

Queue Queue::operator+(const Queue &other){
    Queue res;
    res = *this;
    Node *curr = other.head;
    while(curr != nullptr){
        res.enqueue(curr->data);
        curr = curr->next;
    }
    return res;
}

bool Queue::is_empty(){
    return tail == nullptr;
}

Node *Queue::get_head() const{
    return head;
}