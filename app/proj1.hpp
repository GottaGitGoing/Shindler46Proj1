#ifndef __PROJ_1__HPP
#define __PROJ_1__HPP

#include <map>
#include <string>
#include <vector>
#include <set>
#include <list>

/* 
 * Project 1:  you need to implement this function.
 I promise that any of my test cases will have an empty 
 	map as the fourth parameter when called.
 If the puzzle IS solvable, return true AND make the mapping indicate the solution.
 If the puzzle is NOT solvable, it is enough to return false.

 See the project 1 write-up for a better description. 
 */

std::map<char,unsigned> PuzzleSolve(unsigned int k, std::string S, std::list<unsigned> U, std::vector<char> Uniq_list, std::string s1, std::string s2, std::string s3);


bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping);

bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping);


#endif