/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
using namespace std;

void printList(ULListStr* list, int start, int end);
int main(int argc, char* argv[])
{
    //make a linked list of increasing values
    ULListStr* list = new ULListStr();
    list->push_back("three");
    list->push_back("four");
    list->push_front("two");
    //mistake to be fixed (one not seven)
    list->push_front("seven");
    //mistake to be fixed (pop this)
    list->push_front("eight");
    cout<< "get(3)" << list->get(3) << endl;
    list->push_back("five");
    list->push_back("six");
    list->push_back("seven");
    list->push_back("eight");
    list->push_back("nine");
    list->push_back("ten");
    list->push_back("eleven");
    list->push_back("twelve");
    list->push_back("thirteen");
    
    //printList(list, 0, 22);
    
    //fix mistakes from earlier
    list->pop_front();
    list->set((size_t) 8, "one");
    
    //printList(list, 0, 22);
    
    //test get(size_t loc
    cout << "list->get(3) = " << list->get(3) << endl;
    cout << "list->get(11) = " << list->get(11) << endl;
    cout << "list->get(size-1) = " << list->get(list->size() - 1) << endl;
    cout << "list.get(0) = " << list->get(0) << endl;



    //test push_front
    cout << "list size: " << list->size() << endl;
    cout << "list back: " << list->back() << endl;
    cout << "list front: " << list->front() << endl;
    list->push_front("forty");
    cout << "list.get(0) = " << list->get(0) << endl;
    cout << "list front: " << list->front() << endl;

    cout << "list size: " << list->size() << endl;
    cout << "list back: " << list->back() << endl;
    cout << "list front: " << list->front() << endl;
    list->push_back("forty");
    cout << "list.get(arrsize) = " << list->get(14) << endl;
    cout << "list front: " << list->front() << endl;
    //test set
    //cout << "list.get(3) = " << list->get(3) << endl;
    //list->set(3, "thirty");
    //cout << "after list.set, list->get(3) = " << list->get(3) << endl;
    
    //pop front and back until two items are gone
    list->pop_front();
    list->pop_front();
    list->pop_back();
    
    //printList(list, 0, 10);
    
    //clear
    list->clear();
    cout << "size: " << list->size() << endl;
    
    delete list;
    return 0;
}

/*void printList(ULListStr* list, int start, int end){
    cout << "size: " << list->size() << endl;
    cout << "front: " << list->front() << endl;
    cout << "back: " << list->back() << endl;
    if(end > 0){
        cout<< "whole list: ";
        for(int i=start; i<end; i++){
            cout << list->get(i) << ", ";
        }
        cout << endl;
    }
}*/
