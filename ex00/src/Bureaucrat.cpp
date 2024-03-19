/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:50:00 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/19 21:47:22 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(int grade, std::string name)
{
    if (grade < 0)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
    {
        this->_grade = grade;
        this->_name = name;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
    *this = rhs;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    this->_grade = rhs.getGrade();
    this->_name = rhs.getName();
    return (*this);
}

std::ostream    &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
    return (o);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

void    Bureaucrat::incrementGrade()
{
    if (this->_grade == 0)
        throw Bureaucrat::GradeTooHighException();
    else
        this->_grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade++;
}