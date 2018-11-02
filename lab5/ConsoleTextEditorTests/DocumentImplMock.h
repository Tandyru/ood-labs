#pragma once
#include "../ConsoleTextEditorLib/IDocumentImpl.h"

using namespace document;
using namespace document::impl;

class CDocumentImplMock : public IDocumentImpl
{
public:
	// Inherited via IDocumentImpl
	virtual shared_ptr<IParagraph> InsertParagraph(const string & text, optional<size_t> position = optional<size_t>()) override
	{
		lastCommandText = text;
		lastCommandPosition = position;
		itemCount++;
		return shared_ptr<IParagraph>();
	}

	virtual shared_ptr<IImage> InsertImage(const Path & path, int width, int height, optional<size_t> position = optional<size_t>()) override
	{
		lastCommandPath = path;
		lastCommandWidth = width;
		lastCommandHeight = height;
		return shared_ptr<IImage>();
	}

	virtual size_t GetItemsCount() const override
	{
		return itemCount;
	}

	virtual CConstDocumentItem GetItem(size_t index) const override
	{
		return CConstDocumentItem(shared_ptr<IParagraph>());
	}

	virtual CDocumentItem GetItem(size_t index) override
	{
		return CDocumentItem(shared_ptr<IParagraph>());
	}

	virtual void DeleteItem(size_t index) override
	{
		itemCount--;
	}

	void SetTitle(const string& title) override
	{
		this->title = title;
	}

	string GetTitle() const override
	{
		return title;
	}

public:
	string lastCommandText;
	Path lastCommandPath;
	optional<size_t> lastCommandPosition;
	int lastCommandWidth = 0;
	int lastCommandHeight = 0;
	size_t itemCount = 0;
	string title;
};