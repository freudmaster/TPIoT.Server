//
// Created by MAGUENDJI Freud on 12/2/20.
//

#ifndef TP_IOT_POINT_H
#define TP_IOT_POINT_H
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Point {

private:
    float _x, _y;
    std::string color;
public:
    Point( float x, float y);
    Point();
    static Point* fromJson(const json &j) ;

    float getX() const;

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;

    void setX(float x);

    float getY() const;

    const std::string &getColor() const;

    void setColor(const std::string &color);

    void setY(float y);
};
static Point ZERO=Point(0,0);



#endif //TP_IOT_POINT_H
