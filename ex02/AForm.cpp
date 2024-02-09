/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:55 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/09 15:03:27 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : _name("Default"), _gradeToSign(10), _gradeToExecute(6)
{
    _sign = false;
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name), _sign(false), _gradeToSign(signGrade), _gradeToExecute(execGrade)
{
	if (_gradeToSign < 1 || _gradeToSign > 150)
		throw IncorrectGrades();
	else if (_gradeToExecute < 1 || _gradeToExecute > 150)
		throw IncorrectGrades();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& old)
    : _name(old._name), _sign(old._sign), _gradeToSign(old._gradeToSign), _gradeToExecute(old._gradeToExecute) {
}


AForm &AForm::operator=(const AForm& aform)
{
	if (this != &aform)
	{
        _sign = aform.getIsSigned();
	}
	return (*this);
}

std::string AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_sign);
}

int AForm::getSignGrade(void) const
{
	return (_gradeToSign);
}

int AForm::getExecGrade (void) const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << ". ";
		throw AForm::GradeTooLowException();
	}
	else if (bureaucrat.getGrade() < _gradeToSign)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->_name << ". ";
		throw AForm::GradeTooHighException();
	}
	if (_sign == false)
	{
		_sign = true;
		std::cout << GREEN "Success: " RESET << bureaucrat.getName() << " signed aform " << this->_name << std::endl;
	}
	else
		std::cout << RED "This aform is already signed." RESET << std::endl;
}

std::ostream& operator<<(std::ostream& out, const AForm& aform)
{
	out << BGRED "[ AForm info ]" RESET << std::endl;
	out << GREEN "AForm name: " RESET<< aform.getName() << std::endl
		<< GREEN "Grade to sign: " RESET<< aform.getSignGrade() << std::endl
		<< GREEN "Grade to execute: " RESET<< aform.getExecGrade();
	return (out);
}

std::ostream& operator<<(std::ostream& out, AForm& aform)
{
	out << BGRED "[ AForm info ]" RESET << std::endl;
	out << GREEN "AForm name: " RESET<< aform.getName() << std::endl
		<< GREEN "Grade to sign: " RESET<< aform.getSignGrade() << std::endl
		<< GREEN "Grade to execute: " RESET<< aform.getExecGrade();
	return (out);
}
