/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:55:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/03 22:23:23 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

# define SHRUBBERY_SIGN 145
# define SHRUBBERY_EXEC 137

class ShrubberyCreationForm : public Form
{
	private:
		std::string		_target;
		ShrubberyCreationForm();

	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &other);

		ShrubberyCreationForm(std::string target);

		void	execute(Bureaucrat const & executor) const;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */