#include "aabb.hpp"
aabb::aabb(double x, double y, double width, double height): x(x), y(y), width(width), height(height) 
{}

bool aabb::check_aabb_collision(aabb box_other) {
    if (this->x < box_other.get_x() + box_other.get_width() &&
        this->x + this->width > box_other.get_x() &&
        this->y < box_other.get_y() + box_other.get_height() &&
        this->height + this->y > box_other.get_y())
        return true;
    return false;    
}