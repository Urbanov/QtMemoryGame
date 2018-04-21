#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include "settings.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog {

    Q_OBJECT

public:
    explicit SettingsWindow(QWidget* parent = 0);
    const Settings* get() const;
    ~SettingsWindow();
    void show();

private:
    Ui::SettingsWindow* ui;
    Settings m_settings;
};

#endif // SETTINGSWINDOW_H
