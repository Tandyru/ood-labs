#include "stdafx.h"
#include "CommandCombiner.h"
#include "ICommandVisitor.h"
#include "ReplaceTextCommand.h"

namespace document
{
namespace command
{

namespace
{

class CCommandVisitor : public ICommandVisitor
{
public:
	void Visit(const CDeleteItemCommand& command) override
	{
		deleteItemCommand = &command;
	}

	void Visit(const CInsertParagraphCommand& command) override
	{
		insertParagraphCommand = &command;
	}

	void Visit(const CInsertImageCommand& command) override
	{
		insertImageCommand = &command;
	}

	const CDeleteItemCommand* deleteItemCommand = nullptr;
	const CInsertParagraphCommand* insertParagraphCommand = nullptr;
	const CInsertImageCommand* insertImageCommand = nullptr;
};

unique_ptr<CCommand> Combine(const CDeleteItemCommand& deleteItem, const CInsertParagraphCommand& insertParagraph)
{
	if (deleteItem.GetPosition() == insertParagraph.GetInsertedPosition())
	{
		auto paragraph = deleteItem.GetDeletedParagraph();
		if (paragraph)
		{
			return make_unique<CReplaceTextCommand>(deleteItem.GetDocument(), deleteItem.GetPosition(), insertParagraph.GetText());
		}
	}
	return unique_ptr<CCommand>();
}

unique_ptr<CCommand> Combine(const CDeleteItemCommand& deleteItem, const CInsertImageCommand& insertImage)
{
	// TODO:
	return unique_ptr<CCommand>();
}

}

unique_ptr<CCommand> CCommandCombiner::Combine(const CCommand & prevCommand, const CCommand & nextCommand) const
{
	CCommandVisitor prevCommandVisitor;
	prevCommand.Accept(prevCommandVisitor);
	CCommandVisitor nextCommandVisitor;
	nextCommand.Accept(nextCommandVisitor);

	if (prevCommandVisitor.deleteItemCommand != nullptr && 
		nextCommandVisitor.insertParagraphCommand != nullptr)
	{
		return Combine(*prevCommandVisitor.deleteItemCommand, *nextCommandVisitor.insertParagraphCommand);
	}
	if (prevCommandVisitor.deleteItemCommand != nullptr &&
		nextCommandVisitor.insertImageCommand != nullptr)
	{
		return Combine(*prevCommandVisitor.deleteItemCommand, *nextCommandVisitor.insertImageCommand);
	}
	return unique_ptr<CCommand>();
}

}
}
