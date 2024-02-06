/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:30:31 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/06 15:25:48 by laugarci         ###   ########.fr       */
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
		const std::string _name;
		bool _sign;
		const int _gradeToSign;
		const int _gradeToExecute;
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
					return "Bureaucrat grade too high.";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Bureaucrat grade too low.";
				}
		};
		class IncorrectGrades : public std::exception {
			public:
				const char* what() const throw() {
					return "Incorrect grades to create a form. Out of range (1-150)";
				}
		};
};

std::ostream&	operator<<( std::ostream& out, Form& form );
std::ostream&	operator<<( std::ostream& out, const Form& form );



#endif
