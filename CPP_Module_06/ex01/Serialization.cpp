/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:50:40 by yousef            #+#    #+#             */
/*   Updated: 2025/09/17 07:55:32 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization() {}
Serialization::~Serialization() {}
Serialization::Serialization(const Serialization &other) { (void)other; }
Serialization &Serialization::operator=(const Serialization &other) 
{ 
    (void)other;
    return *this;
}

uintptr_t Serialization::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

