/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: W
 *
 * Created on October 25, 2017, 11:25 PM
 */

#include <cstdlib>
#include <iostream>
#include "ProjectEuler.h"

/*
 * 
 */
int main(int argc, char** argv) 
{
    std::cout << "Problem 1: Multiples of 3 and 5" << std::endl;
    std::cout << ProjectEuler::SumOfMultiplesUnder(3, 5, 1000) << std::endl;
    
    std::cout << "Problem 2: Sum of even Fibonacci numbers under 4 million" << std::endl;
    std::cout << ProjectEuler::EvenFibonacciNumbersUnder(4000000) << std::endl;
    
    std::cout << "Problem 3: largest prime factor of 600851475143" << std::endl;
    std::vector<int> pfs;
    ProjectEuler::GetPrimeFactors(600851475143,pfs);
    std::cout << *std::max_element(pfs.begin(), pfs.end()) << std::endl;
    
    std::cout << "Problem 4: Largest palindrome product of two 3-digit numbers:" << std::endl;
    std::cout << ProjectEuler::LargestPalindrome() << std::endl;
    return 0;
}

