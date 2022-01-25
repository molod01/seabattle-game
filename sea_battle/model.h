#ifndef MODEL_H
#define MODEL_H

#include "unit.h"
#include <QAbstractItemModel>
#include <QVector>

class SeaBattleModel : public QAbstractItemModel{
    Unit **board = nullptr;
    const ushort dimension_ = 10; //N
    Q_OBJECT
    Q_PROPERTY(int dimension READ dimension CONSTANT);
public:
    SeaBattleModel(QObject *parent = nullptr);
    ~SeaBattleModel();

    void fillBoard();

    Unit* getUnit(ushort x, ushort y);
    ushort dimension() const;

    QModelIndex	index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex	parent(const QModelIndex &index) const;
    int	rowCount(const QModelIndex &parent = QModelIndex()) const;
    int	columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

public slots:
    bool click(int index);

};

#endif // MODEL_H
