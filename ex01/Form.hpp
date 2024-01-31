/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:30:31 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/31 18:46:11 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _sign;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		Form();
		Form( std::string name, unsigned int _signGrade, unsigned int _execGrade );
		~Form();
		Form(const Form& old);
		Form	&operator=(const Form& form);
		std::string	getName( void ) const;
		bool			getIsSigned( void ) const;
		unsigned int	getSignGrade( void ) const;
		unsigned int	getExecGrade( void ) const;
		void			beSigned( const Bureaucrat& bureaucrat );
		//exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Bureaucrat grade too high to sign this form.";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Bureaucrat grade too low to sign this form.";
				}
		};
		class IncorrectGrades : public std::exception {
			public:
				const char* what() const throw() {
					return "Form: incorrect grade. Out of range (1-150)";
				}
		};
};

std::ostream&	operator<<( std::ostream& out, Form& form );
std::ostream&	operator<<( std::ostream& out, const Form& form );



#endif
