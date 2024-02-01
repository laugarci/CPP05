/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:03:34 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/01 16:07:18 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& old);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm& sform);
		std::string	getTarget() const;
		void execute(Bureaucrat const& executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shrub);

#endif
