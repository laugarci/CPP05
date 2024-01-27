/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:27:07 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/27 12:41:04 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#define BOLD "\x1B[1m"
#define RESET "\x1B[0m"
#define RED "\x1B[31M"
#define BGRED "\x1B[41m"
#define GREEN "\x1B[32m"

#include <iostream>
#include <string>

class Bureaucrat {
	private:
		std::string _name;
		int			_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string type, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& old);
		Bureaucrat	&operator=(const Bureaucrat& bureaucrat);
		std::string	getName(void) const;
		int			getGrade(void) const;
};



#endif
