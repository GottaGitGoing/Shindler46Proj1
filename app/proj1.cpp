#include "proj1.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <list>


bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping)
{
	try
	{
	std::string s1_to_number,s2_to_number, s3_to_number;
    for (unsigned int i = 0; i<s1.length();i++)
    {
        s1_to_number += std::to_string(mapping.at(s1[i]));
        // std::bcout << s1_to_number << "  ==  " << std::endl;
    }
    for (unsigned int i = 0; i<s2.length();i++)
    {
        s2_to_number += std::to_string(mapping.at(s2[i]));
        // std::cout << s2_to_number << "  ==  " << std::endl;
    }
    std::stringstream st1(s1_to_number);
    std::stringstream st2(s2_to_number);

    unsigned int x,y,strings_sum;
    st1 >> x;
    st2 >> y;
    strings_sum = x +y;
    // std::cout << x << "  " << y << std::endl;

    for (unsigned int i = 0; i<s3.length();i++)
    {
        s3_to_number += std::to_string(mapping.at(s3[i]));
        // std::cout << s2_to_number << "  ==  " << std::endl;
    }

    std::stringstream st3(s3_to_number);
    unsigned int s3_val;
    st3 >> s3_val;

    // std::cout << s3_val << std::endl;
    if (s3_val == strings_sum)
    {
        return true;
    }
	return false;
	}
	catch(const std::exception& e)
	{
		return false;
	}
	
    
    

}



bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping)
{
	std::vector<char> Uniques;
	std::string concat = s1 + s2 + s3;

	for (unsigned int i=0; i<concat.length(); ++i)
	{
		if (   std::find(Uniques.begin(),Uniques.end(),concat[i]) == Uniques.end()  )
		{
			Uniques.push_back(concat[i]);	
		}
	}
	

	std::list<char> U;

	for (unsigned int i = 0; i<10; ++i)
	{
		char aChar = '0' + i; // source stackOverflow convert int to char.
		U.push_back(aChar);
	}
	
	std::map<char,unsigned> to_check_map;
	std::string empty_sting;
	PuzzleSolve(Uniques.size(), empty_sting,U,Uniques,s1,s2,s3, mapping);

	if (verifySolution(s1,s2,s3,mapping) == true)
	{
		return true;
	}
	else
	{
		return false; 	
	}
		
}


bool PuzzleSolve(unsigned int k, std::string S, std::list<char> U, std::vector<char> Uniq_list, std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping)
{
	// general idea, Tammasia TxtBook
	std::list<char> new_set = U;
	for (auto elem:U)
	{
	
		S.push_back(elem);
	
		for (auto it = new_set.begin(); it != new_set.end();)
		{
	
			if (*it == elem)
			{
				it = new_set.erase(it);
				break;
			}
			else
			{
				++it;
			}
			
		}
		if (k==1)
		{
			std::map<char,unsigned> correct_map;
			for (unsigned int s_ind = 0; s_ind<S.size(); ++s_ind)
			{
				correct_map.insert(std::pair<char,unsigned>(Uniq_list[s_ind],S.at(s_ind)-48));
			}

			if (verifySolution(s1,s2,s3,correct_map) == true)
			{	
				mapping = correct_map;
				return true;
			}
		}
		else
		{
			
			PuzzleSolve(k-1, S, new_set, Uniq_list, s1,s2,s3, mapping);
		}
		S.pop_back();
		new_set.push_back(elem);
		
	}
	return false;
}

