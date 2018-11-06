#pragma once
#include "../ConsoleTextEditorLib/IDocumentImpl.h"

using namespace document;
using namespace document::impl;

class CDocumentImplMock : public IDocumentImpl
{
public:
	// Inherited via IDocumentImpl
	shared_ptr<IParagraph> InsertParagraph(const string & text, optional<size_t> position = optional<size_t>()) override
	{
		lastCommandText = text;
		lastCommandPosition = position;
		itemCount++;
		return shared_ptr<IParagraph>();
	}

	shared_ptr<IImage> InsertImage(shared_ptr<resources::IResource> resource, int width, int height, 
		optional<size_t> position = optional<size_t>()) override
	{
		lastCommandResource = resource;
		lastCommandWidth = width;
		lastCommandHeight = height;
		lastCommandPosition = position;
		return shared_ptr<IImage>();
	}

	void InsertImage(shared_ptr<IImage> image, size_t position) override
	{
		lastCommandPosition = position;
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

	size_t GetParagraphPosition(const IParagraph & paragraph) const override
	{
		return 0;
	}

	size_t GetImagePosition(const IImage & image) const override
	{
		return 0;
	}

public:
	string lastCommandText;
	shared_ptr<resources::IResource> lastCommandResource;
	optional<size_t> lastCommandPosition;
	int lastCommandWidth = 0;
	int lastCommandHeight = 0;
	size_t itemCount = 0;
	string title;
};