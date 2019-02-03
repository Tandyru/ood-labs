#pragma once
#include "../ConsoleTextEditorLib/IDocumentImpl.h"

using namespace document;
using namespace document::impl;

class CDocumentImplMock : public IDocumentImpl
{
public:
	// Inherited via IDocumentImpl
	/*
	void InsertParagraph(const std::string & text, std::optional<size_t> position = std::optional<size_t>()) override
	{
		lastCommandText = text;
		lastCommandPosition = position;
		itemCount++;
	}
	*/
	void InsertParagraph(const std::shared_ptr<IParagraph>& paragraph, std::optional<size_t> position = std::optional<size_t>()) override
	{
		lastCommandText = paragraph->GetText();
		lastCommandPosition = position;
		itemCount++;
	}

	void InsertImage(std::shared_ptr<resources::IResource> resource, int width, int height,
		std::optional<size_t> position = std::optional<size_t>()) override
	{
		lastCommandResource = resource;
		lastCommandWidth = width;
		lastCommandHeight = height;
		lastCommandPosition = position;
	}

	void InsertImage(std::shared_ptr<IImage> image, size_t position) override
	{
		lastCommandPosition = position;
	}

	virtual size_t GetItemsCount() const override
	{
		return itemCount;
	}

	virtual CConstDocumentItem GetItem(size_t index) const override
	{
		return CConstDocumentItem(std::shared_ptr<IParagraph>());
	}

	virtual CDocumentItem GetItem(size_t index) override
	{
		return CDocumentItem(std::shared_ptr<IParagraph>());
	}

	virtual void DeleteItem(size_t index) override
	{
		itemCount--;
	}

	void SetTitle(const std::string& title) override
	{
		this->title = title;
	}

	std::string GetTitle() const override
	{
		return title;
	}

	size_t GetImagePosition(const IImage & image) const override
	{
		return 0;
	}

public:
	std::string lastCommandText;
	std::shared_ptr<resources::IResource> lastCommandResource;
	std::optional<size_t> lastCommandPosition;
	int lastCommandWidth = 0;
	int lastCommandHeight = 0;
	size_t itemCount = 0;
	std::string title;
};