#pragma once

#include "settings.h"
#include "Point.h"
#include "Matrix.h"
#include "rotationMatrixes.h"
#include "Surface.h"


class Parallelepiped{

public:
    Parallelepiped();
    ~Parallelepiped();

    void moveAlongX(double moveDistance);
    void moveAlongY(double moveDistance);
    void moveAlongZ(double moveDistance);

    void rotateAroundX(double rotationAngle);
    void rotateAroundY(double rotationAngle);
    void rotateAroundZ(double rotationAngle);

    void scale(double scaleCoefficient);

    Surface** createArrayOfSurfaces();

    int getNumSurfaces();

protected:
    Matrix* pointsCoords;

    int numVertexes = 8;
    int numSurfaces = 6;

    Point centerPoint;
    void findCenter();
	void moveToCenterCoords();
	void moveFromCenterCoords();

    void addToPointsCoordsMatrix(int numRow, int numCol, double addValue);
    void mulToPointsCoordsMatrix(int numRow, int numCol, double mulValue);

    // fill pointArr, give indexes of point Surface from matrix of points in parallelepiped
    void fillArrayOfSurfacePoints(Point* pointArr, int index1, int index2, int index3, int index4);
};
