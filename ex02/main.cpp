/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:44:39 by facarval          #+#    #+#             */
/*   Updated: 2024/05/21 16:20:57 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>

Base *generate(void)
{
    sleep(1);
    srand(time(NULL));

    int nb;

    nb = rand() % 3 + 1;
    switch (nb)
    {
    case 1:
    {
        std::cout << "generated a A" << std::endl;
        return new A;
    }
    case 2:
    {
        std::cout << "generated a B" << std::endl;
        return new B;
    }
    case 3:
    {
        std::cout << "generated a C" << std::endl;
        return new C;
    }
    break;
    }
    return 0;
}

void identify(Base *p)
{
    A *aa = dynamic_cast<A *>(p);
    B *bb = dynamic_cast<B *>(p);
    C *cc = dynamic_cast<C *>(p);
    if (aa)
    {
        std::cout << "The class is A" << std::endl;
    }
    else if (bb)
    {
        std::cout << "The class is B" << std::endl;
    }
    else if (cc)
    {
        std::cout << "The class is C" << std::endl;
    }
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "The class is A" << std::endl;
    }
    catch (std::exception &)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "The class is B" << std::endl;
    }
    catch (std::exception &)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "The class is C" << std::endl;
    }
    catch (std::exception &)
    {
    }
}

int main(void)
{
    {
        Base *base = generate();

        identify(base);

        delete base;
    }

    {
        Base *base2 = generate();

        identify(*base2);

        delete base2;
    }

    return 0;
}