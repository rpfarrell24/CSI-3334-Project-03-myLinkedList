/*
 * Author:                 Ryan Farrell
 * Assignment Title:       myQueue
 * Assignment Description: This program implements a queue class.
 * Due Date:               02/27/2018
 * Date Created:           02/25/2018
 * Date Last Modified:     02/25/2018
 */

#ifndef _LIST
#define _LIST

#include <memory>
#include <iostream>
#include "containerInterface.h"

using namespace std;

template <class T>
struct node
{
    T        data; //node's data element
    node<T>* next; //Pointer to next node
    node<T>* back; //Pointer to previous node

    /*
     * Description:   Constructor
     * Return:        void
     * Precondition:  Data element, e, is valid
     * Postcondition: node object created
     */
    explicit node (T e)
    {
        data = e;
        next = nullptr;
        back = nullptr;
    }
};

template <class T>
class myList : public containerInterface<T>
{
public:
    /*
     * Description:   Constructor
     * Return:        void
     * Precondition:  None
     * Postcondition: myList object created
     */
    myList ();

    /*
     * Description:   Destructor
     * Return:        void
     * Precondition:  A list exists
     * Postcondition: myList object destroyed
     */
    ~myList ();

    /*
     * Description:   Copy Constructor
     * Return:        void
     * Precondition:  myList object, that, is valid
     * Postcondition: myList object created as a copy of that
     */
    myList (const myList<T>& that);

    /*
     * Description:   Move Constructor
     * Return:        void
     * Precondition:  myList object, that, is valid
     * Postcondition: myList object created as a copy of that
     */
    myList (myList<T>&& that) noexcept;

    /*
     * Description:   Adds a new node at the head of the list
     * Return:        A reference to the calling object
     * Precondition:  A list exists and Data element, e, is valid
     * Postcondition: A node containing e is added to the head of the list
     */
    myList<T>& pushFront (T e);

    /*
     * Description:   Adds a new node at the end of the list
     * Return:        A reference to the calling object
     * Precondition:  A list exists and Data element, e, is valid
     * Postcondition: A node containing e is added to the end of the list
     */
    myList<T>& pushBack (T e);

    /*
     * Description:   Removes the node at the head of the list
     * Return:        A reference to the calling object
     * Precondition:  A list exists
     * Postcondition: node at the head of the list is removed, or if the list is
     *                  empty, a BADINDEX exception is thrown
     */
    myList<T>& popFront () throw(BADINDEX);

    /*
     * Description:   Removes the node at the end of the list
     * Return:        A reference to the calling object
     * Precondition:  A list exists
     * Postcondition: node at the end of the list is removed, but if the list is
     *                  empty, a BADINDEX exception is thrown
     */
    myList<T>& popBack () throw(BADINDEX);

    /*
     * Description:   Calculates and returns the number of nodes in the list
     * Return:        The number of nodes in the list
     * Precondition:  A list exists
     * Postcondition: The list is unchanged
     */
    int getSize () const;

    /*
     * Description:   Determines whether or not the list is full
     * Return:        True if the list is full and false otherwise
     * Precondition:  A list exists
     * Postcondition: The list is unchanged
     */
    bool full () const;

    /*
     * Description:   Determines whether or not the list is empty
     * Return:        True if the list is empty and false otherwise
     * Precondition:  A list exists
     * Postcondition: The list is unchanged
     */
    bool empty () const;

    /*
     * Description:   Returns a copy of the first element in the list
     * Return:        Copy of first element in the list
     * Precondition:  A list exists
     * Postcondition: The list is unchanged, but if the list is empty, a
     *                  BADINDEX exception is thrown
     */
    T front () const throw(BADINDEX);

    /*
     * Description:   Returns a copy of the last element in the list
     * Return:        Copy of last element in the list
     * Precondition:  A list exists
     * Postcondition: The list is unchanged, but if the list is empty, a
     *                  BADINDEX exception is thrown
     */
    T back () const throw(BADINDEX);

    /*
     * Description:   Overloaded Bracket Operator
     * Return:        reference to element at position index in the list
     * Precondition:  A list exists
     * Postcondition: The list is unchanged, but if the list is empty or index
     *                  is out of bounds, a BADINDEX exception is thrown
     */
    T& operator [] (int index) throw(BADINDEX);

    /*
     * Description:   Deletes all nodes in the list
     * Return:        void
     * Precondition:  A list exists
     * Postcondition: All nodes are deleted; head and tail pointed to nullptr
     */
    void erase ();

    /*
     * Description:   Overloaded Copy Assignment Operator
     * Return:        Reference to calling object
     * Precondition:  A list exists and that is valid
     * Postcondition: that is unchanged, and the calling list is an exact copy
     *                  of that
     */
    myList<T>& operator = (const myList<T>& that);

