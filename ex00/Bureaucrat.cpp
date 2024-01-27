/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:03:52 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/27 12:29:48 by laugarci         ###   ########.fr       */
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

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}
