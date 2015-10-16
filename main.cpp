#include <iostream>
#include <fstream>
#include "Parser/parser.h"
#include "Modeller/modeller.h"
#include "Visualizer/renderer.h"

using namespace std;



int main(int argc, char** argv)
{
  cout<<"Welcome to Group 01 final project."<<endl;
  std::string rule_file = "urbanmodel.zoo";

  // parsing
  Parser parser(rule_file);
  std::vector<std::string> tokens = parser.parse();
  parser.printTokens();

  // modelling
  Modeller modeller(tokens);
  modeller.model();
  vector<Shape> shapes = modeller.get_final_shapes();
 /* for(unsigned int i=0; i<shapes.size();i++)
  {
	  cout<<"##"<<(i+1)<<" ";
	  cout<<shapes.at(i).to_string().c_str();
  }*/
  //visualization
  Renderer r("Group 01 Project", shapes, 1024, 768, true);
  r.render();

  return 1;
}
