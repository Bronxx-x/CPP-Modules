/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:49:53 by yousef            #+#    #+#             */
/*   Updated: 2025/09/17 08:03:23 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>
#include <stdint.h>

int main()
{
    Data* data = new Data();
    data->f = 42.42f;
    data->n = 42;
    data->str = "Hello, World!";
    uintptr_t raw = Serialization::serialize(data);
    Data* deserialized = Serialization::deserialize(raw);
    
    if (data == deserialized)
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    }
    else
    {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    delete data;
    return 0;
}