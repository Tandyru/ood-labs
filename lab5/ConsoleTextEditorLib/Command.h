#pragma once

namespace document
{

namespace command
{

class CCommand
{
public:
	virtual ~CCommand() = default;

	void Execute();
	void Unexecute();

protected:
	virtual void ExecuteImpl() = 0;
	virtual void UnexecuteImpl() = 0;

private:
	bool m_executed = false;
};

}

namespace impl
{
class IDocumentImpl;
}

}
