#ifndef TANGENTIALCIRCLEDIAGRAMOFPRIMARYWIND_H
#define TANGENTIALCIRCLEDIAGRAMOFPRIMARYWIND_H
#include "util.hpp"
#include <QWidget>

namespace Ui {
class TangentialCircleDiagramOfPrimaryWind;
}

class TangentialCircleDiagramOfPrimaryWind : public QWidget
{
    Q_OBJECT

public:
    explicit TangentialCircleDiagramOfPrimaryWind(QWidget *parent = nullptr);
    ~TangentialCircleDiagramOfPrimaryWind();

private:
    Ui::TangentialCircleDiagramOfPrimaryWind *ui;
};

#endif // TANGENTIALCIRCLEDIAGRAMOFPRIMARYWIND_H
