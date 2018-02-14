/*
 * Author:                 Ryan Farrell
 * Assignment Title:       myLinkedList
 * Assignment Description: This program implements a linked list class.
 * Due Date:               2018/02/13
 * Date Created:           2018/02/09
 * Date Last Modified:     2018/02/12
 */

#include "myList.h"
#include <string>


template <class T>

/*
 * Description:   Prints the data elements in a list
 * Return:        void
 * Precondition:  name, list, and out are valid
 * Postcondition: The data elements of the list are printed to out
 */
void printList(string name, myList<T>& list, ostream& out = cout);

/*
 * Description:   Prints a horizontal rule
 * Return:        void
 * Precondition:  c, length, and out are valid
 * Postcondition: A horizontal rule is printed to out
 */
void printRule(ostream& out = cout, char c = '*', int length = 80);

int main()
{
    //Print beginning message
    cout << "Testing myList class methods..." << endl;
    printRule();

    //Test constructor
    cout << "Testing constructor..." << endl;

    myList<int> list1; //myList object for testing class methods

    printList("list1", list1);
    printRule();

    //Test copy constructor on an empty list
    cout << "Testing copy constructor with an empty list..." << endl;

    myList<int> list2(list1); //myList object for testing class methods

    printList("list1", list1);
    printList("list2", list2);
    printRule();

    //Test copy constructor on a list with one element
    cout << "Testing copy constructor on a list with one element..." << endl;

    list1.pushFront(5);

    myList<int> list3(list1); //myList object for testing class methods

    printList("list1", list1);
    printList("list3", list3);
    printRule();

    //Test copy constructor on a list with multiple elements
    cout << "Testing copy constructor on a list with multiple elements..."
         << endl;

    list1.pushBack(6);
    list1.pushFront(4);

    myList<int> list4(list1); //myList object for testing class methods

    printList("list1", list1);
    printList("list4", list4);
    printRule();

    //Test pushFront on an empty list
    cout << "Testing pushFront method on an empty list..." << endl;
    printList("list2", list2);
    cout << "Pushing 1..." << endl;

    list2.pushFront(1);

    printList("list2", list2);
    printRule();

    //Test pushFront on a list with one element
    cout << "Testing pushFront method on a list with one element..." << endl;
    printList("list2", list2);
    cout << "Pushing 2..." << endl;

    list2.pushFront(2);

    printList("list2", list2);
    printRule();

    //Test pushFront on a list with multiple elements
    cout << "Testing pushFront method on a list with multiple elements..."
         << endl;
    printList("list2", list2);
    cout << "Pushing 3..." << endl;

    list2.pushFront(3);

    printList("list2", list2);
    printRule();

    //Test popFront on a list with multiple elements
    cout << "Testing popFront on a list with multiple elements..." << endl;
    printList("list2", list2);

    try {
        list2.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list2", list2);

    try {
        list2.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list2", list2);
    printRule();

    //Test popFront on a list with one element
    cout << "Testing popFront on a list with one element..." << endl;
    printList("list2", list2);

    try {
        list2.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list2", list2);
    printRule();

    //Test popFront on an empty list
    cout << "Testing popFront on an empty list, expecting error..." << endl;
    printList("list2", list2);

    try {
        list2.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list2", list2);
    printRule();

    //Test pushBack on an empty list
    cout << "Testing pushBack method on an empty list..." << endl;
    printList("list2", list2);
    cout << "Pushing 1..." << endl;

    list2.pushBack(1);

    printList("list2", list2);
    printRule();

    //Test pushBack on a list with one element
    cout << "Testing pushBack method on a list with one element..." << endl;
    printList("list2", list2);
    cout << "Pushing 2..." << endl;

    list2.pushBack(2);

    printList("list2", list2);
    printRule();

    //Test pushBack on a list with multiple elements
    cout << "Testing pushBack method on a list with multiple elements..."
         << endl;
    printList("list2", list2);
    cout << "Pushing 3..." << endl;

    list2.pushBack(3);

    printList("list2", list2);
    printRule();

    //Test popBack on a list with multiple elements
    cout << "Testing popBack on a list with multiple elements..." << endl;
    printList("list2", list2);

    try {
        list2.popBack();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list2", list2);

    try {
        list2.popBack();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list2", list2);
    printRule();

    //Test popBack on a list with one element
    cout << "Testing popBack on a list with one element..." << endl;
    printList("list2", list2);

    try {
        list2.popBack();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list2", list2);
    printRule();

    //Test popBack on an empty list
    cout << "Testing popBack on an empty list, expecting error..." << endl;
    printList("list2", list2);

    try {
        list2.popBack();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list2", list2);
    printRule();

    //Test several alternating pushFront and pushBack calls
    cout << "Testing several alternating pushFront and pushBack calls..."
         << endl;
    printList("list2", list2);
    cout << "Pushing 1, 2, and 3 to the front and 4, 5, and 6 to the back,"
         << " alternating between calls to pushFront and pushBack..." << endl
         << "Expected result is 3, 2, 1, 4, 5, 6." << endl;

    list2.pushFront(1);
    list2.pushBack(4);
    list2.pushFront(2);
    list2.pushBack(5);
    list2.pushFront(3);
    list2.pushBack(6);

    printList("list2", list2);
    printRule();

    //Several alternating popFronts and popBacks
    cout << "Testing several alternating popFront and popBack calls..."
         << endl;
    printList("list2", list2);

    try {
        list2.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    try {
        list2.popBack();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    try {
        list2.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    try {
        list2.popBack();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    try {
        list2.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    try {
        list2.popBack();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list2", list2);
    printRule();

    //Test getSize on a list with multiple elements
    cout << "Testing getSize method on a list with multiple elements" << endl;
    printList("list1", list1);
    cout << "The number of elements in list1 is " << list1.getSize() << "."
         << endl;
    printRule();

    //Test getSize on a list with one element
    cout << "Testing getSize method on a list with one element" << endl;

    try {
        list1.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    try {
        list1.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list1", list1);
    cout << "The number of elements in list1 is " << list1.getSize() << "."
         << endl;
    printRule();

    //Test getSize on an empty list
    cout << "Testing getSize method on an empty list" << endl;

    try {
        list1.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list1", list1);
    cout << "The number of elements in list1 is " << list1.getSize() << "."
         << endl;
    printRule();

    //Test full on a list that is not empty or full
    cout << "Testing full method on a list with multiple elements..."
         << endl;

    for(int i = 0; i < 17; i++)
    {
        list4.pushFront(i);
    }

    try {
        list4.popFront();
    }
    catch(BADINDEX b){
        cout << "Error: attempted to remove a value from an empty list" << endl;
    }

    printList("list4", list4);
    cout << "The number of elements in list4 is " << list4.getSize() << "."
         << endl;
    cout << "list4 is..." << endl;

    if(list4.full())
        cout << "full" << endl;
    else
        cout << "not full" << endl;

    printRule();

    //Test full on an empty list
    cout << "Testing full method on an empty list..."
         << endl;
    printList("list1", list2);
    cout << "The number of elements in list1 is " << list1.getSize() << "."
         << endl;
    cout << "list1 is..." << endl;

    if(list4.full())
        cout << "full" << endl;
    else
        cout << "not full" << endl;

    printRule();

    //Test empty on a list with multiple items
    cout << "Testing empty method on a list with multiple items..." << endl;
    printList("list4", list4);
    cout << "The number of elements in list4 is " << list4.getSize() << "."
         << endl;
    cout << "list4 is..." << endl;

    if(list4.empty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;

    printRule();

    //Test empty on a list with one item
    cout << "Testing empty method on a list with one item..." << endl;
    printList("list3", list3);
    cout << "The number of elements in list3 is " << list3.getSize() << "."
         << endl;
    cout << "list3 is..." << endl;

    if(list3.empty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;

    printRule();

    //Test empty on an empty list
    cout << "Testing empty method on an empty list..." << endl;
    printList("list1", list1);
    cout << "The number of elements in list1 is " << list1.getSize() << "."
         << endl;
    cout << "list1 is..." << endl;

    if(list1.empty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;

    printRule();

    //Test front and back on a list with multiple elements
    cout << "Testing front and back on a list with multiple elements..."
         << endl;
    printList("list4", list4);
    cout << "The front element of list4 is..." << endl;

    try{
        cout << list4.front();
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from an empty list";
    }

    cout << endl;
    cout << "The back element of list4 is..." << endl;

    try{
        cout << list4.back();
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from an empty list";
    }

    cout << endl;
    printRule();

    //Test front and back on a list with one element
    cout << "Testing front and back on a list with one element..." << endl;
    printList("list3", list3);
    cout << "The front element of list3 is..." << endl;

    try{
        cout << list3.front();
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from an empty list";
    }

    cout << endl;
    cout << "The back element of list3 is..." << endl;

    try{
        cout << list3.back();
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from an empty list";
    }

    cout << endl;
    printRule();

    //Test front and back on an empty list
    cout << "Testing front and back on an empty list..." << endl;
    printList("list1", list1);
    cout << "The front element of list1 is..." << endl;

    try{
        cout << list1.front();
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from an empty list";
    }

    cout << endl;
    cout << "The back element of list1 is..." << endl;

    try{
        cout << list1.back();
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from an empty list";
    }

    cout << endl;
    printRule();

    //Testing overloaded [] on a list with multiple elements
    cout << "Testing overloaded [] operator on a list with multiple elements..."
         << endl;
    printList("list4", list4);
    cout << "The element at position 0 is..." << endl;

    try{
        cout << list4[0];
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from a bad index";
    }

    cout << endl;
    cout << "The element at position 19 (out of bounds) is..." << endl;

    try{
        cout << list4[19];
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from a bad index";
    }

    printRule();

    //Testing overloaded [] on a list with one element
    cout << "Testing overloaded [] operator on a list with one element..."
         << endl;
    printList("list3", list3);
    cout << "The element at position 0 is..." << endl;

    try{
        cout << list3[0];
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from a bad index";
    }

    cout << endl;
    cout << "The element at position -1 (out of bounds) is..." << endl;

    try{
        cout << list3[-1];
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from a bad index";
    }

    printRule();

    //Testing overloaded [] on an empty list
    cout << "Testing overloaded [] operator on an empty list..."
         << endl;
    printList("list2", list2);
    cout << "The element at position 0 (out of bounds) is..." << endl;

    try{
        cout << list2[0];
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from a bad index";
    }

    cout << endl;
    cout << "The element at position 10 (out of bounds) is..." << endl;

    try{
        cout << list2[10];
    }
    catch(BADINDEX b) {
        cout << "Error: attempted to retrieve a value from a bad index";
    }

    printRule();

    //Test erase on a list with multiple elements
    cout << "Testing erase on a list with multiple elements" << endl;
    printList("list4", list4);

    list4.erase();

    printList("list4", list4);
    printRule();

    //Test erase on a list with one element
    cout << "Testing erase on a list with one element" << endl;
    printList("list3", list3);

    list3.erase();

    printList("list3", list3);
    printRule();

    //Test erase on an empty list
    cout << "Testing erase on an empty list" << endl;
    printList("list2", list2);

    list2.erase();

    printList("list2", list2);
    printRule();

    //Test overloaded = on an empty list
    cout << "Testing overloaded = operator on an empty list" << endl;
    printList("list1", list1);
    printList("list2", list2);
    cout << endl << "Copying list2 to list1" << endl;

    list1 = list2;

    printList("list1", list1);
    printRule();

    //Test overloaded = on a list with one element
    list2.pushFront(1);

    cout << "Testing overloaded = operator on a list with one element" << endl;
    printList("list1", list1);
    printList("list2", list2);
    cout << endl << "Copying list2 to list1" << endl;

    list1 = list2;

    printList("list1", list1);
    printRule();

    //Test overloaded = on a list with multiple elements
    list2.pushFront(2);

    cout << "Testing overloaded = operator on a list with multiple elements"
         << endl;
    printList("list1", list1);
    printList("list2", list2);
    cout << endl << "Copying list2 to list1" << endl;

    list1 = list2;

    printList("list1", list1);
    printRule();

    //Print end message
    cout << "End of tests." << endl;

    return 0;
}

//Function implementation
template <class T>
void printList(string name, myList<T>& list, ostream& out)
{

    //Print label
    out << endl << "Here are the elements in " << name << ": " << endl;

    //Print contents of the list
    for(int i = 0; i < list.getSize(); i++)
        out << list[i] << " ";
    out << endl << endl;
}

void printRule(ostream& out, char c, int length)
{
    //Print horizontal rule of char c of size length
    out << endl;
    for(int i = 0; i < length; i++)
        out << c;
    out << endl << endl;
}