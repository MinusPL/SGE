#pragma once
#define GLEW_STATIC

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

class SGE_Mesh
{
private:
	GLuint VBO, EBO, VAO;
	GLuint VBOClr, VBONorm;
	GLuint VBOTangent;
	GLuint VBOuv;

	glm::vec3 NormalFromIndices(GLuint a, GLuint b, GLuint c);
	glm::vec3 TangentFromIndices(GLuint a, GLuint b, GLuint c);

public:
	GLenum vertexFlag = GL_TRIANGLES;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> colors;
	std::vector<GLuint> indices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> tangents;

	GLuint GetVAO() {
		return VAO;
	}

	void CreateInstanceAttribPointer();

	void Draw();

	void CreateMesh();
	void RecalculateNormals();

	~SGE_Mesh();
};