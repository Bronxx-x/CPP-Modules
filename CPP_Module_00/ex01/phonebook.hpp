/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:32:09 by yousef            #+#    #+#             */
/*   Updated: 2025/04/21 09:46:37 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "contact.hpp"

class PhoneBook{
	private:
		Contact	contacts[8];
		int		index;
		bool	full;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	set_info(void);
		void	get_info(void)const;
		void	show_instruction(void);
};

#endif