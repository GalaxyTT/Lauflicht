#ifndef GPIO_H
#define GPIO_H

#include <QObject>

#include "config.h"

class Gpio : public QObject
{
    Q_OBJECT
public:
    explicit Gpio(QObject *parent = nullptr);
    void set(int pin, bool state);
    int get(int pin);

signals:

private:
    int m_handle;

};

#endif // GPIO_H
