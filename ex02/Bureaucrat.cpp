/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:03:52 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/03 17:57:28 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
	_name = "undefined";
	_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	_name = name;
	_grade = grade;
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
		this->_name = bureaucrat.getName();
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

void    Bureaucrat::signForm(AForm &aform)
{
	try
	{
		aform.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Error: " RESET << e.what() << std::endl;
	}
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
