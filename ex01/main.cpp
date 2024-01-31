/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:04:45 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/31 18:46:02 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void tryToSign(Bureaucrat& bureaucrat)
{
	std::cout << BGRED "[ Form Test ]" RESET << std::endl;
	try
	{
		Form form("form1", 10, 10);
		bureaucrat.signForm(form);
		//bureaucrat.signForm(form);
		std::cout << std::endl;
		//std::cout << std::endl << form << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Error: " RESET << e.what() << std::endl << std::endl;
	}
}


void createObject(std::string name, int grade)
{
	try {
	Bureaucrat a(name, grade);
	std::cout << BGRED "[ Bureaucrat info ]" RESET << std::endl;
	std::cout << a << std::endl;
	tryToSign(a);
	} catch (const std::exception& e) {
		std::cerr << RED "Error: " RESET << e.what() << std::endl << std::endl;
	}
}

void	incrementGradeTest(Bureaucrat& bureaucrat)
{
	try {
		bureaucrat.incrementGrade();
	} catch (const std::exception& e) {
		std::cerr << RED "Error: " RESET << e.what() << std::endl;
	}
}

void	decrementGradeTest(Bureaucrat& bureaucrat)
{
	try {
		bureaucrat.decrementGrade();
	} catch (const std::exception& e) {
		std::cerr << RED "Error: " RESET << e.what() << std::endl;
	}
}

int main()
{
	std::cout << BGRED "[ CORRECT PARAMS TEST ]" RESET << std::endl << std::endl;
	createObject("AAA", 1);
	createObject("BBB", 51);
	createObject("CCC", 130);
	createObject("DDD", 150);
	createObject("III", 10);
	std::cout << BGRED "[ INCORRECT PARAMS TEST ]" RESET << std::endl;
	createObject("EEE", 0);
	createObject("FFF", -13);
	createObject("GGG", 170);
	createObject("HHH", 6734);
	std::cout << std::endl << BGRED "[ INCREMENT GRADE TEST ]" RESET << std::endl;
	Bureaucrat a ("Increment", 3);
	std::cout << a;
	incrementGradeTest(a);
	std::cout << a;
	incrementGradeTest(a);
	std::cout << a;
	incrementGradeTest(a);
	std::cout << a;
	std::cout << std::endl << BGRED "[ DECREMENT GRADE TEST ]" RESET << std::endl;
	Bureaucrat b ("Decrement", 148);
	std::cout << b;
	decrementGradeTest(b);
	std::cout << b;
	decrementGradeTest(b);
	std::cout << b;
	decrementGradeTest(b);
	std::cout << b;

	return (0);
}
