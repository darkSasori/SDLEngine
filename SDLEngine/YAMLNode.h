#ifndef __YAMLNODE_H__
#define __YAMLNODE_H__

#include "Headers.h"
#include "Exception.h"

NS_BEGIN

class YAMLNode : public YAML::Node {
	private:
		YAML::Parser m_Parser;

	public:
		YAMLNode();
		virtual ~YAMLNode();

		void LoadFile(std::string);
};

NS_END

#endif
