#pragma once
#ifndef __GLOBAL_ENTRY_ARGV__
#define __GLOBAL_ENTRY_ARGV__ 1
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <strstream>
#include <vector>

namespace MainArgv {

static void getArgv(int argc, char **argv, std::vector<std::string> *inject_target) noexcept try {
  if (argv != nullptr && argc > (int)0 && argc < (int)10) {
    const unsigned short int MX_TKS = (unsigned short int)0x014u; // max 20 iterations
    unsigned short int cnt_x = 0u, cnt_y = 0u, cnt_i = 0u;
    std::vector<char> lookup_lst;
    lookup_lst.push_back(' ');
    lookup_lst.push_back('-');
    std::stringstream put_args;
    std::vector<std::__cxx11::basic_string<char>> vec_res;
    for (cnt_x = 0u; cnt_x < argc; ++cnt_x) {
      size_t index_size = strlen(argv[cnt_x]);
      if (*argv[cnt_x] == lookup_lst[1u]) {
        ++cnt_y;
        put_args << "\"";
        while (cnt_y != index_size && cnt_y <= MX_TKS) {
          if (cnt_y == index_size)
            break;
          put_args << argv[cnt_x][cnt_y];
          ++cnt_y;
        }
        put_args << "\", ";
        cnt_y = 0u;
        ++cnt_i;
      }
    }
    if (put_args.str().length() > 0) {
      std::regex rit_pattern("\"([^\"]*)\"");
      std::string get_put = put_args.str(), result;
      std::string::iterator ptr_beg = get_put.begin(), ptr_end = get_put.end();
      std::sregex_iterator it_beg(ptr_beg, ptr_end, rit_pattern), it_end;
      std::smatch match_extr;
      while (it_beg != it_end) {
        match_extr = *it_beg;
        result = match_extr.str(1);
        printf("Command Argument: %s\n", result.c_str());
        inject_target->push_back(result);
        ++it_beg;
      }
      printf("Registered %ld command arguments...\n", inject_target->size());
    }
  } else {
    std::cout << "No arguments .." << std::endl;
  }
} catch (...) {
  return;
};
}; // namespace MainArgv
#endif