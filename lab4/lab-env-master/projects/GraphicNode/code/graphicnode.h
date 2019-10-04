#pragma once
#include "meshresource.h"
#include "shaderresource.h"
#include "texture.h"
#include "transform.h"
#include <memory>

class GraphicNode
{
private:
	std::shared_ptr<MeshResource> p_Mesh;
	std::shared_ptr<Texture> p_Texture;
	std::shared_ptr<ShaderResource> p_Shader;
	std::shared_ptr<Transform> p_Transform;
	
public:
	GraphicNode(MeshResource& mesh, Texture& tex, ShaderResource& shader, Transform& trans);
	~GraphicNode();

	void Draw();
	
	void SetMesh(MeshResource& newmesh);
	void SetShader(ShaderResource& newshad);
	void SetTexture(Texture& newtex);
	void SetTransform(Transform &newtrans);
	
	std::shared_ptr<MeshResource> GetMesh() const;
	std::shared_ptr<ShaderResource> GetShader() const;
	std::shared_ptr<Texture> GetTexture() const;
	std::shared_ptr<Transform> GetTransform() const;
};