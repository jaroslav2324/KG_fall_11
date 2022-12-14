#pragma once

#include <algorithm>
#include <vector>

#include "SDL.h"

#include "settings.h"
#include "Color.h"
#include "Parallelepiped.h"
#include "Pyramid.h"


class ZBuffer{

public:
    ZBuffer();
    ~ZBuffer();

    void renderBuffer(SDL_Renderer* renderer, Parallelepiped* par, Pyramid* pyr, Point* lightSource);

private:
    void clearZBuffer();
    void placeParallelepiped(Parallelepiped* par);
    void placePyramid(Pyramid* pyr);
    void placeSurfaceInZBuffer(Surface* surface);

    void recursiveFillVectorOfCoords(Surface* surface, std::vector<std::pair<int, int>>& pointsVector, int startX, int startY);

    void placeShades(SDL_Renderer* renderer, Parallelepiped* par, Pyramid* pyr, Point* lightSource);

    Color*** screenColorsArray; // [SCREEN_HEIGHT] [SCREEN_WIDTH] ;
    double*** zBuffer; // [SCREEN_HEIGHT] [SCREEN_WIDTH] ;
};