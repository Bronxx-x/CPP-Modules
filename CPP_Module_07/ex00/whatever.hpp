/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:19:00 by yousef            #+#    #+#             */
/*   Updated: 2025/09/22 15:21:43 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
T min(const T &a, const T &b) {
    if (a < b)
        return a;
    else if (a > b)
        return b;
    else
        return b;
    
}
template <typename T>
T max(const T &a, const T &b) {
    if (a > b)
        return a;
    else if (a < b)
        return b;
    else
        return b;
}
#endif