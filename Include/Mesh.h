#ifndef MESH_H
#define MESH_H
#include "GL/glew.h"
#include "VertexArray.h"
#include "Shaders.h"
#include "Texture.h"

class Mesh
{
public:
	// Apply the rule of five here - potentiall pass a Vertex Array by const reference, rvalue reference, etc
	Mesh(std::weak_ptr<Shader> shaderProgram, std::weak_ptr<Texture> meshTexture, bool diff = false);

	Mesh(VertexArray&& vao, std::weak_ptr<Shader> shaderProgram) : m_vao(std::move(vao)), m_shaderProgram(shaderProgram) {}
	~Mesh() = default;
	
	void Bind();
	void Draw();
	void SetShader();
	void SetTexture();
	void SetUniforms();
	void SetTransMatrix(glm::mat4 trans);
	void Render();
	void Update();
	void InitMesh();


private:
	VertexArray m_vao;
	std::weak_ptr<Shader> m_shaderProgram;
	std::weak_ptr<Texture> m_meshTexture;
	glm::mat4 m_transMatrix;
};


#endif