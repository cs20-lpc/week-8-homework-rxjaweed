#include <iostream>
#include "LinkedListStack.hpp"
#include "Stack.hpp"
using namespace std;

int main() {
    LinkedListStack<int> list;

    cout << "Pushing elements 10, 20, 30..." << endl;
    list.push(10);
    list.push(20);
    list.push(30);
    list.print();  // should show 30, 20, 10
    cout << "Getting length..." << endl;
    cout << list.getLength() << endl;

    cout << "Peek top element: " << list.peek() << endl;

    cout << "Popping top element..." << endl;
    list.pop();
    list.print();  // should show 20, 10

    cout << "Rotating LEFT..." << endl;
    list.rotate(Stack<int>::Direction::LEFT);
    list.print();  // should show 10, 20

    cout << "Rotating RIGHT..." << endl;
    list.rotate(Stack<int>::Direction::RIGHT);
    list.print();  // should show 20, 10

    cout << "Copying list to anotherList..." << endl;
    LinkedListStack<int> anotherList(list);
    anotherList.print();  // should match list

    cout << "Clearing list..." << endl;
    list.clear();
    list.print();  // should say empty

    cout << "Done testing." << endl;
    return 0;
}
