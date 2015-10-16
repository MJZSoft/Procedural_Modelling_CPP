#ifndef COMMAND_H
#define COMMAND_H
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <cstdlib>
#include <string.h>
#include "scope.h"

typedef std::map<std::string, std::vector<Scope> > dt_level_type;

#define PI float(M_PI)

class Command
{
  public:
    // hardcode different branches in the run section for different ids (see .cpp file)
    void run(Scope& predecessor, dt_level_type& shapes_for_new_level);
    Command(std::string id, std::vector<std::string> arguments, std::vector<std::string> output_symbols);

  private:
    std::string id;
    std::vector<std::string> arguments;
    std::vector<std::string> output_symbols;
    bool is_rel(std::string value);
    bool is_abs(std::string value);
    // converts a list of relative and absolute arguments into absolute values according to a reference value
    std::vector<float> convert_into_abs(std::vector<std::string> arguments, float reference=0);
    static void collect_scopes_for_level(dt_level_type& scopes_for_level, std::string symbol, Scope scope);
    std::vector<float> compute_new_position(int axis, std::vector<float> ref_pos, float distance, float rot_x, float rot_y, float rot_z);
};

#endif
