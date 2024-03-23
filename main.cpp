
#include "get_argv.hpp"                         // include translation unit

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace MainArgv;

/** Function Pseudocode **/

int main(int argc, char **argv) {
  
  vector<std::string> command_line_args;         // destination container for parsed command line arguments
  getArgv(argc, argv, &command_line_args);       // parsing and storing CLAs(command line arguments)

  /** code... **/
  
  return EXIT_SUCCESS;                           // or 0
};
