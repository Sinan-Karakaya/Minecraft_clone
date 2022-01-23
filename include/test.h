#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

using namespace glm;

typedef struct triangle {
    GLuint vertexbuffer;
    GLfloat *g_vertex;
} triangle_t;

typedef struct matrix {
    GLuint MatrixID;
    glm::mat4 mvp;
} matrix_t;

triangle_t *do_triangle(void);
void draw_triangle(GLuint vertexbuffer);
GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
// matrix_t tr_vector(GLuint ProgramID);
void draw_colors(GLuint colorbuffer);
GLuint loadBMP_custom(const char *filepath);
GLuint loadDDS(const char * imagepath);
void computeMatricesFromInputs(void);
glm::mat4 getViewMatrix(void);
glm::mat4 getProjectionMatrix(void);
bool loadOBJ(const char *path, std::vector<vec3> & out_vertices, std::vector<vec2> & out_uvs, std::vector<vec3> & out_normals);
