#pragma once
#include "ILineStyle.h"
#include "IEnumerator.h"

namespace shape
{

class IGroup;

class CGroupLineStyle : public ILineStyle
{
	using ILineStyleEnumerator = IEnumerator<ILineStyle>;
public:
	CGroupLineStyle(std::unique_ptr<ILineStyleEnumerator>&& enumerator);

	void SetColor(const ColorType& color) override;
	ColorType GetColor() const override;

	void SetThickness(const ILineStyle::ThicknessType& thickness) override;
	ILineStyle::ThicknessType GetThickness() const override;

private:
	void ForEach(const std::function<void(ILineStyle&)>& func);

private:
	std::unique_ptr<ILineStyleEnumerator> m_enumerator;
};

}