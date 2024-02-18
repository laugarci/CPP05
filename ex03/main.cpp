/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:19 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/18 16:34:25 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	std::cout << BGRED "[ SUBJECT TEST ]" RESET << std::endl;
   	Intern  someRandomIntern;
	AForm*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;

	std::cout << BGRED "[ MORE TESTS ]" RESET << std::endl;
	Intern intern1;
	Intern intern2;
	Intern intern3;
	
	try {
		AForm *robot = intern1.makeForm("robotomy request", "Manuel");
		AForm *presi = intern2.makeForm("presidential pardon", "Pepito");
		AForm *shr = intern3.makeForm("shrubbery creation", "Menganito");

		Bureaucrat bur("test1", 45);
		robot->execute(bur);
		Bureaucrat bur1("test2", 5);
		presi->execute(bur1);
		Bureaucrat bur2("test3", 137);
		shr->execute(bur2);
		delete robot;
		delete presi;
		delete shr;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << BGRED "[ INCORRECT TEST ]" RESET << std::endl;
	try {
		AForm *test = intern1.makeForm("test", "test");
		Bureaucrat bur3("test", 5);
		test->execute(bur3);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
