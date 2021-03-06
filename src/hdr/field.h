#pragma once

#include "entity.h"
#include "display.h"
#include "coordinate_system.h"

const Vector2 CENTERED_ORIGIN_POINT = Vector2(NAN, NAN);

class Field
{

protected:

    Rectangle area_;
    CoordinateSystem coord_system_;
    Color color_;

public:

    Field() = default;
    // Первоначальные координаты отсчитываются от верхнего левого угла Feild
    Field(Rectangle area, Color color,
          Vector2 origin_point, float scale);
    Field(Rectangle area, Color color,
          PixelPoint abs_origin_point, float scale);

    CoordinateSystem& coord_system();
    const Rectangle& area() const;

    void Move(PixelPoint pixelpoint);
    void Draw(Display& display);
    Vector2 getRandomCoord() const;

    void drawFigure(Display& display, Entity* entity);

    void drawPoint(Display& display, Vector2& point, Color& color);
    void drawLine(Display& display, Vector2& first_point, Vector2& second_point, Color& color);

    bool isWithin(PixelPoint point) const;

    ~Field() = default;

};