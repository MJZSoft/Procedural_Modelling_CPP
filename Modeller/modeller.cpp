#include "modeller.h"

Modeller::Modeller(std::vector<std::string> tokens)
{
  // hardcoded axiom
  std::vector<float> position;
  position.push_back(0);
  position.push_back(0);
  position.push_back(0);
  Scope axiom_scope("axiom" , position , 0 , 0 , 0);
  std::vector<Scope> axiom;
  axiom.push_back(axiom_scope);
  dt_level_type first_level;
  first_level["axiom"] = axiom;
  Modeller::derivation_tree.push_back(first_level);
  // if the handled tokens are empty, we will use the test tokens
  if(tokens.size()>0)
  {
    this->tokens = tokens;
  }
  else
  {
    this->tokens = Modeller::create_test_tokens();
  }
}

void Modeller::model()
{
  srand(time(NULL)); // random seed
  std::vector<std::vector<Command> > commands_for_scopes;
  std::vector<std::string>::iterator it1 = tokens.begin();
  // initialize variables used for rule creation
  int id;
  std::vector<std::string> probability_strings;
  std::vector<std::vector<Command> > commands_with_probabilities;
  std::string pred_symb;
  std::string cmd_id;
  std::string rel_arg;
  std::vector<Command> commands;
  std::vector<std::string> output_symbols;
  std::vector<std::string> arguments;
  int bracket_count;
  while(it1!=tokens.end())
  {
    // find beginning of a rule
    if(*it1 == "ID")
    {
      ++it1;
      ++it1; // bracket
      id = atoi(it1->c_str());
      ++it1;
      ++it1; // bracket
      ++it1; // colon
      while(*it1 != "ENDR")
      {
        // find predecessor
        if(*it1 == "SHAPE")
        {
          ++it1;
          ++it1; // bracket
          pred_symb = *it1;
          ++it1;
        }
        // extract commands
        else if(*it1=="SUBDIV" || *it1=="REPEAT" || *it1=="SIZEV" || *it1=="TRANSLATE" || *it1=="ROTATEX"
          || *it1=="ROTATEY" || *it1=="ROTATEZ" || *it1=="INSTANCE" || *it1=="COLOR" || *it1=="COMP")
        {
          cmd_id = *it1;
          ++it1;
          ++it1; // bracket
          bracket_count = 1;
          while(bracket_count != 0)
          {
            if(*it1 == "(")
            {
              bracket_count++;
            }
            else if(*it1 == ")")
            {
              bracket_count--;
            }
            else if(*it1 == "RELATIVE")
            {
              ++it1;
              ++it1; // bracket
              rel_arg = *it1;
              rel_arg.push_back('r');
              arguments.push_back(rel_arg);
              ++it1; // bracket
            }
            else if(*it1 != "SIZES" && *it1 != ",")
            {
              arguments.push_back(*it1);
            }
            ++it1;
          }
          // find output symbols
          if(*it1 == "{")
          {
            ++it1; // the bracket
            while(*it1 != "}")
            {
              if(*it1 != "|")
              {
                output_symbols.push_back(*it1);
              }
              ++it1;
            }
          }
          commands.push_back(Command(cmd_id, arguments, output_symbols));
          // clear variables
          arguments.clear();
          output_symbols.clear();
        }
        else if(*it1=="PROBABILITY")
        {
          ++it1;
          ++it1; // bracket
          probability_strings.push_back(*it1);
          commands_with_probabilities.push_back(commands);
          commands.clear();
          ++it1;
        }
        else
        {
          ++it1; // string is not important
        }
      }
      // find random rule according to given probabilities
      dt_level_type scopes_for_latest_level = derivation_tree.back();
      if (scopes_for_latest_level.count(pred_symb) > 0) {
        if(probability_strings.size()>0)
        {
          std::vector<double> probabilities = compute_probabilities(probability_strings);
	  probability_strings.clear();
          for(unsigned int n=0; n<scopes_for_latest_level.at(pred_symb).size(); n++)
          {
            double prob = (double)rand()/RAND_MAX; // compute a random number
            double prob_area = 0;
            int k=-1;
            while(prob_area<prob)
            {
              k++;
              prob_area += probabilities[k];
            }
            commands_for_scopes.push_back(commands_with_probabilities[k]);
          }
	  commands_with_probabilities.clear();
        }
        else
        {
          for(unsigned int n=0; n<scopes_for_latest_level.at(pred_symb).size(); n++)
          {
            commands_for_scopes.push_back(commands);
          }
        }
      }
      Modeller::apply_rule(pred_symb, commands_for_scopes);
      commands.clear();
      commands_for_scopes.clear();
    }
    ++it1;
  }
}

