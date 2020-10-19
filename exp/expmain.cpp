// expmain.cpp
//
// Do whatever you'd like here.  This is intended to allow you to experiment
// with the code in the "app" directory or with any additional libraries
// that are part of the project, outside of the context of the main
// application or Google Test.

#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    std::string s1 = "bc";
    std::string s2 = "a";
    std::string s3 = "abc";

    std::string concat_st = s1 + s2;
    
    std::cout << concat_st << "  " << s3 << std::endl;
    // if (concat_st == s3)
    // {
    //     std::cout << "true bitch" << std::endl;
    // }
    
    std::string sorted_word1 = concat_st;
    std::string sorted_word2 = s3;
    std::sort(sorted_word1.begin(), sorted_word1.end());
    std::sort(sorted_word2.begin(), sorted_word2.end());

    std::cout << sorted_word1 << "  " << sorted_word2 << std::endl;
    return 0;
}

