/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:32:09 by yousef            #+#    #+#             */
/*   Updated: 2025/05/17 20:40:24 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "Contact.hpp"

class PhoneBook{
	private:
		Contact	contacts[8];
		int		index;
		int 	overindex;
		bool	full;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	set_info(void);
		void	get_info(void)const;
		void	show_instruction(void);
};

#endif