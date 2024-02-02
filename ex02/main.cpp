/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:19 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/02 16:18:45 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat bur("test", 10);
	AForm *form = new ShrubberyCreationForm("test");
	AForm *form2 = new PresidentialPardonForm("hola");
	AForm *form3 = new RobotomyRequestForm("adios");
	ShrubberyCreationForm sform;

	std::cout << *form << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;
//	form->execute(bur);
}
