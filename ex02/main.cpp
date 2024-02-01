/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:19 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/01 16:49:05 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat bur("test", 10);
	AForm *form = new ShrubberyCreationForm("test");
	ShrubberyCreationForm sform;

	std::cout << *form << std::endl;
	form->execute(bur);
}
