#pragma once

#include "FractoriumPch.h"

/// <summary>
/// DoubleSpinBox and VariationTreeDoubleSpinBox classes.
/// </summary>

/// <summary>
/// A derivation to prevent the spin box from selecting its own text
/// when editing. Also to prevent multiple spin boxes from all having
/// selected text at once.
/// </summary>
class DoubleSpinBox : public QDoubleSpinBox
{
	Q_OBJECT

public:
	explicit DoubleSpinBox(QWidget* parent = 0, int height = 16, double step = 0.05);
	virtual ~DoubleSpinBox() { }
	void SetValueStealth(double d);
	void DoubleClick(bool b);
	void DoubleClickZero(double val);
	void DoubleClickNonZero(double val);
	double Step();
	void Step(double step);
	double SmallStep();
	void SmallStep(double step);
	QLineEdit* lineEdit();

public slots:
	void OnSpinBoxValueChanged(double d);
	void OnTimeout();

protected:
	virtual bool eventFilter(QObject* o, QEvent* e) override;
	virtual void focusInEvent(QFocusEvent* e);
	virtual void focusOutEvent(QFocusEvent* e);
	virtual void enterEvent(QEvent* e);
	virtual void leaveEvent(QEvent* e);

private:
	void StartTimer();
	void StopTimer();

	bool m_Select;
	bool m_DoubleClick;
	double m_DoubleClickNonZero;
	double m_DoubleClickZero;
	double m_Step;
	double m_SmallStep;
	QPoint m_MouseDownPoint;
	QPoint m_MouseMovePoint;
	static QTimer m_Timer;
};

/// <summary>
/// VariationTreeWidgetItem and VariationTreeDoubleSpinBox need each other, but each can't include the other.
/// So VariationTreeWidgetItem includes this file, and use a forward declaration here.
/// </summary>
class VariationTreeWidgetItem;

/// <summary>
/// Derivation for the double spin boxes that are in the
/// variations tree.
/// </summary>
class VariationTreeDoubleSpinBox : public DoubleSpinBox
{
public:
	/// <summary>
	/// Constructor that passes agruments to the base and assigns the m_Param and m_Variation members.
	/// </summary>
	/// <param name="p">The parent widget</param>
	/// <param name="widgetItem">The widget item this spinner is contained in</param>
	/// <param name="id">The variation this spinner is for</param>
	/// <param name="param">The name of the parameter this is for</param>
	/// <param name="h">The height of the spin box. Default: 16.</param>
	/// <param name="step">The step used to increment/decrement the spin box when using the mouse wheel. Default: 0.05.</param>
	explicit VariationTreeDoubleSpinBox(QWidget* p, VariationTreeWidgetItem* widgetItem, eVariationId id, string param, int h = 16, double step = 0.05)
		: DoubleSpinBox(p, h, step)
	{
		m_WidgetItem = widgetItem;
		m_Param = param;
		m_Id = id;
		setDecimals(3);
	}

	virtual ~VariationTreeDoubleSpinBox() { }
	bool IsParam() { return !m_Param.empty(); }
	string ParamName() { return m_Param; }
	eVariationId GetVariationId() { return m_Id; }
	VariationTreeWidgetItem* WidgetItem() { return m_WidgetItem; }

private:
	string m_Param;
	eVariationId m_Id;
	VariationTreeWidgetItem* m_WidgetItem;
};
