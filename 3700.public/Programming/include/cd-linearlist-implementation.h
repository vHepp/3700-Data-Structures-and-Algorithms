//
// Created by bob on 4/3/20.
//

#ifndef LINEARLIST_CD_LINEARLIST_IMPLEMENTATION_H
#define LINEARLIST_CD_LINEARLIST_IMPLEMENTATION_H

#include <cd-linearlist.h>
#include <stdexcept>

//=============================================================================
//----------------------------- common operations -----------------------------
//=============================================================================

//=============================================================================
// CDLinearList<ListType>::CDLinearList()
//  constructor
//

template <typename ListType>
CDLinearList<ListType>::CDLinearList() {

    head = nullptr;     // as discussed in the slides
    cursor = nullptr;   //
    count = 0;
}

//=============================================================================
// CDLinearList<ListType>::~CDLinearList()
//  destructor
//

template <typename ListType>
CDLinearList<ListType>::~CDLinearList() { clear(); }

//=============================================================================
// uint32_t CDLinearList<ListType>::size()
//  return size of list (number of nodes)
//

template <typename ListType>
uint32_t CDLinearList<ListType>::size() { return count; }

//=============================================================================
// bool CDLinearList<ListType>::isEmpty()
//  return true if list is empty, false otherwise
//

template <typename ListType>
bool CDLinearList<ListType>::isEmpty() { return count == 0; }

//=============================================================================
// void clear()
//  remove all nodes from list, reset head and count
//
// Notes:
// - uses a counted loop instead of looking for the nullptr. that way, if this
//   is changed to a circular list (which has no null pointers), the code won't
//   be affected.
//

template <typename ListType>
void CDLinearList<ListType>::clear() {
    ListNode<ListType>
        *tmp;

    for (int i=0;i<count;i++) {
        tmp = head->next;           // remember second node in the list
        delete head;                // remove the first node
        head = tmp;                 // second node moves to front
    }

    head = nullptr;                 // all nodes removed, reset list
    cursor = nullptr;
    count = 0;
}

//=============================================================================
//------------------------- list-specific operations --------------------------
//=============================================================================

//=============================================================================
// uint32_t CDLinearList<ListType>::search(const ListType &key)
//  search for key in the list
//
// Parameter:
//  key - what to look for
//
// Returns:
//  - index of first occurrence if key exists in the list
//  - throws a domain_error exception if key is not in the list
//

template <typename ListType>
uint32_t CDLinearList<ListType>::search(const ListType &key) {
    ListNode<ListType>
        *tmp = head;                // start at head of list

    for (int i=0;i<count;i++) {     // step through the list
        if (key == tmp->datum)      // if key found, stop and return index
            return i;
        tmp = tmp->next;            // walk to next node
    }

    // if we get here, the key was not in the list
    throw std::domain_error("key not found");
}

//=============================================================================
// ListType &CDLinearList<ListType>::operator[](int32_t pos)
//  return reference to element at given position, works like array []
//
// Parameter:
//  pos - position in the list to access
//
// Returns:
//  - reference to specified element in the list
//  - throws a domain_error exception if pos is invalid (< -count or >= count)
//

template <typename ListType>
ListType &CDLinearList<ListType>::operator[](int32_t pos) {
    ListNode<ListType>
        *tmp = head;                // start at head of list

    if (pos < -count || pos >= count)
        throw std::domain_error("Invalid index");

    // now with negative indexing!
    if (pos < 0)
        for (int i=0;i>pos;i--)         // step through the list
            tmp = tmp->prev;            // walk to previous node
    else
        for (int i=0;i<pos;i++)         // step through the list
            tmp = tmp->next;            // walk to next node

    return tmp->datum;              // return reference;
}

//=============================================================================
// void CDLinearList<ListType>::map(void (*fp)(ListType &))
//  apply given function to each element in the list
//
// Parameter:
//  fp - pointer to function to call
//

template <typename ListType>
void CDLinearList<ListType>::map(void (*fp)(ListType &)) {
    ListNode<ListType>
        *tmp = head;                // start at head of list

    for (int i=0;i<count;i++) {     // step through the list
        (*fp)(tmp->datum);          // call the function, pass the datum
        tmp = tmp->next;            // walk to next node
    }
}

