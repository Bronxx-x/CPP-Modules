/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:50:50 by yousef            #+#    #+#             */
/*   Updated: 2025/09/17 08:05:12 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>
#include <string>


struct Data
{
    int         n;
    float       f;
    std::string str;
};

class Serialization
{
public:
    Serialization();
    ~Serialization();
    Serialization(const Serialization &other);
    Serialization &operator=(const Serialization &other);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
#endif