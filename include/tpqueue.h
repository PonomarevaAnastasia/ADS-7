// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TpQueue {
 private:
    struct Item {
        T value;
        Item* next;
    };
    Item* head;
    Item* create(const T& value) {
        Item* temp = new Item;
        temp->value = value;
        temp->next = nullptr;
        return temp;
    }

 public:
    TPQueue() :head(nullptr) {}
    void push(const T&);
    T pop();
};
template<typename T>
T TPQueue<T>::pop() {
    if (head == nullptr) {
        throw std::string("Empty!");
    } else {
        T n  = head->value;
        Item* tmp = head->next;
        delete head;
        head = tmp;
        return n;
    }
}
template<typename T>
void TPQueue<T>::push(const T& n) {
    if (head == nullptr) {
        head = create(n);
    } else {
        Item* obj = head;
        int i = 0;
        while (obj) {
            if (obj->value.prior < n.prior) {
                break;
            }
            obj = obj->next;
            i++;
        }
        if (i == 0) {
            Item* tmp = new Item;
            tmp->next = head;
            tmp->value = n;
            head = tmp;
        } else {
            obj = head;
            for (int k = 1; k < i; k++) {
                obj = obj->next;
            }
            Item* tmp = new Item;
            tmp->next = obj->next;
            tmp->value = n;
            obj->next = tmp;
        }
    }
}

struct sum {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
