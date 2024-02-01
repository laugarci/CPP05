/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:10:39 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/01 18:07:26 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm ("RobotomyRequestForm Creation Form", 72, 45)
{
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &old) : AForm(old)
{
	*this = old;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rform)
{
	this->_target = rform._target;
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	std::cout << "rrrrbbbbrrtttttttt" << std::endl;
	(void)executor;

}
