/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:03:52 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/06 15:19:43 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("undefined"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& old)
{
	*this = old;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
	{
		this->_grade = bureaucrat.getGrade();
	}
	return (*this);
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream&	operator<<( std::ostream& out, Bureaucrat& bureaucrat )
{
	out << GREEN "Name: " RESET << bureaucrat.getName() << std::endl << GREEN "Grade: " RESET << bureaucrat.getGrade() <<std::endl;
	return (out);
}

std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat )
{
	out << GREEN "Name: " RESET << bureaucrat.getName() << std::endl << GREEN "Grade: " RESET << bureaucrat.getGrade() <<std::endl;
	return (out);
}
