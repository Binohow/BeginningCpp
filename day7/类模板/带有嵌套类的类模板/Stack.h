#pragma once
#include<iostream>
template<typename T>
class Stack
{
private:
    class Node
    {   
        public:
            T item {};
            Node* next;
            Node(const T& item):item{item}{};
    };
    
    Node* head{};
    
public:
    Stack()=default;
    Stack(const Stack& stack); // Copy constructor
    ~Stack();// Destructor
    Stack& operator=(const Stack(& rhs));

    void push(const T& item);
    T pop();
    bool isEmpty() const;
    void swap(Stack& other) noexcept;
};

template <typename T>
Stack<T>::Stack(const Stack& stack)
{
    if (stack.head)
    {
        this->head=new Node{(*stack.head)};
        Node* oldNode {stack.head};
        Node* newNode {head};
        while ((oldNode=oldNode->next))
        {
            newNode->next=new Node{*oldNode};
            newNode=newNode->next;
        }        
    }
    
}

template<typename T>
Stack<T>::~Stack()
{
    while (head)
    {
        auto temp=head->next;
        delete head;
        head=temp;
    }
    
}

template<typename T>
void Stack<T>::swap(Stack& other)noexcept
{
    std::swap(head, other.head);
}

template<typename T>
void swap(Stack<T>& one, Stack<T>& other) noexcept
{
    std::swap(one.head,other.head);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& rhs)
{
    auto copy{rhs};
    swap(copy);
    return *this;
}
template<typename T>
bool Stack<T>::isEmpty()const
{
    return head==nullptr;
}
template<typename T>
T Stack<T>::pop()
{
    if (isEmpty())
        throw std::logic_error{"Stack empty"};

    
    Node* temp {head};
    T item {head->item};
    head = head->next;
    delete temp;
    return item;
}

template <typename T>
void Stack<T>::push(const T& item)
{
    Node* node{new Node{item}};
    node->next=head;
    head=node;
}
