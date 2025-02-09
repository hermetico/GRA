#ifndef OBJECTE_H
#define OBJECTE_H

#include <QObject>

#include <vector>

#include <Common.h>
#include <cara.h>


#include <QGLShaderProgram>

typedef Common::vec4  color4;
typedef Common::vec4  point4;

using namespace std;

class Objecte : public QObject
{
    Q_OBJECT
protected:
    QString nom; // nom del fitxer on esta el cotxe
    vector<Cara> cares; // cares de l'objecte


    // Sistema de coordenades d'un objecte: punt origen i eixos de rotació
    GLfloat xorig, yorig, zorig;
    float xRot;
    float yRot;
    float zRot;

    GLfloat tam; // Escala de l'objecte aplicada al fitxer d'entrada


    // Programa de shaders de la GPU
    QGLShaderProgram *program;
    GLuint buffer; // Buffer de comunicacio amb la GPU

    // Estructures de vertexs i colors per passar a la GPU
    int     numPoints;
    point4 *points;
    color4 *colors;
    int Index; // index de control del numero de vertexs a posar a la GPU
    virtual void escalarFrom1(float factor);

public:

    vector<point4> vertexs; // vertexs de l'objecte sense repetits
    float getYOrig();
    void setYorig(float orig);
    // Capsa mínima contenidora de l'objecte
    Capsa3D capsa;


    //explicit Objecte(QObject *parent = 0);
    Objecte(const int npoints, QObject *parent = 0);

    Objecte(const int npoints, QString n, GLdouble tamanio, GLdouble x0, GLdouble y0, GLdouble z0,  double girx, double giry, double girz);

    ~Objecte();

    // llegeix un model en format OBJ
    virtual void readObj(QString filename);

    // make(): omple l'estructura de points i colors de l'objecte, inicialitza NumVertices
    // Si l'objecte es construeix procedimentalment es sobrecarrega el make
    virtual void make();

    // Pas generic de vertexs i colors a la GPU
    virtual void toGPU(QGLShaderProgram *p);
    // Pintat amb la GPU
    virtual void draw();

    // Calcula la capsa 3D contenidora de l'objecte
    virtual Capsa3D calculCapsa3D();
    virtual point4 calculCentre();

    // Aplica una TG qualsevol a un objecte
    virtual void aplicaTG(mat4 m);
    void aplicaTGPoints(mat4 m);
    // Aplica una TG centrada en el punt central de la capsa de l'objecte a un objecte
    void aplicaTGCentrat(mat4 m);



protected:
    point4 centre;
    void construeix_cara ( char **words, int nwords, Objecte*objActual, int vindexUlt);
private:


};



#endif // OBJECTE_H
