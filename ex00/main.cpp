/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:04:45 by laugarci          #+#    #+#             */
/*   Updated: 2024/01/27 12:41:07 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("P1", 13);
	Bureaucrat b("P2", 0);
	Bureaucrat c("P3", -3);
	Bureaucrat d("P3", 200);
	Bureaucrat e;
	Bureaucrat f (a);

	std::cout << BGRED"[ Tests ]"RESET << std::endl;
	std::cout << GREEN"Name: "RESET << a.getName() << std::endl << GREEN"Grade: "RESET << a.getGrade() << std::endl << "-------" <<std::endl;
	std::cout << GREEN"Name: "RESET << b.getName() << std::endl << GREEN"Grade: "RESET << b.getGrade() << std::endl << "-------" <<std::endl;
	std::cout << GREEN"Name: "RESET << c.getName() << std::endl << GREEN"Grade: "RESET << c.getGrade() << std::endl << "-------" <<std::endl;
	std::cout << GREEN"Name: "RESET << d.getName() << std::endl << GREEN"Grade: "RESET << d.getGrade() << std::endl << "-------" <<std::endl;
	std::cout << GREEN"Name: "RESET << e.getName() << std::endl << GREEN"Grade: "RESET << e.getGrade() << std::endl << "-------" <<std::endl;
	std::cout << GREEN"Name: "RESET << f.getName() << std::endl << GREEN"Grade: "RESET << f.getGrade() << std::endl << "-------" <<std::endl;
}