    /*
     * Description:   Overloaded Move Assignment Operator
     * Return:        Reference to calling object
     * Precondition:  A list exists and that is valid
     * Postcondition: that is unchanged, and the calling list is an exact copy
     *                  of that
     */
    myList<T>& operator = (myList<T>&& that) noexcept;

private:
    node<T>* head; //Pointer to first list element
    node<T>* tail; //Pointer to last list element
};

template <class T>
myList<T>:: myList ()
{
    //Initialize head and tail pointers to nullptr
    head = nullptr;
    tail = nullptr;
}

template <class T>
myList<T>:: ~myList ()
{
    //Erase the contents of the list
    this->erase();
}

template <class T>
myList<T>:: myList (const myList<T>& that)
{
    //Set this list's head and tail to nullptr
    this->head = nullptr;
    this->tail = nullptr;

    //If that is not empty, make this list a copy of that
    if(!that.empty())
    {
        //Create an initial node and a pointer for traversing this list
        auto scanThis = this->head = new node<T>(that.head->data);

        //Create a pointer for traversing that list
        auto scanThat = that.head->next;

        //Set the tail to the head
        this->tail = this->head;

        //Traverse that until its tail is reached while copying its contents
        for(int i = 1; i < that.getSize(); i++)
        {
            //Create a new node as a copy of the one in that
            scanThis->next = new node<T>(scanThat->data);

            //Set the new node's back pointer
            scanThis->next->back = scanThis;

            //Move scan pointers forward
            scanThis = scanThis->next;
            scanThat = scanThat->next;

            //Make the new node the new tail
            this->tail = scanThis;
        }

        //Set the tail's next pointer to the head
        this->tail->next = this->head;

        //Set the head's back pointer to the tail
        this->head->back = this->tail;
    }
}

template <class T>
myList<T>:: myList (myList<T>&& that) noexcept
{
    //Set this list's head and tail to nullptr
    this->head = nullptr;
    this->tail = nullptr;

    //If that is not empty, swap this list's head and tail with that list's
    if(!that.empty())
    {
        //Swap the adresses of the head and tail of each list
        swap(this->head, that.head);
        swap(this->tail, that.tail);
    }
}

template <class T>
myList<T>& myList<T>:: pushFront (T e)
{
    //If the list is empty, create the first node
    if(this->empty())
    {
        //Create the first node with e as data
        this->head = new node<T>(e);

        //Point tail to the new node
        this->tail = this->head;

        //Point head and tail's next and back to themselves
        this->head->next = this->head;
        this->head->back = this->head;
    }

    //If the list is not empty and not full, add a new node at the head
    else if(!this->full())
    {
        //Create a temporary pointer for the new node with e as data
        auto temp = new node<T>(e);

        //Point the new node's next to the current head
        temp->next = this->head;

        //Point the new node's back to tail
        temp->back = this->tail;

        //Point the current head's back to the new node
        this->head->back = temp;

        //Point the tail's next to the new node
        this->tail->next = temp;

        //Make the new node the new head
        this->head = temp;
    }

    //If the list is full, do nothing

    //Return the calling list
    return *this;
}

template <class T>
myList<T>& myList<T>:: pushBack (T e)
{
    //If the list is empty, create the first node
    if(this->empty())
    {
        //Create the first node with e as data
        this->head = new node<T>(e);

        //Point tail to the new node
        this->tail = this->head;

        //Point head and tail's next and back to themselves
        this->head->next = this->head;
        this->head->back = this->head;
    }

    //If the list is not empty and not full, add a new node at the tail
    else if(!this->full())
    {
        //Create a temporary pointer for the new node with e as data
        auto temp = new node<T>(e);

        //Point the new node's next to the head
        temp->next = this->head;

        //Point the new node's back to the current tail
        temp->back = this->tail;

        //Point head's back to the new node
        this->head->back = temp;

        //Point the current tail's next to the new node
        this->tail->next = temp;

        //Make the new node the new tail
        this->tail = temp;
    }

    //If the list is full, do nothing

    //Return the calling list
    return *this;
}

template <class T>
myList<T>& myList<T>:: popFront () throw(BADINDEX)
{
    //If the list is empty, throw a BADINDEX exception
    if(this->empty())
        throw BADINDEX();

    //If the list has one element, erase the list
    if(this->getSize() == 1)
        this->erase();

    //If the list has more than one element, simply remove it
    else
    {
        //Point tail's next to the node to become the new head
        this->tail->next = this->head->next;

        //Point the node to become the new head's back to tail
        this->head->next->back = this->tail;

        //Create a pointer for the node to be deleted
        auto toDelete = this->head;

        //Point head to the new head
        this->head = this->head->next;

        //Isolate the node to be deleted
        toDelete->next = nullptr;
        toDelete->back = nullptr;

        //Delete the node
        delete toDelete;
    }

    //Return the calling list
    return *this;
}

