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
	std::vector<char> Uniques;
	std::string concat = s1 + s2 + s3;

	for (unsigned int i=0; i<concat.length(); ++i)
	{
		if (   std::find(Uniques.begin(),Uniques.end(),concat[i]) == Uniques.end()  )
		{
			Uniques.push_back(concat[i]);	
		}
	}
	
	// for (auto elem:Uniques)
	// {
	// 	std::cout << elem << std::endl;
	// }

	std::list<unsigned> U;

	for (unsigned int i = 0; i<10; ++i)
	{
		U.push_back(i);
	}

	// for (auto elem:U)
	// {
	// 	std::cout << elem << " -- " << std::endl;
	// }

	std::map<char,unsigned> to_check_map;
	std::string empty_sting;
	to_check_map = PuzzleSolve(Uniques.size(), empty_sting,U,Uniques,s1,s2,s3);

	if (to_check_map.size() == 0)
	{
		return false;
	}
	
	mapping = to_check_map;
	return true;

	
}


std::map<char,unsigned> PuzzleSolve(unsigned int k, std::string S, std::list<unsigned> U, std::vector<char> Uniq_list, std::string s1, std::string s2, std::string s3)
{
	std::list<unsigned> new_set = U;
	for (auto elem:U)
	{
		// if (elem > Uniq_list.size())
		// {
		// 	continue;
		// }
		// std::cout << "Failing at for loop 1 " << elem  << std::endl;
		try
		{
			S.push_back(Uniq_list.at(elem));
		}
		catch(const std::exception& e)
		{
			continue;
		}
		
		
		// std::cout << "Failing at push_back" << std::endl;
		for (auto it = new_set.begin(); it != new_set.end();)
		{
			// std::cout << "Failing at for loop 2" << std::endl;
			if (*it == elem)
			{
				// std::cout << "Failing at erase" << std::endl;
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
			// std::cout << "Failing at base case" << std::endl;
			std::map<char,unsigned> correct_map;
			for (unsigned int char_num_ind = 0; char_num_ind<Uniq_list.size(); ++char_num_ind)
			{
				// std::cout << "Failing at base map pop" << std::endl;
				correct_map.insert(std::pair<char,unsigned>(Uniq_list.at(char_num_ind),char_num_ind));
			}

			if (verifySolution(s1,s2,s3,correct_map) == true)
			{
				
				return correct_map;
			}
		}
		else
		{
			// std::cout << "Failing at recursive call" << std::endl;
			PuzzleSolve(k-1, S, new_set, Uniq_list, s1,s2,s3);
		}
		S.pop_back();
		new_set.push_back(elem);
		// std::cout << "Failing at end of for loop" << std::endl;
	}
	std::map<char,unsigned> no_result;
	return no_result;
}



// bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::map<char, unsigned> & mapping)
// {
// 	std::set<char> perms;

// 			// **Question**  should the set of unique characters include the result of summation (should BIB be included in the permutations) :
// 	std::string concat_strings = s1 + s2 + s3;
// 	for (unsigned int i = 0; i<concat_strings.length(); ++i)
// 	{
// 		perms.insert(concat_strings[i]);
// 	}

// 	unsigned int len_of_set = 0;
// 	std::vector<char> Uniques;
	
// 	// creating a vector of unique letters of all 3 strings
// 	for (auto it = perms.begin(); it != perms.end(); ++it)
// 	{
// 		// std::cout << *it << std::endl;
// 		len_of_set += 1;
// 		Uniques.push_back(*it);
// 	}
// 	const unsigned int size_k = Uniques.size();
	
// 			// **Question** Am I supposed to pass in the list/len of lhs of the permutations (EX: POT + PAN = BIB and me passing set of {POTAN} only)
// 	bool a = PuzzleSolve(size_k, "", Uniques,s1,s2,s3);

// 	return a;
// }

// bool PuzzleSolve(unsigned int k, std::string S, std::vector<char> U, std::string s1, std::string s2, std::string s3)
// {
// 	// k is the length of set U
// 	auto new_set = U;
// 	for (auto it = U.begin(); it != U.end(); ++it)
// 	{
// 		S += *it;  // add the letter from Set to the empty string
// 		new_set.erase(std::remove(new_set.begin(), new_set.end(), *it), new_set.end()); // source : https://stackoverflow.com/questions/39912/how-do-i-remove-an-item-from-a-stl-vector-with-a-certain-value

// 		// std::map<char,unsigned> potential_map;
// 		// for (unsigned int i =0; i<S.length();++i)
// 		// {
// 		// 	// std::cout << S << std::endl;
// 		// 	potential_map.insert(std::pair<char,unsigned>(S[i],i));
// 		// }
// 		// potential_map.insert(std::pair<char,unsigned>(U[0],S.length()));

// 		if (k == 1)
// 		{
// 			/* make a  map of character numbers by iterating thru S and giving the value
// 			the index i. Then after creating the map, give the proj0 code following:
// 					proj0code(S,U,S+U,map_I_created) */
			
// 			std::map<char,unsigned> potential_map;
// 			for (unsigned int i =0; i<S.length();++i)
// 			{
// 				// std::cout << S << std::endl;
// 				potential_map.insert(std::pair<char,unsigned>(S[i],i));
// 			}
// 			potential_map.insert(std::pair<char,unsigned>(U[0],S.length()));
			
// 			// for (auto elem:potential_map)
// 			// {
			
// 			// std::cout << elem.first << "  " << elem.second << std::endl;
			
// 			// }

			
// 			// std::cout << S << std::endl;
// 			if (verifySolution(s1,s2,s3, potential_map) == true)
// 			{
// 				std::cout << "Please Please" <<  std::endl;
// 				return true;
// 			}
// 		}
// 		else
// 		{
// 			// std::cout << S << std::endl;
// 			PuzzleSolve(k-1,S,new_set,s1,s2, s3);
// 		}
// 		char temp = S.back();
// 		S.pop_back();
// 		new_set.push_back(temp);
		
// 	}
// 	return false;
// }


