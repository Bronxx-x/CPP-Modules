/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:14:37 by yousef            #+#    #+#             */
/*   Updated: 2025/06/20 17:15:30 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain &other);
    ~Brain();
    Brain &operator=(const Brain &other);

    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};
#endif