#ifndef SPLASHLABEL_H
#define SPLASHLABEL_H

#include <QtWidgets>

class splashLabel : public QLabel
{

  Q_OBJECT

public:

  explicit splashLabel(QDialog * parent = 0) :
    QLabel(parent)
  {
  }

  virtual void setId(int labelindex)
  {
    index = labelindex;
  }

  virtual int getId()
  {
    return index;
  }

protected:

  virtual void mousePressEvent(QMouseEvent * event)
  {
    if (event->type() == QEvent::MouseButtonDblClick) {
      emit buttonPressed(Qt::Key_Enter);
    }
    else {
      emit buttonPressed(Qt::Key_Select);
    }
    // QWidget::mousePressEvent(event);
  }

  virtual void mouseReleaseEvent(QMouseEvent * event)
  {
    setFocus();
    // emit buttonPressed(0);
    // QWidget::mouseReleaseEvent(event);
  }


  /*void paintEvent(QPaintEvent *)
  {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
  }
   */
signals:
  void buttonPressed(int button);

private:
  int index;
};

#endif /* SPLASHLABEL_H */

