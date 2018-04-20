#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog {

    Q_OBJECT

public:
    explicit SettingsWindow(QWidget* parent = 0);
    ~SettingsWindow();

private:
    Ui::SettingsWindow* ui;

signals:
    void sizeSettingChanged(int width, int height);
};

#endif // SETTINGSWINDOW_H
