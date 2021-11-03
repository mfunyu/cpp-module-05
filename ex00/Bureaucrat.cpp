/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:03 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/03 13:15:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() : _name("no_name"), _grade(GRADE_LOWEST)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_name = other._name;
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	setGrade(grade);
}

std::string		Bureaucrat::getName() const
{
	return _name;
}

int		Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrage()
{
	setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrage()
{
	setGrade(_grade + 1);
}

bool	Bureaucrat::isGradeTooHigh(int grade)
{
	return grade < GRADE_HIGHEST;
}

bool	Bureaucrat::isGradeTooLow(int grade)
{
	return GRADE_LOWEST < grade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (isGradeTooHigh(grade))
	{
		throw GradeTooHighException();
	}
	if (isGradeTooLow(grade))
	{
		throw GradeTooLowException();
	}
	_grade = grade;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}


std::ostream	&operator<<(std::ostream &os, const Bureaucrat& bureaucrat)
{
	std::cout << bureaucrat.getName() << ": bureaucrat grade " <<\
				 bureaucrat.getGrade();
	return os;
}
