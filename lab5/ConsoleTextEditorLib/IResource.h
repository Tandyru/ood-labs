#pragma once

namespace resources
{

class IResource
{
public:
	virtual Path GetFilePath() const = 0;
	virtual Path GetSavePath() const = 0;
	virtual ~IResource() = default;
};

}
