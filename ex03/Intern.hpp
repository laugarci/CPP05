/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:00:49 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/16 14:44:16 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		AForm *makeForm(std::string name, std::string target);
		class NonExistForm : public std::exception {
			public:
				const char *what() const throw() {
					return ("This form doesn't exist");
			}
		};
};

#endif
