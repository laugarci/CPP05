
#ifndef FORM_HPP
#define FORM_HPP


class Form {
	private:
		const std::string _name;
		bool _sign;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form();
		~Form();
		Form(const Form& old);
		Form	&operator=(const Form& form);
		std::string	getName( void ) const;
		bool		getIsSigned( void ) const;
		unsigned int	getSignGrade( void ) const;
		unsigned int	getExecGrade( void ) const;
		void		beSigned( const Bureaucrat& bureaucrat );
		//exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Bureaucrat grade out of range (1-150)";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Bureaucrat grade out of range (1-150)";
				}
		};
};

std::ostream&	operator<<( std::ostream& out, Form& form );
std::ostream&	operator<<( std::ostream& out, const Form& form );



#endif
