#ifndef aabb_hpp
#define aabb_hpp

class aabb
{
protected:
    double x, y, width, height;
public:
    aabb(double x, double y, double width, double height);
    void set_x(double x){ this->x = x; }
    void set_y(double y){ this->y = y; }
    void set_xy(double x, double y){ this->x = x; this->y = y; }
    void set_width (double w){ this->width = w; }
    void set_height(double h){ this->height = h;}
    double get_x(){ return this->x; }
    double get_y(){ return this->y; }
    double get_width (){ return this->width; }
    double get_height(){ return this->height;}

    int aabb_id = 0;
    bool check_aabb_collision(aabb box_other);
};


#endif