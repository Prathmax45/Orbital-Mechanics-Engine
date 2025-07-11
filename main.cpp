#include <iostream>
#include "vector_3D.h"

using namespace std;

int main()
{
    vector_3D v1;
    v1.display();

    vector_3D v2(1,2,3);
    vector_3D v4(3,5,6);
    vector_3D v3;
    v3 = v2 * 4;
    v3.display();
    double i = v3 .dot(v2);
    cout << i << endl;

    v3 = v2.cross(v4);
    v3.display();

    double len = v3.length();
    cout << len <<endl;

    v4 = v3.normalize();
    v4.display();

}
