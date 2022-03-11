/*
** PERSONNAL PROJECT, 2022
** minecraft clone
** File description:
** generate a chunk
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "test.h"
using namespace glm;

obj_components_t *generate_chunk(int iteration)
{
    obj_components_t *obj_comps = NULL;
    // std::vector<vec3> vertices;
    // std::vector<vec2> uvs;
    // std::vector<vec3> normals;
    loadOBJ("./assets/cube.obj", obj_comps->vertices, obj_comps->uvs, obj_comps->normals, iteration);
    glBufferData(GL_ARRAY_BUFFER, obj_comps->vertices.size() * sizeof(vec3), &obj_comps->vertices[0], GL_STATIC_DRAW);
    return obj_comps;
}
