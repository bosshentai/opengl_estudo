
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>



#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
  
     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
   
     

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 540, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1); // incrosizacao d tempo

    if (glewInit() != GLEW_OK)
        std::cout << "ERROR!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    {
      
        
        GLCall(glEnable(GL_BLEND)); 
        GLCall(glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA));

       

       Renderer renderer;

    

     
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
           renderer.Clear();

         //  test.OnUpdate(0.0f);
         //  test.OnRender();

         //  glfwPollEvents();
         

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        
    }

 
    glfwTerminate();

    glfwTerminate();
    return 0;
}