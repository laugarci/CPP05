/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:18:21 by laugarci          #+#    #+#             */
/*   Updated: 2024/02/01 17:21:56 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
    this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137)
{
    this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &old) : AForm(old)
{
    *this = old;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &sform)
{
    std::cout << "Shrubbery Creation Form is assigned" << std::endl;
    this->_target = sform._target;
    return *this;
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	(void)executor;
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename);

    if (file.is_open()) {
        file << "          &&& &&  & &&\n";
        file << "      && &\\/&\\|& ()|/ @, &&\n";
        file << "      &\\/(/&/&||/& /_/)_&/_&\n";
        file << "   &() &\\/&|()|/&\\/ '%" "& ()\n";
        file << "  &_\\_&&_\\ | &&/&__%_/_& &&\n";
        file << "&&   && & &| &| /& & % ()& /&&\n";
        file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
        file << "     &&     \\|||\n";
        file << "             |||\n";
        file << "             |||\n";
        file << "             |||\n";
        file << "       , -=-~  .-^- _\n";

        std::cout << GREEN "Success: "<< RESET << "ShrubberyCreationForm executed successfully. Check file: " << filename << std::endl;
    } else {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &sform)
{
    out << BGRED "[ Shrubbery Creation Form ]" RESET
		<< std::endl << GREEN "Name: " RESET<< sform.getName() << std::endl
		<< GREEN "Target: " RESET << sform.getTarget() << std::endl
		<< GREEN "Grade to sign: " RESET << sform.getSignGrade() << std::endl
		<< GREEN "Grade to execute: " RESET << sform.getExecGrade() << std::endl 
		<< GREEN "Signed: " RESET << sform.getIsSigned() << std::endl;
    return out;
}