std::vector<std::vector<Shape> > Modeller::get_leaf_shapes_in_all_levels() {
  std::vector<std::vector<Shape> > shapes;
  for (unsigned int i = 0; i < derivation_tree.size(); i++) {
    std::vector<Shape> shapes_for_level;
    dt_level_type::iterator it = derivation_tree[i].find("leaf");
    if (it != derivation_tree[i].end()) {
      for (unsigned int j = 0; j < it->second.size(); j++) {
        shapes_for_level.push_back(create_shape(it->second[j]));
      }
    }
    shapes.push_back(shapes_for_level);
  }
  return shapes;
}

std::vector<std::vector<Shape> > Modeller::get_drawable_tree()
{
  std::vector<std::vector<Shape> > shapes;
  std::vector<Shape> shapes_for_level;
  for (unsigned int i = 0; i < derivation_tree.size(); i++)
  {
    for (dt_level_type::iterator it1 = derivation_tree[i].begin(); it1!=derivation_tree[i].end(); ++it1)
    {
      for (std::vector<Scope>::iterator it2=it1->second.begin(); it2!=it1->second.end(); ++it2)
      shapes_for_level.push_back(create_shape(*it2));
    }
    shapes.push_back(shapes_for_level);
    shapes_for_level.clear();
  }
  return shapes;
}

std::vector<Shape> Modeller::get_final_shapes() {
  return Modeller::get_leaf_shapes_in_all_levels().back();
}

void Modeller::apply_rule(std::string predecessor, std::vector<std::vector<Command> > commands_for_scopes, std::string condition) {
  dt_level_type scopes_for_new_level;
  dt_level_type scopes_for_latest_level = derivation_tree.back();

  // preserve the scopes from the latest level that won't be modified by this rule
  for (dt_level_type::iterator it = scopes_for_latest_level.begin(); it != scopes_for_latest_level.end(); it++) {
    if (it->first != predecessor) {
      scopes_for_new_level.insert(std::pair<std::string, std::vector<Scope> >(it->first, it->second));
    }
  }

  if(scopes_for_latest_level.count(predecessor) > 0)
  {
    std::vector<Scope> scopes = scopes_for_latest_level.at(predecessor);
    for (unsigned int i = 0; i < scopes.size(); i++) {
      if (condition == "" || scopes[i].meets_condition(condition, scopes_for_new_level)) {
        for (unsigned int j = 0; j < commands_for_scopes[i].size(); j++) {
          commands_for_scopes[i][j].run(scopes[i], scopes_for_new_level);
        }
      }
    }
  }

  derivation_tree.push_back(scopes_for_new_level);
}

std::vector<double> Modeller::compute_probabilities(std::vector<std::string> numbers)
{
  // convert into double
  char* end;
  std::vector<double> converted;
  for(std::vector<std::string>::iterator it1=numbers.begin(); it1!=numbers.end(); ++it1)
  {
    converted.push_back(std::strtod((*it1).c_str(), &end));
  }
  // compute sum
  double sum = 0;
  for(std::vector<double>::iterator it1=converted.begin(); it1!=converted.end(); ++it1)
  {
    sum+=*it1;
  }
  // normalize
  std::vector<double> probabilities;
  for(std::vector<double>::iterator it1=converted.begin(); it1!=converted.end(); ++it1)
  {
    probabilities.push_back((*it1)/sum);
  }
  return probabilities;
}

