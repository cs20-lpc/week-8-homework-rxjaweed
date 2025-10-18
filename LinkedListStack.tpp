template <typename T>
LinkedListStack<T>::LinkedListStack()
{ 
    top = nullptr;
    length = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    Node<T>* current = top;
    Node<T>* temp = top;

    while (current != nullptr)
    {
        current = temp->next;
        delete temp;
        temp = current;

    }
    top = nullptr;

}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    
    Node<T>* current = copyObj.top; //this is the source we are copying from
    Node<T>* newcurrent = new Node<T> (current->data); //creating a new node to copy data pointed to by source
    top = newcurrent; //copies top element
    

    if (copyObj.top == nullptr) //if its empty, then we are done here.
    {
        top = nullptr;
        return;
    }
    
    current = current->next;
    while (current != nullptr)
    {
        newcurrent->next = new Node<T> (current->data); //creating a new node in each remaining element
        newcurrent = newcurrent->next;
        current = current->next;
    }
    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    if (isEmpty())
    {
        throw string ("Stack is empty, cannot pop from empty stack");
    }
    Node<T>* current = top;
    top = top->next;
    delete current;
    length--;

    
    
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
     Node<T>* newNode = new Node<T> (elem);
     newNode->next = top;
     top = newNode; 
     length++;
  
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    if (isEmpty())
    {
        throw string ("Stack is empty, can't rotate");
    }
    if (top->next == nullptr)
    {
        throw string ("Can't rotate, only one element in stack");
    }
    else 
    {
        if (dir == Stack<T>::Direction::RIGHT)
        {
            Node<T>* prev = nullptr; //previous to the node we are moving
            Node<T>* current = top; //node we are moving
            while (current->next != nullptr)
            {
                prev = current;
                current = current->next;
            }
            prev->next = nullptr;
            current->next = top; //Note to self: you always have to insert element before top, and then add it after top
            top = current;
        }

        if (dir == Stack<T>::Direction::LEFT)
        {
            Node<T>* current = top;
            
            top = top->next; //new top
            current->next = nullptr; //make the first element (current) now point to nullptr

            Node<T>* prev = top;
            while (prev->next != nullptr)
            {
                prev = prev->next;
            }
            prev->next = current; 
            
        }
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
