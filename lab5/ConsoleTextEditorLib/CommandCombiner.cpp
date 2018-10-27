#include "stdafx.h"
#include "CommandCombiner.h"
#include "ICommandVisitor.h"
#include "CompositeCommand.h"

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

bool CommandPositionsAreEqual(const CDeleteItemCommand& deleteItem, const CInsertParagraphCommand& insertParagraph)
{
	if (!(insertParagraph.GetPosition()))
	{
		return deleteItem.GetLastItemDeleted();
	}
	return deleteItem.GetPosition() == *insertParagraph.GetPosition();
}

bool CommandPositionsAreEqual(const CDeleteItemCommand& deleteItem, const CInsertImageCommand& insertImage)
{
	if (!(insertImage.GetPosition()))
	{
		return deleteItem.GetLastItemDeleted();
	}
	return deleteItem.GetPosition() == *insertImage.GetPosition();
}

bool ShoudCombine(const CDeleteItemCommand& deleteItem, const CInsertParagraphCommand& insertParagraph)
{
	if (CommandPositionsAreEqual(deleteItem, insertParagraph))
	{
		auto paragraph = deleteItem.GetDeletedParagraph();
		if (paragraph)
		{
			return true;
		}
	}
	return false;
}

bool ShoudCombine(const CDeleteItemCommand& deleteItem, const CInsertImageCommand& insertImage)
{
	if (CommandPositionsAreEqual(deleteItem, insertImage))
	{
		auto image = deleteItem.GetDeletedImage();
		if (image && image->GetPath() == insertImage.GetPath())
		{
			return true;
		}
	}
	return false;
}

}

bool CCommandCombiner::ShoudCombine(const CCommand & prevCommand, const CCommand & nextCommand)
{
	CCommandVisitor prevCommandVisitor;
	prevCommand.Accept(prevCommandVisitor);
	CCommandVisitor nextCommandVisitor;
	nextCommand.Accept(nextCommandVisitor);

	if (prevCommandVisitor.deleteItemCommand != nullptr && 
		nextCommandVisitor.insertParagraphCommand != nullptr)
	{
		return command::ShoudCombine(*prevCommandVisitor.deleteItemCommand, *nextCommandVisitor.insertParagraphCommand);
	}
	if (prevCommandVisitor.deleteItemCommand != nullptr &&
		nextCommandVisitor.insertImageCommand != nullptr)
	{
		return command::ShoudCombine(*prevCommandVisitor.deleteItemCommand, *nextCommandVisitor.insertImageCommand);
	}
	return false;
}

}
}
