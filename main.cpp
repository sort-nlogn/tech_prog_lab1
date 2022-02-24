#include <iostream>
#include "private_queue.hpp"
#include "public_queue.hpp"
#include "protected_queue.hpp"

using namespace std;

int get_int(){
    int ans;
    printf("Value to enqueue: ");
    scanf("%d", &ans);
    return ans;
}

char select_type(){
    printf("Select queue type\n1 --- public\n2 --- private\n3 --- pritected\n");
    printf(">>");
    return getchar();
}

void display_help(){
    printf("1 --- Push element\n2 --- Pop element\n3 --- Display queue\n\
4 --- Display last element less than mean\n\
5 --- Copy queue\n\
6 --- Merge copied queue with current queue\n\
7 --- Exit programm\n\
8 --- Display help\n");
}

template<typename T>
char execute_commands(){
    T q1, q2;
    display_help();
    while(1){
        char c = getchar();
        if(c == '\n')
            printf(">>");
        if(c == '1'){
            q1.enqueue(get_int());
        }else if(c == '2'){
            printf("Dequeued value: %d\n",  q1.dequeue());
        }else if(c == '3'){
            q1.display();
            printf("\n");
        }else if(c == '4'){
            printf("%d \n", q1.get_value());
        }else if(c == '5'){
            q2 = q1;
        }else if(c == '6'){
            q1 = q1 + q2;
        }else if(c == '7'){
            q1.dealloc_nodes();
            q2.dealloc_nodes();
            return 0;
        }else if(c == '8'){
            display_help();
        }
    }
    return 0;
}

int main(){
    char type = select_type();
    while(type){
        if(type == '1')
            type = execute_commands<PublicQueue>();
        else if(type == '2')
            type = execute_commands<PrivateQueue>();
        else if(type == '3')
            type = execute_commands<ProtectedQueue>();
        else{
            printf("No such type. Try again\n");
            getchar();
            type = select_type();
        }
    }
    return 0;
}