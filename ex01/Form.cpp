/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:55 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/31 16:36:30 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
/*
Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade)
{
	_name = name;
	_gradeToSign = signGrade;
	_gradeToExecute = execGrade;
	_sign = false;
}*/

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade)
    : _name(name), _sign(false), _gradeToSign(signGrade), _gradeToExecute(execGrade) {
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
	//	_name = form.getName();
        _sign = form.getIsSigned();
   //     _gradeToSign = form.getSignGrade();
    //    _gradeToExecute = form.getExecGrade();
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
		throw Form::GradeTooLowException();
	_sign = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "------------- Form Info -------------" << std::endl;
    out << "Form name: " << form.getName() << std::endl
      << "Grade to sign: " << form.getSignGrade() << std::endl
      << "Grade to execute: " << form.getExecGrade();
    return out;
}

std::ostream& operator<<(std::ostream& out, Form& form) {
    out << "------------- Form Info -------------" << std::endl;
    out << "Form name: " << form.getName() << std::endl
      << "Grade to sign: " << form.getSignGrade() << std::endl
      << "Grade to execute: " << form.getExecGrade();
    return out;
}
