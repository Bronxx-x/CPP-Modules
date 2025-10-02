/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:17:02 by yhamdan           #+#    #+#             */
/*   Updated: 2025/10/02 21:47:20 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        // [...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\n================ EXTRA TESTS ================\n" << std::endl;

    // Extra: MutantStack tests
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size after pop: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;

        std::cout << "Iterating MutantStack:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
        std::cout << "Copied std::stack size: " << s.size() << std::endl;
    }

    std::cout << "\n---------------------------------------------\n" << std::endl;

    // Extra: std::list tests
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);

        std::cout << "Back: " << lst.back() << std::endl;
        lst.pop_back();
        std::cout << "Size after pop_back: " << lst.size() << std::endl;

        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::list<int>::iterator lit = lst.begin();
        std::list<int>::iterator lite = lst.end();
        ++lit;
        --lit;

        std::cout << "Iterating std::list:" << std::endl;
        while (lit != lite)
        {
            std::cout << *lit << std::endl;
            ++lit;
        }

        std::list<int> ls(lst);
        std::cout << "Copied list size: " << ls.size() << std::endl;
    }

    std::cout << "\n---------------------------------------------\n" << std::endl;

    // Optional bonus: const_iterator test
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);

        std::cout << "Const Iterator test:" << std::endl;
        MutantStack<int>::const_iterator cit = mstack.begin();
        MutantStack<int>::const_iterator cite = mstack.end();
        while (cit != cite)
        {
            std::cout << *cit << std::endl;
            ++cit;
        }
    }

    return 0;
}
