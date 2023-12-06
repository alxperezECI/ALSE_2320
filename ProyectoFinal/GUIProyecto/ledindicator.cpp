// ledindicator.cpp
#include "ledindicator.h"
#include <QPainter>

LedIndicator::LedIndicator(QWidget *parent)
    : QWidget(parent), m_color(Qt::red) {
}

QSize LedIndicator::sizeHint() const {
    return QSize(20, 20);
}

void LedIndicator::setColor(const QColor &color) {
    m_color = color;
    update(); // Redraw the widget
}

void LedIndicator::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw the LED
    painter.setBrush(m_color);
    painter.drawEllipse(rect());
}