//=============================================================================
// void CDLinearList<ListType>::insert(uint32_t pos,const ListType &d)
//  insert element into the list
//
// Parameters:
//  pos - position of new element; subsequent elements shifted
//    d - value to be inserted
//
// Notes:
//  - throws a domain_error exception if pos is invalid (< -count or > count)
//  - predecessor no longer needs to be a pointer to a pointer.
//

template <typename ListType>
void CDLinearList<ListType>::insert(int32_t pos, const ListType &d) {
    ListNode<ListType>
        *ptr,
        *pred,
        *succ;

    // step 0: validate pos
    if (pos < -count || pos > count)
        throw std::domain_error("Invalid index");

    // step 1: allocate new node and place datum
    ptr = new ListNode<ListType>;
    ptr->datum = d;
    ptr->next = ptr->prev = ptr;        // point node to itself

    // step 1.5: special case - inserting into empty list
    if (count == 0) {
        head = ptr;                         // point to the "list"
        count = 1;
        return;                             // bail here
    }

    // step 2: find the predecessor and successor... pred first
    pred = head->prev;
    if (pos < 0)
        for (int i=-1;i>pos;i--)
            pred = pred->prev;
    else
        for (int i=0;i<pos;i++)
            pred = pred->next;
    succ = pred->next;

    // step 3: copy predecessor's next pointer to new node... successor's too
    ptr->next = pred->next;
    ptr->prev = succ->prev;

    // step 4: predecessor and successor point to new node
    pred->next = succ->prev = ptr;

    // step 4.5: a nuance... if inserting in position 0, update the head
    if (pos == 0)
        head = ptr;

    // step 5: update count
    count++;
}

//=============================================================================
// void CDLinearList<ListType>::remove(uint32_t pos)
//  remove element from the list
//
// Parameter:
//  pos - position of element to be removed; subsequent elements shifted
//
// Notes:
//  - throws a domain_error exception if pos is invalid (<= -count or >= count)
//  - predecessor no longer needs to be a pointer to a pointer.
//

template <typename ListType>
void CDLinearList<ListType>::remove(int32_t pos) {
    ListNode<ListType>
        *ptr,
        *pred,
        *succ;

    // step 0: validate pos
    if (pos <= -count || pos >= count)
        throw std::domain_error("Invalid index");

    // step 0.5: special case, removing last node from the list
    if (count == 1) {
        delete head;
        head = cursor = nullptr;
        count = 0;
        return;
    }

    // step 1: find the node to be deleted
    ptr = head;
    if (pos < 0)
        for (int i=0;i>pos;i--)
            ptr = ptr->prev;
    else
        for (int i=0;i<pos;i++)
            ptr = ptr->next;

    // step 2.5: nuances... if deleting pos 0, update head
    if (pos == 0)
        head = head->next;

    // step 2.6: other nuance... if deleting the cursor node, clear the cursor
    if (ptr == cursor)
        cursor = nullptr;

    // step 2: get the predecessor and successor... which might be the same node
    pred = ptr->prev;
    succ = ptr->next;

    // step 3: copy ntbd's pointer to predecessor... pointing around ntbd
    pred->next = succ;
    succ->prev = pred;

    // step 4: delete the node
    delete ptr;

    // step 5: update count
    count--;
}

//=============================================================================
//-------------------------- cursor-specific methods --------------------------
//=============================================================================

template <typename ListType>
ListType &CDLinearList<ListType>::cur() {

    if (cursor == nullptr)
        throw std::domain_error("Cursor not set");

    return cursor->datum;
}

template <typename ListType>
void CDLinearList<ListType>::first() {

    if (count == 0)
        throw std::out_of_range("List is empty");

    cursor = head;
}

template <typename ListType>
void CDLinearList<ListType>::last() {

    if (count == 0)
        throw std::out_of_range("List is empty");

    cursor = head->prev;
}

template <typename ListType>
bool CDLinearList<ListType>::isFirst() {

    if (count == 0)
        return false;

    return cursor == head;
}

template <typename ListType>
bool CDLinearList<ListType>::isLast() {

    if (count == 0)
        return false;

    return cursor == head->prev;
}

template <typename ListType>
void CDLinearList<ListType>::next() {

    if (cursor == nullptr)
        throw std::domain_error("Cursor not set");

    cursor = cursor->next;
}

template <typename ListType>
void CDLinearList<ListType>::previous() {

    if (cursor == nullptr)
        throw std::domain_error("Cursor not set");

    cursor = cursor->prev;
}

#endif //CD_LINEARLIST_IMPLEMENTATION_H