std::vector<std::string> Modeller::create_test_tokens()
{
  std::vector<std::string> tokens;
  tokens.push_back("BEGIN");
  tokens.push_back("ID");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(")");
  tokens.push_back(":");
  tokens.push_back("SHAPE");
  tokens.push_back("(");
  tokens.push_back("axiom");
  tokens.push_back(")");
  tokens.push_back("ARROW");
  tokens.push_back("#");
  // rotate
  tokens.push_back("ROTATEY");
  tokens.push_back("(");
  tokens.push_back("90");
  tokens.push_back(")");
  // change size
  tokens.push_back("SIZEV");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("4");
  tokens.push_back(",");
  tokens.push_back("10");
  tokens.push_back(")");
  // divide into 4 scopes along the z axis
  tokens.push_back("SUBDIV");
  tokens.push_back("(");
  tokens.push_back("Z");
  tokens.push_back(",");
  tokens.push_back("SIZES");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("2");
  tokens.push_back(",");
  tokens.push_back("3");
  tokens.push_back(",");
  tokens.push_back("4");
  tokens.push_back(")");
  tokens.push_back(")");
  tokens.push_back("{");
  tokens.push_back("first");
  tokens.push_back("|");
  tokens.push_back("second");
  tokens.push_back("|");
  tokens.push_back("third");
  tokens.push_back("|");
  tokens.push_back("fourth");
  tokens.push_back("}");
  tokens.push_back("$");
  tokens.push_back("ENDR");

  tokens.push_back("ID");
  tokens.push_back("(");
  tokens.push_back("2");
  tokens.push_back(")");
  tokens.push_back(":");
  tokens.push_back("SHAPE");
  tokens.push_back("(");
  tokens.push_back("first");
  tokens.push_back(")");
  tokens.push_back("ARROW");
  tokens.push_back("#");
  // change size
  tokens.push_back("SIZEV");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("1");
  tokens.push_back(")");
  // change color to red
  tokens.push_back("COLOR");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("0");
  tokens.push_back(",");
  tokens.push_back("0");
  tokens.push_back(")");
  // create cube
  tokens.push_back("INSTANCE");
  tokens.push_back("(");
  tokens.push_back("CUBE");
  tokens.push_back(")");
  tokens.push_back("$");
  tokens.push_back("ENDR");
  
  tokens.push_back("ID");
  tokens.push_back("(");
  tokens.push_back("3");
  tokens.push_back(")");
  tokens.push_back(":");
  tokens.push_back("SHAPE");
  tokens.push_back("(");
  tokens.push_back("second");
  tokens.push_back(")");
  tokens.push_back("ARROW");
  tokens.push_back("#");
  // change size
  tokens.push_back("SIZEV");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("2");
  tokens.push_back(",");
  tokens.push_back("2");
  tokens.push_back(")");
  // change color to orange
  tokens.push_back("COLOR");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("0.5");
  tokens.push_back(",");
  tokens.push_back("0");
  tokens.push_back(")");
  // create cube
  tokens.push_back("INSTANCE");
  tokens.push_back("(");
  tokens.push_back("CUBE");
  tokens.push_back(")");
  tokens.push_back("$");
  tokens.push_back("ENDR");

  tokens.push_back("ID");
  tokens.push_back("(");
  tokens.push_back("4");
  tokens.push_back(")");
  tokens.push_back(":");
  tokens.push_back("SHAPE");
  tokens.push_back("(");
  tokens.push_back("third");
  tokens.push_back(")");
  tokens.push_back("ARROW");
  tokens.push_back("#");
  // change size
  tokens.push_back("SIZEV");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("3");
  tokens.push_back(",");
  tokens.push_back("3");
  tokens.push_back(")");
  // change color to green
  tokens.push_back("COLOR");
  tokens.push_back("(");
  tokens.push_back("0.5");
  tokens.push_back(",");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("0");
  tokens.push_back(")");
  // create cube
  tokens.push_back("INSTANCE");
  tokens.push_back("(");
  tokens.push_back("CUBE");
  tokens.push_back(")");
  tokens.push_back("$");
  tokens.push_back("ENDR");

  tokens.push_back("ID");
  tokens.push_back("(");
  tokens.push_back("5");
  tokens.push_back(")");
  tokens.push_back(":");
  tokens.push_back("SHAPE");
  tokens.push_back("(");
  tokens.push_back("fourth");
  tokens.push_back(")");
  tokens.push_back("ARROW");
  tokens.push_back("#");
  // change size
  tokens.push_back("SIZEV");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("4");
  tokens.push_back(",");
  tokens.push_back("4");
  tokens.push_back(")");
  // change color to yellow
  tokens.push_back("COLOR");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("0");
  tokens.push_back(")");
  // get faces of the scope
  tokens.push_back("COMP");
  tokens.push_back("(");
  tokens.push_back("ALL");
  tokens.push_back(")");
  tokens.push_back("{");
  tokens.push_back("face");
  tokens.push_back("}");
  tokens.push_back("$");
  tokens.push_back("ENDR");

  tokens.push_back("ID");
  tokens.push_back("(");
  tokens.push_back("5");
  tokens.push_back(")");
  tokens.push_back(":");
  tokens.push_back("SHAPE");
  tokens.push_back("(");
  tokens.push_back("face");
  tokens.push_back(")");
  tokens.push_back("ARROW");
  tokens.push_back("#");
  // change color to yellow
  tokens.push_back("COLOR");
  tokens.push_back("(");
  tokens.push_back("1");
  tokens.push_back(",");
  tokens.push_back("0");
  tokens.push_back(",");
  tokens.push_back("0.5");
  tokens.push_back(")");
  // create cube
  tokens.push_back("INSTANCE");
  tokens.push_back("(");
  tokens.push_back("CUBE");
  tokens.push_back(")");
  tokens.push_back("$");
  tokens.push_back("ENDR");

  tokens.push_back("END");
  return tokens;
}

