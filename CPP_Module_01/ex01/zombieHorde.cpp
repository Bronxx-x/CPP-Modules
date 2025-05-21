/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:59:34 by yousef            #+#    #+#             */
/*   Updated: 2025/05/21 02:22:11 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
        horde[i].setName(name);

    return horde;
}
