//
// Created by MAGUENDJI Freud on 12/2/20.
//

#include "Point.h"

Point::Point(const float x, const float y) {
    this->_x=x;
    this->_y=y;
    this->color="";
}

Point::Point():Point(0,0) {}

float Point::getX() const {
    return _x;
}

void Point::setX(float x) {
    _x = x;
}

float Point::getY() const {
    return _y;
}

void Point::setY(float y) {
    _y = y;
}

const std::string &Point::getColor() const {
    return color;
}

void Point::setColor(const std::string &color_) {
    Point::color = color_;
}

Point* Point::fromJson(const json &j) {
    Point* p=new Point();
    for(auto i=j.begin();i!=j.end();++i){
        auto key=i.key().c_str();
        auto value=i.value().get<std::string>();
        if (std::strcmp(key,"x")==0){
            auto floatval=std::stof(value);
            p->setX(floatval);
        }else if(std::strcmp(key,"color")==0){
            if(value.length()==0){
               p->setColor("255.255.255");
            }else{
                p->setColor(value);
            }
        }else if(std::strcmp(key,"y")==0){
            p->setY(std::stof(value));

        }
    }
   return p;

}

bool Point::operator==(const Point &rhs) const {
    return _x == rhs._x &&
           _y == rhs._y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

