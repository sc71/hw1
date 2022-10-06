#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
    //if list does not exist
    if(tail_ == NULL){
        Item* item = new Item();
        item->val[0] = val;
        item->first = 0;
        item->last = 1;
        //set tail to new list
        tail_ = item;
        head_ = item;
    }
    //if list is full
    else if(tail_->last >= ARRSIZE){
        //make a new item
        Item* item = new Item();
        item->val[0] = val;
        item->first = 0;
        item->last = 1;
        //set tail to new list
        item->prev = tail_;
        tail_->next = item;
        tail_ = item;
    }
    //if list is not full
    else{
        tail_->val[tail_->last] = val;
        tail_->last += 1;
    }
    //increment size
    size_++;
}

void ULListStr::pop_back(){
    //if last value is only one in tail_ item, remove that item
    if(tail_->last == 1){
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = NULL;
        tail_->last = ARRSIZE;
        delete temp;
    }
    //if last value is not only one in tail_ item
    else{
        //tail_->val[(int)(tail_->last)-1] = NULL;
        tail_->last -= 1;
    }
    size_--;
}

void ULListStr::push_front(const std::string& val){
    //if list doesn't exist yet
    if(head_ == NULL){
        Item* item = new Item();
        item->val[ARRSIZE-1] = val;
        item->first = ARRSIZE-1;
        item->last = ARRSIZE;
        //set tail to new list
        tail_ = item;
        head_ = item;
    }
    //if list is full
    else if(head_->first == 0){
        //make a new item
        Item* item = new Item();
        item->val[ARRSIZE-1] = val;
        item->first = ARRSIZE-1;
        item->last = ARRSIZE;
        //set head to new list
        item->next = head_;
        head_->prev = item;
        head_ = item;
    }
    //if list is not full
    else{
        int pos = (int)head_->first - 1;
        head_->val[pos] = val;
        head_->first -= 1;
    }
    size_++;
}

void ULListStr::pop_front(){
    //if first is only value left in head_
    if(head_->first == ARRSIZE-1){
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = NULL;
        head_->first = 0;
        delete temp;
    }
    //if first value is not only one in head_
    else{
        head_->first += 1;
    }
    size_--;
}

std::string const & ULListStr::back() const{
    if (tail_ == NULL){
        return NULL;
    }
    else {return tail_->val[tail_->last - 1];}
}

std::string const & ULListStr::front() const{
    if(head_ == NULL){
        return NULL;
    }
    else {return head_->val[head_->first];}
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
    std::string* ptr = NULL;
    int itemNum = 0;
    int valNum = 0;
    //if loc is out of array
    if((int)loc >= size_ || (int)loc < 0){
        return ptr;
    }
    //if we are getting a value from head
    if ((int) loc <= (head_->last - head_->first)){
        valNum = head_->first + (int) loc;
        ptr = &head_->val[valNum];
        return ptr;
    }
    //otherwise, we need to search other items in the list
    else {
        //if head is not a full array of 10, we need to shift our search
        //valNum = the value we are looking for minus the indices in head_
        valNum = (int)loc - (head_->last - head_->first);
        //itemNum = number of items we have to traverse
        itemNum = valNum/10;
        //valNum = index in the itemNum-th array that our val is in
        valNum %= 10;
        Item* item = head_->next;
        for(int i=0; i<itemNum; i++){
            item = item->next;
        }
        ptr = &item->val[valNum];
        return ptr;
    }
}
