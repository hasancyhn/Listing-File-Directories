#include "dialog.h"

#include <QApplication>
#include <QStringList>
#include <QStringListModel>
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QStringList sayilar;
//    sayilar << "bir" << "iki" << "uc";
//    QAbstractItemModel *model = new QStringListModel(sayilar);

//    QListView *goruntule = new QListView;
//    view->setModel(model);
//    view->show();

    Dialog w;
    w.show();
    return a.exec();
}
