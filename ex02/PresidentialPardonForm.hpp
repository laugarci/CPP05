/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:03:34 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/01 15:07:16 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>
#include <string>

class PresidentialPardonForm {
	private:
		std::string const _name;
		bool _sign;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& old);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm& form);
};


#endif
