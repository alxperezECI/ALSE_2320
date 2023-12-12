// ledindicator.h
#ifndef LEDINDICATOR_H
#define LEDINDICATOR_H

#include <QWidget>

class LedIndicator : public QWidget {
    Q_OBJECT

public:
    explicit LedIndicator(QWidget *parent = nullptr);

    QSize sizeHint() const override;

public slots:
    void setColor(const QColor &color);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QColor m_color;
};

#endif // LEDINDICATOR_H

