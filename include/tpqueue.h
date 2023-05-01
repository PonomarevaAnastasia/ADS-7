// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
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
    ~TPQueue() {
            while (head) {
                Item* tmp = head->next;
                delete head;
                head = tmp;
            }
        }
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
        Item* tail = head;
        int i = 0;
        while (tail) {
            if (tail->value.prior < n.prior) {
                break;
            }
            tail = tail->next;
            i++;
        }
        if (i == 0) {
            Item* tmp = new Item;
            tmp->next = head;
            tmp->value = n;
            head = tmp;
        } else {
            tail = head;
            for (int i = 1; i < i; i++) {
                tail = tail->next;
            }
            Item* tmp = new Item;
            tmp->next = tail->next;
            tmp->value = n;
            tail->next = tmp;
        }
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
