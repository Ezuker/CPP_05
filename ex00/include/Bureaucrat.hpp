/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:50:05 by bcarolle          #+#    #+#             */
/*   Updated: 2024/03/19 21:21:23 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    public:
        //Contructors Destructors
        Bureaucrat();
        Bureaucrat(int grade, std::string name);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat();

        //Operator
        Bureaucrat  &operator=(const Bureaucrat &rhs);
        
        //Accessors
        int         getGrade() const;
        std::string getName() const;

        //Member functions
        void    incrementGrade();
        void    decrementGrade();
        
        //Exception
        class GradeTooHighException : public std::exception
        {
            public:
                const char    *what()
                {
                    return ("Grade too High");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char    *what()
                {
                    return ("Grade too Low");
                }
        };

    private:
        std::string _name;
        int         _grade;
};

std::ostream    &operator<<(std::ostream &o,const Bureaucrat &rhs);