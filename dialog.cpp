#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    initilazeFonksiyonu();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_treeView_activated(const QModelIndex &index)
{
    QString seciliDosyaYolu = dizinModel.filePath(index);
    qDebug() << seciliDosyaYolu;
    // dosyaModel ile seciliDosyaYolu birlestiriliyor
    dosyaModel.setFilter(QDir::Filter::AllDirs | QDir::Filter::Files);
    ui->listView->setRootIndex(dosyaModel.setRootPath(seciliDosyaYolu));
}

void Dialog::initilazeFonksiyonu()
{
    // Ekranda acik olan (anlik) dosya dizini gosteriliyor.
    dizinModel.setRootPath(QDir::currentPath());
    // C ve D diskinin gelmesini ve butun alt dizinlerin gelmesini sagladik.
    dizinModel.setFilter(QDir::Filter::Drives | QDir::Filter::AllDirs | QDir::Filter::NoDotAndDotDot );

    ui->treeView->setModel(&dizinModel);

    for (int i=1; i<dizinModel.columnCount(); i++){
        ui->treeView->hideColumn(i);
    }

    dosyaModel.setRootPath(dizinModel.rootPath());
    // Sadece dosyalar listelensin.
    dosyaModel.setFilter(QDir::Filter::Files);
    // dosyaModel ile viewModel olan listView baglandi.
    ui->listView->setModel(&dosyaModel);
}