template <class T>
myList<T>& myList<T>:: popBack () throw(BADINDEX)
{
    //If the list is empty, throw a BADINDEX exception
    if(this->empty())
        throw BADINDEX();

    //If the list has one element, erase the list;
    if(this->getSize() == 1)
        this->erase();

    //If the list has more than one element, simply remove it
    else
    {
        //Point head's back to the node to become the new tail
        this->head->back = this->tail->back;

        //Point the node to become the new tail's next to head
        this->tail->back->next = this->head;

        //Create a pointer for the node to be deleted
        auto toDelete = this->tail;

        //Point tail to the new tail
        this->tail = this->tail->back;

        //Isolate the node to be deleted
        toDelete->next = nullptr;
        toDelete->back = nullptr;

        //Delete the node
        delete toDelete;
    }

    //Return the calling list
    return *this;
}

template <class T>
int myList<T>:: getSize () const
{
    //If the list is empty, return 0
    if(this->empty())
        return 0;

    //Create a pointer to traverse the list
    auto scan = this->head;

    //Create a size counter
    auto size = 1;

    //Traverse the list while counting nodes
    while(scan != this->tail)
    {
        //Increment size counter
        size++;

        //Move to the next node
        scan = scan->next;
    }

    //Return the size of the list
    return size;
}

template <class T>
bool myList<T>:: full () const
{
    //Attempt to allocate memory from the heap
    try {
        auto temp = new node<int>(1);
        delete temp;
    }

    //If exception thrown, return true
    catch(bad_alloc& b)
    {
        return true;
    }

    //If successful, return false
    return false;
}

template <class T>
bool myList<T>:: empty () const
{
    //If head does not point to a node, return true; otherwise, return false
    return this->head == nullptr;
}

template <class T>
T myList<T>:: front () const throw(BADINDEX)
{
    //If the list is empty, throw a BADINDEX exception
    if(this->empty())
        throw BADINDEX();

    //Return the data element in the head node
    return this->head->data;
}

template <class T>
T myList<T>:: back() const throw(BADINDEX)
{
    //If the list is empty, throw a BADINDEX exception
    if(this->empty())
        throw BADINDEX();

    //Return the data element in the tail node
    return this->tail->data;
}

template <class T>
T& myList<T>:: operator [] (int index) throw(BADINDEX)
{
    //If the list is empty, throw a BADINDEX exception
    if(this->empty())
        throw BADINDEX();

    //If index is out of bounds, throw a BADINDEX exception
    if(index < 0 || index > this->getSize() - 1)
        throw BADINDEX();

    //Create a pointer to traverse the list
    auto scan = this->head;

    //Traverse the list until the node at index is reached
    for(int i = 0; i < index; i++)
        scan = scan->next;

    //Return the data element in the node
    return scan->data;
}

template <class T>
void myList<T>:: erase ()
{
    //If the list is not empty, delete it's nodes
    if(!this->empty())
    {
        //Create pointers for nodes to be deleted and for traversing the
        //list
        auto scan = this->head;
        auto toDelete = this->head;

        while(toDelete != this->tail)
        {
            //Move scan forward
            scan = scan->next;

            //Isolate the node to be deleted
            toDelete->next = nullptr;
            toDelete->back = nullptr;

            //Delete the node
            delete toDelete;

            //Move toDelete forward to scan
            toDelete = scan;
        }

        //Isolate the tail node
        toDelete->next = nullptr;
        toDelete->back = nullptr;

        //Delete the tail node
        delete toDelete;
    }

    //Set head and tail to nullptr
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
myList<T>& myList<T>:: operator = (const myList<T>& that)
{
    //If that is the same list, simply return this list
    if(that.head == this->head)
        return *this;

    //erase this list
    this->erase();

    //If that is not empty, make this list a copy of that
    if(!that.empty())
    {
        //Create an initial node and a pointer for traversing this list
        auto scanThis = this->head = new node<T>(that.head->data);

        //Create a pointer for traversing that list
        auto scanThat = that.head->next;

        //Set the tail to the head
        this->tail = this->head;

        //Traverse that until its tail is reached while copying its contents
        for(int i = 1; i < that.getSize(); i++)
        {
            //Create a new node as a copy of the one in that
            scanThis->next = new node<T>(scanThat->data);

            //Set the new node's back pointer
            scanThis->next->back = scanThis;

            //Move scan pointers forward
            scanThis = scanThis->next;
            scanThat = scanThat->next;

            //Make the new node the new tail
            this->tail = scanThis;
        }

        //Set the tail's next pointer to the head
        this->tail->next = this->head;

        //Set the head's back pointer to the tail
        this->head->back = this->tail;
    }

    //Return the calling list
    return *this;
}

template <class T>
myList<T>& myList<T>:: operator = (myList<T>&& that) noexcept
{
    //Swap the adresses of the head and tail of each list
    swap(this->head, that.head);
    swap(this->tail, that.tail);

    //return this list
    return *this;
}

#endif //MYLINKEDLIST_MYLIST_H