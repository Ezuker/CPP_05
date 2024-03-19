/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:50:03 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/19 21:47:10 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat benoit(1510, "name");
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat benoit(-5, "name");
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat benoit(150, "name");
        benoit.decrementGrade();
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat benoit(0, "name");
        benoit.incrementGrade();
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
}