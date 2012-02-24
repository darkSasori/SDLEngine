#include "YAMLNode.h"

NS_BEGIN

YAMLNode::YAMLNode(){
}

YAMLNode::~YAMLNode(){
}

void YAMLNode::LoadFile(std::string file){
	std::ifstream f1(file.c_str());
	m_Parser.Load(f1);

	if( !m_Parser.GetNextDocument(*this) )
		throw Exception("Nao foi possivel carregar o arquivo '%s'.", file.c_str());
}

NS_END
