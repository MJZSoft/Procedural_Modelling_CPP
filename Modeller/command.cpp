#include "command.h"

Command::Command(std::string id, std::vector<std::string> arguments, std::vector<std::string> output_symbols)
{
	Command::id = id;
	Command::arguments = arguments;
	Command::output_symbols = output_symbols;
}

bool Command::is_rel(std::string value)
{
  char* end;
  const char* input = value.c_str();
  std::strtod(input, &end);
  if (*input == '\0' || end == input || *end != 'r' || strlen(end)>1)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool Command::is_abs(std::string value)
{
  char* end;
  const char* input = value.c_str();
  std::strtod(input, &end);
  if (*input == '\0' || end == input || *end != '\0')
  {
    return false;
  }
  else
  {
    return true;
  }
}

std::vector<float> Command::convert_into_abs(std::vector<std::string> arguments, float reference)
{
  char* end;
  float value;
  float rel_sum = 0;
  float abs_sum = 0;
  std::vector<int> pos_rel_values;
  std::vector<float> converted;
  for(unsigned int k=0; k<arguments.size(); k++)
  {
    if(Command::is_abs(arguments[k]))
    {
      value = float(std::strtod(arguments[k].c_str(), &end));
      abs_sum += value;
      converted.push_back(value);
    }
    else if(Command::is_rel(arguments[k]))
    {
      value = float(std::strtod(arguments[k].c_str(), &end));
      rel_sum += value;
      pos_rel_values.push_back(k);
      converted.push_back(value);
    }
    else
    {
      std::cout << "Error: argument " << k+1 << " is corrupted!" << std::endl;
      converted.push_back(-1);
    }
  }
  for(std::vector<int>::iterator it1=pos_rel_values.begin(); it1!=pos_rel_values.end(); ++it1)
  {
    converted[*it1] = converted[*it1]*(reference-abs_sum)/rel_sum;
  }
  return converted;
}

void Command::run(Scope& predecessor, dt_level_type& scopes_for_new_level)
{
	if(id == "SUBDIV")
	{
    // sanity checks
    if(Command::arguments.size() <= 2)
    {
      std::cout << "Error: wrong number of arguments within a 'SUBDIV' command!" << std::endl;
    }
    else if(Command::arguments.size() != Command::output_symbols.size()+1)
    {
      std::cout << "Error: number of arguments does not equal the number of output Scopes within a 'SUBDIV' command!" << std::endl;
    }
    else
    {
      // get axis
      std::string axis = Command::arguments[0];
      if(axis != "X" && axis != "Y" && axis != "Z")
      {
        std::cout << "Error: axis not specified correctly within a 'SUBDIV' command!" << std::endl;
      }
      // get sizes for the new Scopes
      std::vector<std::string> convert_this = Command::arguments;
      convert_this.erase(convert_this.begin());
      // create new Scopes
      std::vector<float> ref_pos = predecessor.get_position();
      float sx = predecessor.get_sx();
      float sy = predecessor.get_sy();
      float sz = predecessor.get_sz();
      float x_rot = predecessor.get_x_rot();
      float y_rot = predecessor.get_y_rot();
      float z_rot = predecessor.get_z_rot();
      float distance = 0.0;
      float step;
      for(unsigned int sh=1; sh<=Command::output_symbols.size(); sh++)
      {
        if(axis == "X")
        {
          std::vector<float> sizes = Command::convert_into_abs(convert_this,predecessor.get_sx());
          step = sizes[sh-1];
          Scope new_scope("__<<#scope",Command::compute_new_position(0,ref_pos,distance,x_rot,y_rot,z_rot),step,sy,sz);
          new_scope.set_x_rot(x_rot);
          new_scope.set_y_rot(y_rot);
          new_scope.set_z_rot(z_rot);
          new_scope.set_r_col(predecessor.get_r_col());
          new_scope.set_g_col(predecessor.get_g_col());
          new_scope.set_b_col(predecessor.get_b_col());
          Command::collect_scopes_for_level(scopes_for_new_level, Command::output_symbols[sh-1],new_scope);
          distance += step;
        }
        else if(axis == "Y")
        {
          std::vector<float> sizes = Command::convert_into_abs(convert_this,predecessor.get_sy());
          step = sizes[sh-1];
          Scope new_scope("__<<#scope",Command::compute_new_position(1,ref_pos,distance,x_rot,y_rot,z_rot),sx,step,sz);
          new_scope.set_x_rot(x_rot);
          new_scope.set_y_rot(y_rot);
          new_scope.set_z_rot(z_rot);
          new_scope.set_r_col(predecessor.get_r_col());
          new_scope.set_g_col(predecessor.get_g_col());
          new_scope.set_b_col(predecessor.get_b_col());
          Command::collect_scopes_for_level(scopes_for_new_level, Command::output_symbols[sh-1],new_scope);
          distance += step;
        }
        else if(axis == "Z")
        {
          std::vector<float> sizes = Command::convert_into_abs(convert_this,predecessor.get_sz());
          step = sizes[sh-1];
          Scope new_scope("__<<#scope",Command::compute_new_position(2,ref_pos,distance,x_rot,y_rot,z_rot),sx,sy,step);
          new_scope.set_x_rot(x_rot);
          new_scope.set_y_rot(y_rot);
          new_scope.set_z_rot(z_rot);
          new_scope.set_r_col(predecessor.get_r_col());
          new_scope.set_g_col(predecessor.get_g_col());
          new_scope.set_b_col(predecessor.get_b_col());
          Command::collect_scopes_for_level(scopes_for_new_level, Command::output_symbols[sh-1],new_scope);
          distance += step;
        }
      }
    }
	}
	else if(id == "REPEAT")
	{
    // sanity checks
    if(Command::arguments.size() != 2)
    {
      std::cout << "Error: wrong number of arguments within a 'REPEAT' command!" << std::endl;
    }
    else if(Command::output_symbols.size() > 1)
    {
      std::cout << "Error: more than one output id given within a 'REPEAT' command!" << std::endl;
    }
    else
    {
      // get axis
      std::string axis = Command::arguments[0];
      if(axis != "X" && axis != "Y" && axis != "Z")
      {
        std::cout << "Error: axis not specified correctly within a 'REPEAT' command!" << std::endl;
      }
      else
      {
        // get reference
        float reference;
        float sx = predecessor.get_sx();
        float sy = predecessor.get_sy();
        float sz = predecessor.get_sz();
        float x_rot = predecessor.get_x_rot();
        float y_rot = predecessor.get_y_rot();
        float z_rot = predecessor.get_z_rot();
        if(axis == "X")
        {
          reference = sx;
        }
        else if(axis == "Y")
        {
          reference = sy;
        }
        else
        {
          reference = sz;
        }
        // compute number of repetitions
        std::vector<std::string> convert_this;
        convert_this.push_back(arguments[1]);
        float num_tilings = Command::convert_into_abs(convert_this)[0];
        float repetitions = ceil(reference/num_tilings);
        // create Scopes
        std::vector<float> ref_pos = predecessor.get_position();
        float distance = 0.0;
        if(axis == "X")
        {
          float new_size = sx/repetitions;
          for(unsigned int k=0; k<repetitions; k++)
          {
            Scope new_scope("__<<#scope",Command::compute_new_position(0,ref_pos,distance,x_rot,y_rot,z_rot),new_size,sy,sz);
            new_scope.set_x_rot(x_rot);
            new_scope.set_y_rot(y_rot);
            new_scope.set_z_rot(z_rot);
            new_scope.set_r_col(predecessor.get_r_col());
            new_scope.set_g_col(predecessor.get_g_col());
            new_scope.set_b_col(predecessor.get_b_col());
            Command::collect_scopes_for_level(scopes_for_new_level, Command::output_symbols[0],new_scope);
            distance += new_size;
          }
        }
        else if(axis == "Y")
        {
          float new_size = sy/repetitions;
          for(unsigned int k=0; k<repetitions; k++)
          {
            Scope new_scope("__<<#scope",Command::compute_new_position(1,ref_pos,distance,x_rot,y_rot,z_rot),sx,new_size,sz);
            new_scope.set_x_rot(x_rot);
            new_scope.set_y_rot(y_rot);
            new_scope.set_z_rot(z_rot);
            new_scope.set_r_col(predecessor.get_r_col());
            new_scope.set_g_col(predecessor.get_g_col());
            new_scope.set_b_col(predecessor.get_b_col());
            Command::collect_scopes_for_level(scopes_for_new_level, Command::output_symbols[0],new_scope);
            distance += new_size;
          }
        }
        else
        {
          float new_size = sz/repetitions;
          for(unsigned int k=0; k<repetitions; k++)
          {
            Scope new_scope("__<<#scope",Command::compute_new_position(2,ref_pos,distance,x_rot,y_rot,z_rot),sx,sy,new_size);
            new_scope.set_x_rot(x_rot);
            new_scope.set_y_rot(y_rot);
            new_scope.set_z_rot(z_rot);
            new_scope.set_r_col(predecessor.get_r_col());
            new_scope.set_g_col(predecessor.get_g_col());
            new_scope.set_b_col(predecessor.get_b_col());
            Command::collect_scopes_for_level(scopes_for_new_level, Command::output_symbols[0],new_scope);
            distance += new_size;
          }
        }
      }
    }
	}
	else if(id == "SIZEV")
	{
    // sanity checks
    if(Command::arguments.size() != 3)
    {
      std::cout << "Error: wrong number of arguments within a 'SIZE' command!" << std::endl;
    }
    else
    {
      std::vector<float> new_size = Command::convert_into_abs(Command::arguments);
      predecessor.set_sx(new_size[0]);
      predecessor.set_sy(new_size[1]);
      predecessor.set_sz(new_size[2]);
    }
	}
	else if(id == "TRANSLATE")
	{
    // sanity checks
    if(Command::arguments.size() != 3)
    {
      std::cout << "Error: wrong number of arguments within a 'TRANSLATE' command!" << std::endl;
    }
    else
    {
      predecessor.set_position(Command::convert_into_abs(Command::arguments));
    }
	}
	else if(id == "ROTATEX")
	{
    // sanity checks
    if(Command::arguments.size() != 1)
    {
      std::cout << "Error: wrong number of arguments within a 'ROTATEX' command!" << std::endl;
    }
    else
    {
      predecessor.set_x_rot(Command::convert_into_abs(Command::arguments)[0]);
    }
	}
	else if(id == "ROTATEY")
	{
    // sanity checks
    if(Command::arguments.size() != 1)
    {
      std::cout << "Error: wrong number of arguments within a 'ROTATEY' command!" << std::endl;
    }
    else
    {
      predecessor.set_y_rot(Command::convert_into_abs(Command::arguments)[0]);
    }
	}
	else if(id == "ROTATEZ")
	{
    // sanity checks
    if(Command::arguments.size() != 1)
    {
      std::cout << "Error: wrong number of arguments within a 'ROTATEZ' command!" << std::endl;
    }
    else
    {
      predecessor.set_z_rot(Command::convert_into_abs(Command::arguments)[0]);
    }
	}
  else if(id == "INSTANCE")
  {
    // sanity checks
    if(Command::arguments.size() != 1)
    {
      std::cout << "Error: wrong number of arguments within a 'INSTANCE' command!" << std::endl;
    }
    else
    {
      Scope instance(Scope(Command::arguments[0], predecessor.get_position(), predecessor.get_sx(), predecessor.get_sy(), predecessor.get_sz()));
      instance.set_x_rot(predecessor.get_x_rot());
      instance.set_y_rot(predecessor.get_y_rot());
      instance.set_z_rot(predecessor.get_z_rot());
      instance.set_r_col(predecessor.get_r_col());
      instance.set_g_col(predecessor.get_g_col());
      instance.set_b_col(predecessor.get_b_col());
      Command::collect_scopes_for_level(scopes_for_new_level, "leaf", instance);
    }
  }
  else if(id == "COLOR")
  {
    // sanity checks
    if(Command::arguments.size() != 3)
    {
      std::cout << "Error: wrong number of arguments within a 'COLOR' command!" << std::endl;
    }
    else
    {
      std::vector<float> new_color = Command::convert_into_abs(Command::arguments);
      predecessor.set_r_col(new_color[0]);
      predecessor.set_g_col(new_color[1]);
      predecessor.set_b_col(new_color[2]);
    }
  }
  else if(id == "COMP")
  {
    // sanity checks
    if(Command::arguments.size() != 1)
    {
      std::cout << "Error: wrong number of arguments within a 'COMP' command!" << std::endl;
    }
    else if(Command::output_symbols.size() != 1)
    {
      std::cout << "Error: not exactly one output shape within a 'COMP' command!" << std::endl;
    }
    else
    {
      // create faces
      std::string face_idx = Command::arguments[0];
      std::vector<Scope> faces;
      std::vector<float> pos = predecessor.get_position();
      std::string name = predecessor.get_name();
      float sx = predecessor.get_sx();
      float sy = predecessor.get_sy();
      float sz = predecessor.get_sz();
      float x_rot = predecessor.get_x_rot();
      float y_rot = predecessor.get_y_rot();
      float z_rot = predecessor.get_z_rot();
      if(face_idx == "TOP")
      {
        faces.push_back(Scope("__<<#scope",Command::compute_new_position(1, pos, sy, x_rot, y_rot, z_rot),sx,0.0f,sz));
      }
      else if(face_idx == "BOTTOM")
      {
        faces.push_back(Scope("__<<#scope",pos,sx,0.0f,sz));
      }
      else if(face_idx == "LEFT")
      {
        faces.push_back(Scope("__<<#scope",pos,0.0f,sy,sz));
      }
      else if(face_idx == "RIGHT")
      {
        faces.push_back(Scope("__<<#scope",Command::compute_new_position(0, pos, sx, x_rot, y_rot, z_rot),0.0f,sy,sz));
      }
      else if(face_idx == "FRONT")
      {
        faces.push_back(Scope("__<<#scope",pos,sx,sy,0.0f));
      }
      else if(face_idx == "BACK")
      {
        faces.push_back(Scope("__<<#scope",Command::compute_new_position(2, pos, sz, x_rot, y_rot, z_rot),sx,sy,0.0f));
      }
      else if(face_idx == "ALL")
      {
        faces.push_back(Scope("__<<#scope",Command::compute_new_position(1, pos, sy, x_rot, y_rot, z_rot),sx,0.0f,sz));
        faces.push_back(Scope("__<<#scope",pos,sx,0.0f,sz));
        faces.push_back(Scope("__<<#scope",pos,0.0f,sy,sz));
        faces.push_back(Scope("__<<#scope",Command::compute_new_position(0, pos, sx, x_rot, y_rot, z_rot),0.0f,sy,sz));
        faces.push_back(Scope("__<<#scope",pos,sx,sy,0.0f));
        faces.push_back(Scope("__<<#scope",Command::compute_new_position(2, pos, sz, x_rot, y_rot, z_rot),sx,sy,0.0f));
      }
      // create scopes for faces
      for(std::vector<Scope>::iterator it1=faces.begin(); it1!=faces.end(); ++it1)
      {
        it1->set_x_rot(x_rot);
        it1->set_y_rot(y_rot);
        it1->set_z_rot(z_rot);
        it1->set_r_col(predecessor.get_r_col());
        it1->set_g_col(predecessor.get_g_col());
        it1->set_b_col(predecessor.get_b_col());
        Command::collect_scopes_for_level(scopes_for_new_level, Command::output_symbols[0],*it1);
      }
    }
  }
	else
	{
		std::cout << "Error: ID does not exist" << std::endl;
	}
}

void Command::collect_scopes_for_level(dt_level_type& scopes_for_level, std::string symbol, Scope scope) {
  if (scopes_for_level.count(symbol) == 0) {
    std::vector<Scope> scopes;
    scopes.push_back(scope);
    scopes_for_level.insert(std::pair<std::string, std::vector<Scope> >(symbol, scopes));
  } else {
    scopes_for_level.at(symbol).push_back(scope);
  }
}

std::vector<float> Command::compute_new_position(int axis, std::vector<float> ref_pos, float distance, float rot_x, float rot_y, float rot_z)
{
  std::vector<float> new_position;
  new_position.push_back(0);
  new_position.push_back(0);
  new_position.push_back(0);
  if(axis >= 0 && axis <= 2)
  {
    new_position[axis] = distance; // init position in reference coordinate system
    // x rotation
    new_position[1] = new_position[1]*cosf(rot_x*PI/180.0f)-new_position[2]*sinf(rot_x*PI/180.0f);
    new_position[2] = new_position[1]*sinf(rot_x*PI/180.0f)+new_position[2]*cosf(rot_x*PI/180.0f);
    // y rotation
    new_position[0] = new_position[0]*cosf(rot_y*PI/180.0f)+new_position[2]*sinf(rot_y*PI/180.0f);
    new_position[2] = -new_position[0]*sinf(rot_y*PI/180.0f)+new_position[2]*cosf(rot_y*PI/180.0f);
    // z rotation
    new_position[0] = new_position[0]*cosf(rot_z*PI/180.0f)-new_position[1]*sinf(rot_z*PI/180.0f);
    new_position[1] = new_position[0]*sinf(rot_z*PI/180.0f)+new_position[1]*cosf(rot_z*PI/180.0f);
  }
  else
  {
    std::cout << "Error: Axis must be between 0 and 2!" << std::endl;
  }
  // shift coordinate system back to global one
  for(int j=0; j<3; j++)
  {
    new_position[j] += ref_pos[j];
  }
  return new_position;
}
