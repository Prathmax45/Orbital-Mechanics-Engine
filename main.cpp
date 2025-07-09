#include <iostream>
#include "vector_3D.h"

using namespace std;

int main()
{
    vector_3D v1;
    v1.display();

    vector_3D v2(1,2,3);
    vector_3D v3;
    v3 = v2 * 4;
    v3.display();
    double i = v3 .dot(v2);
    cout << i << endl;
    v2.display();
}
