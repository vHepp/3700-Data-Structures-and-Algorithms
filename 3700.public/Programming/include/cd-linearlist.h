//
// Created by bob on 4/8/20.
//

#ifndef LINEARLIST_H
#define LINEARLIST_H

#include <cstdint>

template <typename ListType>
struct ListNode {
    ListType
        datum;
    ListNode<ListType>
        *next,
        *prev;              // added to circular doubly linked list
};

template <typename ListType>
class CDLinearList {
public:
    CDLinearList();
    ~CDLinearList();

    uint32_t size();
    bool isEmpty();

    void clear();

    uint32_t search(const ListType &);
    ListType &operator[](int32_t);

    void map(void (*)(ListType &));

    void insert(int32_t,const ListType &);
    void remove(int32_t);

    // cursor methods
    ListType &cur();

    void first();
    void last();

    bool isFirst();
    bool isLast();

    void next();
    void previous();
private:
    ListNode<ListType>
        *head,
        *cursor;                // added for cursors
    int32_t
        count;
};

#include <cd-linearlist-implementation.h>

#endif //LINEARLIST_H
