#ifndef MODELLING_H
#define MODELLING_H

#include "scope.h"
#include "command.h"
#include "Shape.h"
#include "time.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

class Modeller {
  public:
	  Modeller(std::vector<std::string> tokens);
    void model();
    std::vector<std::vector<Shape> > get_leaf_shapes_in_all_levels();
    std::vector<Shape> get_final_shapes();
    std::vector<std::vector<Shape> > get_drawable_tree();
    void print_final_shapes();
  private:
    std::vector<dt_level_type> derivation_tree;
    std::vector<std::string> tokens;
    void apply_rule(std::string predecessor, std::vector<std::vector<Command> > commands_for_scopes, std::string condition="");
    std::vector<double> compute_probabilities(std::vector<std::string> numbers);
    std::vector<std::string> create_test_tokens();
    Shape create_shape(Scope scope);
    std::vector<Shape> create_shapes(std::vector<Scope> scopes);
};

#endif
