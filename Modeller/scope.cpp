#include "scope.h"

Scope::Scope(std::string name, std::vector<float> position, float sx, float sy, float sz)
{
  Scope::name = name;
  Scope::sx = sx;
  Scope::sy = sy;
  Scope::sz = sz;
  Scope::position = position;
  // initialize with no rotation
  Scope::x_rot = 0.0f;
  Scope::y_rot = 0.0f;
  Scope::z_rot = 0.0f;
  // initialize the color as grey
  Scope::r_col = 0.5f;
  Scope::g_col = 0.5f;
  Scope::b_col = 0.5f;
}

float Scope::max_x() {
  return std::max(position[0], position[0] + sx);
}
float Scope::max_y() {
  return std::max(position[1], position[1] + sy);
}
float Scope::max_z() {
  return std::max(position[2], position[2] + sz);
}
float Scope::min_x() {
  return position[0];
}
float Scope::min_y() {
  return position[1];
}
float Scope::min_z() {
  return position[2];
}

bool Scope::meets_condition(std::string condition, std::map<std::string, std::vector<Scope> > active_scopes) {
  if (condition == "occ == \"none\"") {
	std::map<std::string, std::vector<Scope> >::iterator it = active_scopes.begin();
    bool intersects = false;
    while (!intersects && it != active_scopes.end()) {
      // this assumes the shapes are axis aligned
      unsigned int i = 0;
      while (!intersects && i < it->second.size()) {
        intersects = (it->second[i].max_x() >= min_x() && it->second[i].min_x() <= max_x() &&
                      it->second[i].max_y() >= min_y() && it->second[i].min_y() <= max_y() &&
                      it->second[i].max_z() >= min_z() && it->second[i].min_z() <= max_z());

        i++;
      }
      it++;
    }
    return !intersects;
  } else {
    std::cout << condition << " handling is not implemented" << std::endl;
    return false;
  }
}

std::string Scope::get_name()
{
  return Scope::name;
}

std::vector<float> Scope::get_position()
{
  return Scope::position;
}

void Scope::set_position(std::vector<float> new_position)
{
  Scope::position = new_position;
}

float Scope::get_sx()
{
  return Scope::sx;
}

float Scope::get_sy()
{
  return Scope::sy;
}

float Scope::get_sz()
{
  return Scope::sz;
}

void Scope::set_sx(float sx)
{
  Scope::sx = sx;
}

void Scope::set_sy(float sy)
{
  Scope::sy = sy;
}

void Scope::set_sz(float sz)
{
  Scope::sz = sz;
}

float Scope::get_x_rot()
{
  return Scope::x_rot;
}

float Scope::get_y_rot()
{
  return Scope::y_rot;
}

float Scope::get_z_rot()
{
  return Scope::z_rot;
}

void Scope::set_x_rot(float x_rot)
{
  Scope::x_rot = x_rot;
}

void Scope::set_y_rot(float y_rot)
{
  Scope::y_rot = y_rot;
}

void Scope::set_z_rot(float z_rot)
{
  Scope::z_rot = z_rot;
}

float Scope::get_r_col()
{
  return Scope::r_col;
}

float Scope::get_g_col()
{
  return Scope::g_col;
}

float Scope::get_b_col()
{
  return Scope::b_col;
}

void Scope::set_r_col(float r_col)
{
  Scope::r_col = r_col;
}

void Scope::set_g_col(float g_col)
{
  Scope::g_col = g_col;
}

void Scope::set_b_col(float b_col)
{
  Scope::b_col = b_col;
}
