/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:30:31 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/01 15:42:46 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef aform_HPP
#define aform_HPP

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool _sign;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		AForm();
		AForm( std::string name, unsigned int _signGrade, unsigned int _execGrade );
		virtual ~AForm();
		AForm(const AForm& old);
		AForm	&operator=(const AForm& aform);
		std::string	getName( void ) const;
		bool			getIsSigned( void ) const;
		unsigned int	getSignGrade( void ) const;
		unsigned int	getExecGrade( void ) const;
		void			beSigned( const Bureaucrat& bureaucrat );
		virtual void        execute(Bureaucrat const & executor) const = 0;
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
					return "Incorrect grades to create a aform. Out of range (1-150)";
				}
		};
};

std::ostream&	operator<<( std::ostream& out, AForm& aform );
std::ostream&	operator<<( std::ostream& out, const AForm& aform );



#endif
