/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:52:57 by yousef            #+#    #+#             */
/*   Updated: 2025/09/22 15:52:58 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array {
private:
    T* elements;
    unsigned int size;
public:
    Array() : elements(NULL), size(0) {}
    Array(unsigned int n) : size(n) 
    {
        elements = new T[n];
    }
    Array(const Array& other) : elements(NULL), size(other.size) 
    {
        if (size > 0) {
            elements = new T[size];
            for (unsigned int i = 0; i < size; ++i)
                elements[i] = other.elements[i];
        }
    }
    
    Array& operator=(const Array& other) 
    {
        if (this != &other) 
        {
            delete[] elements;
            size = other.size;
            elements = NULL;
            if (size > 0) 
            {
                elements = new T[size];
                for (unsigned int i = 0; i < size; ++i)
                    elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    ~Array() 
    {
        delete[] elements;
    }

    T& operator[](unsigned int index) 
    {
        if (index >= size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return elements[index];
    }

    const T& operator[](unsigned int index) const 
    {
        if (index >= size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return elements[index];
    }

    unsigned int getSize() const 
    {
        return size;
    }
};
#endif