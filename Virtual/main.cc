#include <iostream>

class Point2d{
public:
    Point2d(float x, float y):
        x_(x),
        y_(y)
    {

    }

    virtual void SetX(float x){
        x_ = x;
    }

    virtual void SetY(float y){
        y_ = y;
    }
private:
    float x_;
    float y_;
};

class Point3d : public Point2d{
public:
    Point3d(float x, float y, float z):
        Point2d(x, y),
        z_(z)
    {

    }
    void SetZ(float z){
        z_ = z;
    }
private:
    float z_;
};


int main(){
    // size
}
