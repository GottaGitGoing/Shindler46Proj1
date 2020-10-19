#include "proj1.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <set>

bool verifySolution(std::string s1, std::string s2, std::string s3, const std::map<char, unsigned> & mapping)
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



bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping)
{
	std::set<char> perms;
	std::string concat_strings = s1 + s2 + s3;
	for (unsigned int i = 0; i<concat_strings.length(); ++i)
	{
		perms.insert(concat_strings[i]);
	}

	unsigned int len_of_set = 0;
	std::vector<char> Uniques;
	
	for (auto it = perms.begin(); it != perms.end(); ++it)
	{
		// std::cout << *it << std::endl;
		len_of_set += 1;
		Uniques.push_back(*it);
	}
	// std::cout << len_of_set << std::endl;
	
	// for (auto it = Uniques.begin(); it != Uniques.end(); ++it)
	// {
	// 	std::cout << *it;
	// }
	bool a = PuzzleSolve(len_of_set, "", Uniques,s1,s2,s3);

	return a;
}

bool PuzzleSolve(unsigned int k, std::string S, std::vector<char> U, std::string s1, std::string s2, std::string s3)
{
	// k is the length of set U
	auto new_set = U;
	for (auto it = U.begin(); it != U.end(); ++it)
	{
		S += *it;
		new_set.erase(std::remove(new_set.begin(), new_set.end(), *it), new_set.end()); // source : https://stackoverflow.com/questions/39912/how-do-i-remove-an-item-from-a-stl-vector-with-a-certain-value
		
		if (k == 1)
		{
			/* make a  map of character numbers by iterating thru S and giving the value
			the index i. Then after creating the map, give the proj0 code following:
					proj0code(S,U,S+U,map_I_created) */
			std::map<char,unsigned> potential_map;
			
			for (unsigned int i =0; i<S.length();++i)
			{
				// std::cout << S << std::endl;
				potential_map.insert(std::pair<char,unsigned>(S[i],i));
			}
			potential_map.insert(std::pair<char,unsigned>(U[0],S.length()));
			// for (auto elem:potential_map)
			// {
			// 	std::cout << elem.first << "  " << elem.second << std::endl;
			// }
			if (verifySolution(s1,s2,s3, potential_map) == true)
			{
				std::cout << "Please Please" <<  std::endl;
				return true;

			}

		}
		else
		{
			
			PuzzleSolve(k-1,S,new_set,s1,s2, s3);
		}
		
	}
	return false;
}


