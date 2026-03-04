#pragma once 
#include <fstream>

struct __declspec(align(4)) CTCPARSE_PARAM // sizeof=0x14
{
//	CTCPARSE_PARAM_vtbl *__vftable;

	//CTCPARSE_PARAM::CTCPARSE_PARAM //add this, I just don't want to rn
	virtual ~CTCPARSE_PARAM();

	CTCPARSE_PARAM *pNext;
	int nType;
	char *pVarName;
	char cComponent;
	// padding byte
	// padding byte
	// padding byte
};

class CTCPARSE_KEYWORD {
public:
	CTCPARSE_KEYWORD(const CTCPARSE_KEYWORD* cKeyword);

	virtual void Save(FILE* f);
	virtual ~CTCPARSE_KEYWORD();

	char aKeyword[40];
	CTCPARSE_PARAM* pParams;
	CTCPARSE_KEYWORD* pNext;
	CTCPARSE_KEYWORD* pChild;
};
