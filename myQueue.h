/*
 * Author:                 Ryan Farrell
 * Assignment Title:       myQueue
 * Assignment Description: This program implements a queue class.
 * Due Date:               02/27/2018
 * Date Created:           02/25/2018
 * Date Last Modified:     02/25/2018
 */

#include "myList.h"

template <class T, class C = myList<T> >
class myQueue
{
public:
    /*
     * Description:   constructor
     * Return:        void
     * Precondition:  none
     * Postcondition: myQueue object created
     */
    myQueue () = default;

    /*
     * Description:   destructor
     * Return:        void
     * Precondition:  myQueue object exists
     * Postcondition: myQueue object destroyed
     */
    ~myQueue () = default;

    /*
     * Description:   copy constructor
     * Return:        void
     * Precondition:  that queue exists
     * Postcondition: myQueue object created as a copy of that
     */
    myQueue (const myQueue& that) = default;

    /*
     * Description:   move constructor
     * Return:        void
     * Precondition:  that queue exists
     * Postcondition: myQueue object created with that's data
     */
    myQueue (myQueue&& that) noexcept = default;

    /*
     * Description:   overloaded copy assignment operator
     * Return:        reference to this queue
     * Precondition:  this queue and that queue exist
     * Postcondition: that queue's data is copied into this queue
     */
    myQueue<T,C>& operator = (const myQueue& that) = default;

    /*
     * Description:   overloaded move assignment operator
     * Return:        reference to this queue
     * Precondition:  this queue and that queue exist
     * Postcondition: this queue assumes that queue's data
     */
    myQueue<T,C>& operator = (myQueue&& that) noexcept = default;

    /*
     * Description:   determines and reports whether or not this queue is empty
     * Return:        True is empty, false otherwise
     * Precondition:  this queue exists
     * Postcondition: this queue is unchanged
     */
    bool IsEmpty ();

    /*
     * Description:   returns a copy of the first element in the queue
     * Return:        copy of first element in the queue
     * Precondition:  this queue exists and is not empty
     * Postcondition: this queue is unchanged
     */
    T First ();

    /*
     * Description:   adds an element to the rear of the queue
     * Return:        reference to this queue
     * Precondition:  this queue exists and is not full
     * Postcondition: an element is added to the rear of the queue
     */
    myQueue<T,C>& Enqueue (T e);

    /*
     * Description:   removes the element at the head of the queue
     * Return:        reference to this queue
     * Precondition:  this queue exists and is not empty
     * Postcondition: element removed from the front of the queue
     */
    myQueue<T,C>& Dequeue ();

private:
    C container;
};

template <class T, class C>
bool myQueue<T, C>:: IsEmpty ()
{
    //Return whether or not the container is empty
    return container.empty();
}

template <class T, class C>
T myQueue<T, C>::First()
{
    //Return a copy of the element at the front of the container
    return container.front();
}

template <class T, class C>
myQueue<T,C>& myQueue<T, C>:: Enqueue (const T e)
{
    //Add the element to the rear of the container
    container.pushBack(e);

    //Return this queue
    return *this;
}

template <class T, class C>
myQueue<T,C>& myQueue<T, C>:: Dequeue ()
{
    //Remove the element at the rear of the container
    container.popFront();

    //Return this queue
    return *this;
}