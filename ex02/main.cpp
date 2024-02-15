/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:19 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/15 09:51:53 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void tryToSignRobot(Bureaucrat& bureaucrat)
{
	std::cout << BGRED "[ Form Test ]" RESET << std::endl;
	try
	{
		RobotomyRequestForm form("RobotForm");
		bureaucrat.signForm(form);
	//	bureaucrat.signForm(form);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Error: " RESET << e.what() << std::endl << std::endl;
	}
}

void tryToSignShr(Bureaucrat& bureaucrat)
{
	std::cout << BGRED "[ Form Test ]" RESET << std::endl;
	try
	{
		ShrubberyCreationForm form("ShrForm");
		bureaucrat.signForm(form);
	//	bureaucrat.signForm(form);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Error: " RESET << e.what() << std::endl << std::endl;
	}
}

void tryToSignPresident(Bureaucrat& bureaucrat)
{
	std::cout << BGRED "[ Form Test ]" RESET << std::endl;
	try
	{
		PresidentialPardonForm form("PresiForm");
		bureaucrat.signForm(form);
	//	bureaucrat.signForm(form);
		std::cout << std::endl;
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
	tryToSignPresident(a);
	tryToSignShr(a);
	tryToSignRobot(a);
	} catch (const std::exception& e) {
		std::cerr << RED "Error: " RESET << e.what() << std::endl << std::endl;
	}
}

int main()
{
	AForm *form = new ShrubberyCreationForm("ShrForm");
	AForm *form2 = new PresidentialPardonForm("PresiForm");
	AForm *form3 = new RobotomyRequestForm("RobotForm");

	std::cout << BGRED "[ FORM INFO TEST ]" RESET << std::endl << std::endl;
	std::cout << *form << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;

	std::cout << BGRED " [ SHRUBBERY FORM  ]" RESET << std::endl;
	try {
		Bureaucrat bur1("test1", 137);
		form->execute(bur1);
	}
	catch (const std::exception& e) {
		std::cerr << RED "Error: " RESET << e.what() << std::endl;
	
	}
	std::cout << BGRED " [ PRESIDENT FORM ] " RESET << std::endl;
	try {
		Bureaucrat bur2("test2", 5);
		form2->execute(bur2);
	} catch (const std::exception& e){
		std::cerr << RED "Error: " RESET << e.what() << std::endl;
	}

	std::cout << BGRED " [ ROBOTOMY FORM ] " RESET << std::endl;
	try {
		Bureaucrat bur3("test3", 45);
		form3->execute(bur3);
		form3->execute(bur3);
		form3->execute(bur3);
		form3->execute(bur3);
	} catch (const std::exception& e) {
		std::cerr << RED "Error: " RESET << e.what() << std::endl;
	}

	std::cout << BGRED "[ SIGN FORM TEST ]" RESET << std::endl << std::endl;
	createObject("Persona1", 1);
	createObject("Persona2", 145);
	createObject("Persona3", 72);
	createObject("Persona4", 25);
	createObject("Persona5", 10);

	delete form;
	delete form2;
	delete form3;
}
