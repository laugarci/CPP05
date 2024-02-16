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
	int i = 0;
	std::string options[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	while (i <= 3)
	{
		if (name.find(options[i]) != std::string::npos)
			break ;
		i++;
	}
	if (i == 0)
		form = new PresidentialPardonForm;
	else if (i == 1)
		form = new RobotomyRequestForm;
	else if (i == 2)
		form = new ShrubberyCreationForm;
	else
	{
		std::cout << "Form not found" << std::endl;
		return (form);
	}
	std::cout << "crear: " << options[i] << std::endl;
	std::cout << "Intern " << target << " creates " << name << std::endl;
	return (form);
}
