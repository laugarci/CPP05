/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:19 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/16 15:01:14 by laugarci         ###   ########.fr       */
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

	AForm *robot = intern1.makeForm("robotomy request", "Manuel");
	AForm *presi = intern2.makeForm("presidential pardon", "Pepito");
	AForm *shr = intern3.makeForm("shrubbery creation", "Menganito");

	Bureaucrat bur("test1", 45);
	robot->execute(bur);
	Bureaucrat bur1("test2", 5);
	presi->execute(bur1);
	Bureaucrat bur2("test3", 137);
	shr->execute(bur2);
	
	try {
	AForm *test = intern1.makeForm("test", "test");
	test->execute(bur2);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
