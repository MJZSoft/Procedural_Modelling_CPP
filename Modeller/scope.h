#ifndef SCOPE_H
#define SCOPE_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

class Scope
{
  public:
	  Scope(std::string name, std::vector<float> position, float sx, float sy, float sz);
	  std::string get_name();
	  std::vector<float> get_position();
    void set_position(std::vector<float> new_position);
    float get_sx();
    float get_sy();
    float get_sz();
    void set_sx(float sx);
    void set_sy(float sy);
    void set_sz(float sz);
    float get_x_rot();
    float get_y_rot();
    float get_z_rot();
    void set_x_rot(float x_rot);
    void set_y_rot(float y_rot);
    void set_z_rot(float z_rot);
    float get_r_col();
    float get_g_col();
    float get_b_col();
    void set_r_col(float r_col);
    void set_g_col(float g_col);
    void set_b_col(float b_col);
    bool meets_condition(std::string condition, std::map<std::string, std::vector<Scope> > active_scopes);
  private:
    float max_x();
    float max_y();
    float max_z();
    float min_x();
    float min_y();
    float min_z();
	  float sx; // side length in x direction
	  float sy; // side length in y direction
	  float sz; // side length in z direction
    float x_rot; // rotation in x direction
    float y_rot; // rotation in y direction
    float z_rot; // rotation in z direction
    float r_col; // r color value
    float g_col; // g color value
    float b_col; // b color value
	  std::vector<float> position; // needs x,y and z coordinate
    std::string name; // stores the type of the object i.e. cube, cylinder, roof
};

#endif
