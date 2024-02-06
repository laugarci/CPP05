/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:04:45 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/05 13:16:05 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void createObject(std::string name, int grade)
{
	try {
		Bureaucrat a(name, grade);
		std::cout << a << std::endl;
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
	std::cout << BGRED "[ Correct params Tests ]" RESET << std::endl;
	createObject("1", 13);
	createObject("2", 51);
	createObject("3", 130);
	createObject("4", 150);
	std::cout << BGRED "[ Incorrect params test ]" RESET << std::endl;
	createObject("5", 0);
	createObject("6", -13);
	createObject("7", 170);
	createObject("8", 6734);
	std::cout << BGRED "[ Increment grade Tests ]" RESET << std::endl;
	Bureaucrat a ("Increment", 3);
	std::cout << a;
	incrementGradeTest(a);
	std::cout << a;
	incrementGradeTest(a);
	std::cout << a;
	incrementGradeTest(a);
	std::cout << a;
	std::cout << BGRED "[ Decrement grade test ]" RESET << std::endl;
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
