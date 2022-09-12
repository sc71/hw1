#include "split.h"
#include "split.cpp"
#include <cstdlib>
#include <vector>

void printList(Node* n);
int main(){
    //make linked lists
    Node* in = (Node*)malloc(sizeof(struct Node));
    in->value = 1;
    Node* h = in;
    std::vector<int> v = {2, 3, 4, 8, 10, 27};
    for(int i=0; i<6; i++){
        Node* n = (Node*)malloc(sizeof(struct Node));
        n->value = v[i];
        h->next = n;
        h = h->next;
    }
    h->next = NULL;
    
    Node* odds = (Node*)malloc(sizeof(struct Node));
    odds = NULL;
    Node* evens = (Node*)malloc(sizeof(struct Node));
    evens = NULL;
    
    split(in, odds, evens);
    
    std::cout << "in: ";
    printList(in);
    std::cout << "odds: ";
    printList(odds);
    std::cout << "evens: ";
    printList(evens);
    return 0;
}

void printList(Node* n){
    if(n == NULL){
        std::cout << "NULL ";
        return;
    }
    while(n != NULL){
        std::cout << n->value << " ";
        n = n->next;
    }
}
