#pragma once
#include "Image.h"
#include "Paragraph.h"

namespace document
{

/*
������������ ������� ���������
*/
class CConstDocumentItem
{
public:
	CConstDocumentItem(shared_ptr<IImage> image);

	CConstDocumentItem(shared_ptr<IParagraph> paragraph);

	// ���������� ��������� �� ����������� �����������, ���� nullptr,
	// ���� ������� �� �������� ������������
	shared_ptr<const IImage> GetImage()const;
	// ���������� ��������� �� ����������� ��������, ���� nullptr, ���� ������� �� �������� ����������
	shared_ptr<const IParagraph> GetParagraph()const;

	virtual ~CConstDocumentItem() = default;

protected:
	shared_ptr<IImage> m_image;
	shared_ptr<IParagraph> m_paragraph;
};

}
