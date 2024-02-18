/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:03:04 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/16 15:02:43 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern& other)
{
	return(*this);
	(void)other;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *form = NULL;
	if (name == "presidential pardon")
	{
		std::cout << "Intern " << target << " creates " << name << std::endl;
		return new PresidentialPardonForm;
	}
	else if (name == "robotomy request")
	{
		std::cout << "Intern " << target << " creates " << name << std::endl;
		return new RobotomyRequestForm;
	}
	else if (name == "shrubbery creation")
	{
		std::cout << "Intern " << target << " creates " << name << std::endl;
		return new ShrubberyCreationForm;
	}
	else
		throw Intern::NonExistForm();
	return (form);
}
