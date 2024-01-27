/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:03:52 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/27 13:54:02 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	_name = "Undefined";
	_grade = 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	_name = name;
	_grade = grade;
	try {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception &e)
	{
			this->_name = name;
			this->_grade = 0;
	}
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& old)
{
	*this = old;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(): std::exception()
{
	std::cout << "Grade too high" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(): std::exception()
{
	std::cout << "Grade too low" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
	{
		this->_name = bureaucrat.getName();
		this->_grade = bureaucrat.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}
