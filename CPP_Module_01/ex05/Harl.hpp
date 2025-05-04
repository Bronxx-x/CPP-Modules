/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:21:08 by yousef            #+#    #+#             */
/*   Updated: 2025/05/04 15:24:07 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <iostream>
#include <string>


typedef void (*HarlFunc)(void);
class Harl
{
public:
    Harl();
    ~Harl();
    void complain( std::string level );
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    HarlFunc functions[4];
    std::string levels[4];
    void initFunctions();
    void initLevels();
};
#endif