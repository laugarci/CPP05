/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:55 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/01 10:48:17 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : _name("Default"), _gradeToSign(10), _gradeToExecute(6)
{
    _sign = false;
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade)
    : _name(name), _sign(false), _gradeToSign(signGrade), _gradeToExecute(execGrade)
{
	if (_gradeToSign < 1)
		throw IncorrectGrades();
	else if (_gradeToExecute > 150)
		throw IncorrectGrades();
}

Form::~Form()
{
}

Form::Form(const Form& old)
    : _name(old._name), _sign(old._sign), _gradeToSign(old._gradeToSign), _gradeToExecute(old._gradeToExecute) {
}


Form &Form::operator=(const Form& form)
{
	if (this != &form)
	{
        _sign = form.getIsSigned();
	}
	return (*this);
}

std::string Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_sign);
}

unsigned int Form::getSignGrade(void) const
{
	return (_gradeToSign);
}

unsigned int Form::getExecGrade (void) const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << ". ";
		throw Form::GradeTooLowException();
	}
	else if (bureaucrat.getGrade() < _gradeToSign)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << ". ";
		throw Form::GradeTooHighException();
	}
	if (_sign == false)
	{
		_sign = true;
		std::cout << GREEN "Success: " RESET << bureaucrat.getName() << " signed form " << this->_name << std::endl;
	}
	else
		std::cout << RED "This form is already signed." RESET << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << BGRED "[ Form info ]" RESET << std::endl;
	out << GREEN "Form name: " RESET<< form.getName() << std::endl
		<< GREEN "Grade to sign: " RESET<< form.getSignGrade() << std::endl
		<< GREEN "Grade to execute: " RESET<< form.getExecGrade();
	return (out);
}

std::ostream& operator<<(std::ostream& out, Form& form)
{
	out << BGRED "[ Form info ]" RESET << std::endl;
	out << GREEN "Form name: " RESET<< form.getName() << std::endl
		<< GREEN "Grade to sign: " RESET<< form.getSignGrade() << std::endl
		<< GREEN "Grade to execute: " RESET<< form.getExecGrade();
	return (out);
}
