#pragma once
#include "../ConsoleTextEditorLib/IDocumentImpl.h"

using namespace document;

class CDocumentImplMock : public IDocumentImpl
{
public:
	// Inherited via IDocumentImpl
	virtual shared_ptr<IParagraph> InsertParagraph(const string & text, optional<size_t> position = optional<size_t>()) override;
	virtual shared_ptr<IImage> InsertImage(const Path & path, int width, int height, optional<size_t> position = optional<size_t>()) override;
	virtual size_t GetItemsCount() const override;
	virtual CConstDocumentItem GetItem(size_t index) const override;
	virtual CDocumentItem GetItem(size_t index) override;
	virtual void DeleteItem(size_t index) override;

public:
	string lastCommandText;
	string lastCommandPath;
	optional<size_t> lastCommandPosition;
};