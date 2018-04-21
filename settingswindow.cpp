#include "settingswindow.h"
#include "ui_settingswindow.h"
#include <QMetaEnum>

#include <QDebug>

SettingsWindow::SettingsWindow(QWidget* parent)
    : QDialog(parent, Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
    , ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    QMetaEnum meta = QMetaEnum::fromType<CardData::ImageType>();
    for (int i = 0; i < meta.keyCount(); ++i) {
        if (meta.value(i) != CardData::ImageType::none) {
            ui->themeComboBox->addItem(meta.key(i));
        }
    }

    meta = QMetaEnum::fromType<Settings::SizeType>();
    for (int i = 0; i < meta.keyCount(); ++i) {
        ui->boardSizeComboBox->addItem(meta.key(i));
    }

    connect(ui->dialogButtonBox, &QDialogButtonBox::rejected, this, &SettingsWindow::close);
    connect(ui->dialogButtonBox, &QDialogButtonBox::accepted, this, [&]() {
        m_settings.setSizeType(static_cast<Settings::SizeType>(ui->boardSizeComboBox->currentIndex()));
        m_settings.setImageType(static_cast<CardData::ImageType>(ui->themeComboBox->currentIndex()));
        close();
    });
}

const Settings* SettingsWindow::get() const
{
    return &m_settings;
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::show()
{
    ui->themeComboBox->setCurrentIndex(m_settings.imageType());
    ui->boardSizeComboBox->setCurrentIndex(m_settings.sizeType());
    QDialog::show();
}
