// NIGHTMAN.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
#include<vector>

#include <GLFW/glfw3.h>
#define PI 3.14



int main(void)
{
    GLFWwindow* window;

    float x = .92f, y = .38f;

    float rad = (45 * PI) / 180;

    float Xvert[8];
    float Yvert[8];

    Xvert[0] = x;
    Yvert[0] = y;


    for (int i = 0;i < 8;i++)
    {

        float a, b,z,v;
        std::cout << Xvert[i] << ", " << Yvert[i]+.1f << "\n";
        a = (Xvert[i] * cos(rad)) - (Yvert[i] * sin(rad));
        b = (Xvert[i] * sin(rad)) + (Yvert[i] * cos(rad));

        //round off:
        z = std::floorf(a * 100) / 100.0f;
        v= std::floorf(b * 100) / 100.0f;

        Xvert[i + 1] = z;
        Yvert[i + 1] = v;
    }





    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Rameses P. Amar:    THE OCTAGON", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_POLYGON);

        
       
     
        
        for (int i = 0;i < 8;i++)
        {
            
            glVertex2f(Xvert[i], Yvert[i] + .1f);
        }
        
        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

       
    }

   

    glfwTerminate();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
