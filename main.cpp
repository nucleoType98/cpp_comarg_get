
#include "get_argv.hpp"                         // include translation unit

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace MainArgv;

/** Function Pseudocode **/

int main(int argc, char **argv) {


  /** Note that argument list passed in the command line MUST follow this pattern: -command1 -command-2 -commandX -commandY 
  
  vector<std::string> command_line_args;         // destination container for parsed command line arguments
  getArgv(argc, argv, &command_line_args);       // parsing and storing CLAs(command line arguments)

  /** code... **/
  
  return EXIT_SUCCESS;                           // or 0
};
