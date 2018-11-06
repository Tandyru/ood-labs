#pragma once
#include "../ConsoleTextEditorLib/IResource.h"

class ResourceMock : public resources::IResource
{
public:
	// Inherited via IResource
	Path GetFilePath() const override;
	Path GetSavePath() const override;
};