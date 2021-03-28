#pragma once
#include<iostream>
#include <string>                           // For std::to_string()
#include <utility>                          // For std::as_const()
template<typename T>
class Array
{
private:
    T* elements;
    size_t size;
public:
    explicit Array(size_t arraySize);
    Array(const Array& arrry);
    ~Array();
    Array& operator=(const Array& rhs);
    T& operator[](size_t  index);
    const T& operator[](size_t  index)const;
    size_t getSize()const {return size;};
};

template<typename T>
Array<T>::Array(size_t arraySize):elements{new T[arraySize]},size{arraySize}
{}
template<typename T>
Array<T>::Array(const Array& arrry):Array{arrry.size}
{
    for (size_t i = 0; i < arrry.size; i++)
    {
        this->elements[i]=arrry.elements[i];
    }
}
template<typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
  if (index >= size) 
	  throw std::out_of_range {"Index too large: " + std::to_string(index)};

  return elements[index];
}
// Non-const subscript operator in terms of const one
// Uses the 'const-and-back-again' idiom
template<typename T>
T& Array<T>::operator[](size_t  index) 
{
    return const_cast<T&>(std::as_const(*this)[index]);
}
template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
    if(&rhs!=this)
    {
        delete[] elements;
        size=rhs.size;
        elements=new T[size];
        for (size_t i = 0; i < size; i++)
        {
            elements[i]=rhs.elements[i];
        }
    }
    return *this;
}