Shape Modeller::create_shape(Scope scope)
{
  // initialize shape
  std::vector<float> position = scope.get_position();
	Point* p = new Point(position[0],position[1],-position[2]);
  Shape* shape = new Shape(*p, scope.get_x_rot(), scope.get_y_rot(), scope.get_z_rot());
  Color* color = new Color(scope.get_r_col(), scope.get_g_col(), scope.get_b_col());
  delete p;
  // add visualized component
  if(scope.get_name()=="CUBE" || scope.get_name()=="__<<#scope" || scope.get_name()=="QUAD")
  {
    if(scope.get_sx()==0.0f)
    {
      Point* p1 = new Point(0.0f, 0.0f, 0.0f);
      Point* p2 = new Point(0.0f, 0.0f, -scope.get_sz());
	    Point* p3 = new Point(0.0f, scope.get_sy(), -scope.get_sz());
      Point* p4 = new Point(0.0f, scope.get_sy(), 0.0f);
      Quad* q1 = new Quad(*p1, *p2, *p3, *p4, *color);
      shape->setQuad(q1);
      delete p1;
      delete p2;
      delete p3;
      delete p4;
    }
    else if(scope.get_sy()==0.0f)
    {
      Point* p1 = new Point(0.0f, 0.0f, 0.0f);
      Point* p2 = new Point(0.0f, 0.0f, -scope.get_sz());
	    Point* p3 = new Point(scope.get_sx(), 0.0f, -scope.get_sz());
      Point* p4 = new Point(scope.get_sx(), 0.0f, 0.0f);
      Quad* q1 = new Quad(*p1, *p2, *p3, *p4, *color);
      shape->setQuad(q1);
      delete p1;
      delete p2;
      delete p3;
      delete p4;
    }
    else if(scope.get_sz()==0.0f)
    {
      Point* p1 = new Point(0.0f, 0.0f, 0.0f);
      Point* p2 = new Point(0.0f, scope.get_sy(), 0.0f);
	    Point* p3 = new Point(scope.get_sx(), scope.get_sy(), 0.0f);
      Point* p4 = new Point(scope.get_sx(), 0.0f, 0.0f);
      Quad* q1 = new Quad(*p1, *p2, *p3, *p4, *color);
      shape->setQuad(q1);
      delete p1;
      delete p2;
      delete p3;
      delete p4;
    }
    else
    {
      if(scope.get_name()=="QUAD")
      {
        std::cout << "Warning: A quad is not 2 dimensional! Creating cube instead." << std::endl;
      }
	    Point* p1 = new Point(0.0f, 0.0f, 0.0f);
      Point* p2 = new Point(0.0f, 0.0f, -scope.get_sz());
      Point* p3 = new Point(0.0f, scope.get_sy(), 0.0f);
	    Point* p4 = new Point(0.0f, scope.get_sy(), -scope.get_sz());
	    Point* p5 = new Point(scope.get_sx(), 0.0f, 0.0f);
	    Point* p6 = new Point(scope.get_sx(), 0.0f, -scope.get_sz());
	    Point* p7 = new Point(scope.get_sx(), scope.get_sy(), 0.0f);
	    Point* p8 = new Point(scope.get_sx(), scope.get_sy(), -scope.get_sz());
	    Quad* q1 = new Quad(*p1, *p2, *p4, *p3, *color);
	    Quad* q2 = new Quad(*p5, *p6, *p8, *p7, *color->disturb());
	    Quad* q3 = new Quad(*p4, *p3, *p7, *p8, *color->disturb());
	    Quad* q4 = new Quad(*p1, *p2, *p6, *p5, *color->disturb());
	    Quad* q5 = new Quad(*p3, *p7, *p5, *p1, *color->disturb());
	    Quad* q6 = new Quad(*p4, *p8, *p6, *p2, *color->disturb());
	    Cube* cube = new Cube(*q1, *q2, *q3, *q4, *q5, *q6);
      shape->setCube(cube);
      delete p1;
      delete p2;
      delete p3;
      delete p4;
      delete p5;
      delete p6;
      delete p7;
      delete p8;
      delete q1;
      delete q2;
      delete q3;
      delete q4;
      delete q5;
      delete q6;
    }
  }
  else if(scope.get_name() == "PYRAMID")
  {
    Point* p1 = new Point(scope.get_sx()/2.0f, scope.get_sy(), -scope.get_sz()/2.0f); //top of pyramid
	  Point* p2 = new Point(0.0f, 0.0f, 0.0f);
	  Point* p3 = new Point(0.0f, 0.0f, -scope.get_sz());
	  Point* p4 = new Point(scope.get_sx(), 0.0f, -scope.get_sz());
	  Point* p5 = new Point(scope.get_sx(), 0.0f, 0.0f);
	  Triangle* t1 = new Triangle(*p1, *p2, *p3, *color->disturb());
	  Triangle* t2  = new Triangle(*p1, *p4, *p5, *color->disturb());
	  Triangle* t3  = new Triangle(*p1, *p3, *p4, *color->disturb());
	  Triangle* t4  = new Triangle(*p1, *p2, *p5, *color->disturb());
	  Quad* q1 = new Quad(*p2, *p3, *p4, *p5, *color->disturb());
	  Primed* pyramid = new Primed(*t1, *t2, *t3, *t4, *q1);
	  shape->setPrimed(pyramid);
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete q1;
  }
  else if(scope.get_name() == "CYLINDER")
  {
    float baseRadius = (scope.get_sx()+scope.get_sy())/4.0f; //Specifies the radius of the cylinder at z = 0.
	  float topRadius = (scope.get_sx()+scope.get_sy())/4.0f; //Specifies the radius of the cylinder at z = height.
    float height = scope.get_sz(); //Specifies the height of the cylinder.
	  float slices = std::max(baseRadius, topRadius)*500.0f; //Specifies the number of subdivisions around the z axis.
	  float stacks = 1.0f; //Specifies the number of subdivisions along the z axis
	  //Circle head; // A filled circle to block top of the cylinder (optional)
	  //Circle bottom; // A filled circle to block bottom (base) of the cylinder (optional)
	  Cylinder* cylinder = new Cylinder(baseRadius, topRadius, height, slices, stacks, *color);
	  shape->setCylinder(cylinder);
  }
  else if(scope.get_name() == "CONE")
  {
    float baseRadius = (scope.get_sx()+scope.get_sy())/4.0f; //Specifies the radius of the cylinder at z = 0.
    float height = scope.get_sz(); //Specifies the height of the cylinder.
    float slices = baseRadius*500.0f; //Specifies the number of subdivisions around the z axis.
    float stacks = 1.0f; //Specifies the number of subdivisions along the z axis
    //Circle bottom; // A filled circle to block bottom (base) of the cylinder (optional)
    Cone* cone = new Cone(baseRadius, height, slices, stacks, *color);
    shape->setCone(cone);
  }
  else if(scope.get_name() == "SPHERE")
  {
    Point* center = new Point((position[0] + (position[0] + scope.get_sx()))/2.0f,
        (position[1] + (position[1] + scope.get_sy()))/2.0f,
        -(position[2] + (position[2] + scope.get_sz()))/2.0f);
	  float  radius = (scope.get_sx()+scope.get_sy()+scope.get_sz())/6.0f;
	  float  slices = 100.0f;
	  float  stacks = 100.0f;
	  Sphere* sphere = new Sphere(*center, radius, slices, stacks, *color);
	  shape->setSphere(sphere);
    delete center;
  }
  else if(scope.get_name() != "EMPTY" && scope.get_name() != "axiom")
  {
    std::cout << "Warning: The given shape is not (yet) supported! Creating empty shape." << std::endl;
  }
  delete color;
  return *shape;
}

std::vector<Shape> Modeller::create_shapes(std::vector<Scope> scopes)
{
  std::vector<Shape> shapes;
  for(std::vector<Scope>::iterator it1=scopes.begin(); it1!=scopes.end(); ++it1)
  {
    shapes.push_back(Modeller::create_shape(*it1));
  }
  return shapes;
}

void Modeller::print_final_shapes()
{
  std::vector<Shape> final_shapes = Modeller::get_final_shapes();
  for(std::vector<Shape>::iterator it1= final_shapes.begin(); it1!=final_shapes.end(); ++it1)
  {
    std::cout << it1->to_string() << std::endl;
  }
}
