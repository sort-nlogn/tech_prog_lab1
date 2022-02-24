#pragma once 

struct Node{
    struct Node *next;
    int data;
    Node(int val);
};

class Queue{
    private:
        Node *tail, *head;

    public:
        Queue();

        Queue(const Queue &other);

        void enqueue(int val);

        int dequeue();

        void dealloc_nodes();

        void operator=(const Queue &other);

        bool is_empty();

        Queue operator+(const Queue &other);

        Node *get_head() const;
};