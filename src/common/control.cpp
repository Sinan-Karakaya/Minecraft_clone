/*
** EPITECH PROJECT, 2022
** opengl
** File description:
** main file
*/

#include <stdlib.h>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "../../include/test.h"

extern GLFWwindow *window;

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

// Initial position : on +Z
glm::vec3 position = glm::vec3( 0, 0, 5 );
// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 60.0f;

float speed = 0.05f;
float mouseSpeed = 0.0001f;

mat4 getProjectionMatrix(void)
{
    return ProjectionMatrix;
}

mat4 getViewMatrix(void)
{
    return ViewMatrix;
}

void computeMatricesFromInputs(void)
{
    // glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

    //get mouse pos
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    //reset mouse pos for next frame
    glfwSetCursorPos(window, 1920/2, 1080/2);

    //compute new orientation
    horizontalAngle += mouseSpeed * deltaTime * float(1920/2 - xpos);
    verticalAngle += mouseSpeed * deltaTime * float(1080/2 - ypos);

    //Direction : spherical coord to cartesian coord conversion
    vec3 direction(
        cos(verticalAngle) * sin(horizontalAngle),
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle)
    );

    //right vector
    vec3 right = vec3(
        sin(horizontalAngle - 3.14f/2.0f),
        0,
        cos(horizontalAngle - 3.14f/2.0f)
    );

    //Up vector : perpendicular to direction and right
    vec3 up = cross(right, direction);

    //Move forward
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        position += direction * deltaTime * speed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        position -= direction * deltaTime * speed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        position += right * deltaTime * speed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        position -= right * deltaTime * speed;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        position.y += 0.5;
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
        position.y -= 0.5;

    //projection matrix : 45&deg; fov, 4:3, display range
    ProjectionMatrix = perspective(radians(initialFoV), 16.0f/9.0f, 0.1f, 100.0f);
    //camera matrix
    ViewMatrix = lookAt(
        position,
        position + direction,
        up
    );
}
