#pragma once

/*
������������ ������� ���������
*/
class CConstDocumentItem
{
public:
	// ���������� ��������� �� ����������� �����������, ���� nullptr,
// ���� ������� �� �������� ������������
	std::shared_ptr<const IImage> GetImage()const;
	// ���������� ��������� �� ����������� ��������, ���� nullptr, ���� ������� �� �������� ����������
	shared_ptr<const IParagraph> GetParagraph()const;
	virtual ~CConstDocumentItem() = default;
};
