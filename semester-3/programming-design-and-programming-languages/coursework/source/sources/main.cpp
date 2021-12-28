#include <QApplication>
#include <QIcon>
#include "breakout.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);
  app.setWindowIcon(QIcon(":/img/breakout.png"));
  Breakout window;

  window.setFixedSize(QSize(660, 900));
  window.setWindowTitle("Breakout");
  window.show();

  return app.exec();
}
