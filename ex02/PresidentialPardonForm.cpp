/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:17:28 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/03 17:24:32 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Creation Form", 25, 5)
{
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Creation Form", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& old) : AForm(old)
{
	*this = old;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &pform)
{
	this->_target = pform._target;
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	std::cout << _target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
	(void)executor;
}
