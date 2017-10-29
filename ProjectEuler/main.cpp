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
   
    std::cout << "Problem 5: smallest positive number that is evenly divisible by all of the numbers from 1 to 20" << std::endl;
    std::cout << ProjectEuler::SmallestDivisibleByAllNumbersUnder(20) << std::endl;
    
    std::cout << "Problem 6: Difference between sum of integers 1-100 squared, and the sum of their individual squares" << std::endl;
    std::cout << ProjectEuler::SumSquareDifference(100) << std::endl;
    
    std::cout << "Problem 7: 10,001th prime number:" << std::endl;
    std::cout << ProjectEuler::GetNthPrime(10001) << std::endl;
    
    std::string series = 
            "73167176531330624919225119674426574742355349194934"
            "96983520312774506326239578318016984801869478851843"
            "85861560789112949495459501737958331952853208805511"
            "12540698747158523863050715693290963295227443043557"
            "66896648950445244523161731856403098711121722383113"
            "62229893423380308135336276614282806444486645238749"
            "30358907296290491560440772390713810515859307960866"
            "70172427121883998797908792274921901699720888093776"
            "65727333001053367881220235421809751254540594752243"
            "52584907711670556013604839586446706324415722155397"
            "53697817977846174064955149290862569321978468622482"
            "83972241375657056057490261407972968652414535100474"
            "82166370484403199890008895243450658541227588666881"
            "16427171479924442928230863465674813919123162824586"
            "17866458359124566529476545682848912883142607690042"
            "24219022671055626321111109370544217506941658960408"
            "07198403850962455444362981230987879927244284909188"
            "84580156166097919133875499200524063689912560717606"
            "05886116467109405077541002256983155200055935729725"
            "71636269561882670428252483600823257530420752963450";
            
    std::cout << "Problem 8: Largest product in a series - 13 adjacent numbers:" << std::endl;
    std::cout << ProjectEuler::GetBiggestAdjacentProduct(series, 13) << std::endl;
    
    
    return 0;
}

