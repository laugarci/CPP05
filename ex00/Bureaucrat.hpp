/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:27:07 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/06 13:25:43 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#define BOLD "\x1B[1m"
#define RESET "\x1B[0m"
#define RED "\x1B[31m"
#define BGRED "\x1B[41m"
#define GREEN "\x1B[32m"

#include <iostream>
#include <string>

class Bureaucrat {
	private:
		const std::string _name;
		unsigned int			_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string type, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& old);
		Bureaucrat	&operator=(const Bureaucrat& bureaucrat);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		//exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Bureaucrat grade too high. Out of range (1-150)";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Bureaucrat grade too low. Out of range (1-150)";
				}
		};

};

std::ostream&	operator<<( std::ostream& out, Bureaucrat& bureaucrat );
std::ostream&	operator<<( std::ostream& out, const Bureaucrat& bureaucrat );


#endif
