#include "headers.h"

SeaBattleModel::SeaBattleModel(QObject *parent) : QAbstractItemModel(parent){
    board = new Unit*[dimension_];
    for(int i = 0; i < dimension_; i++){
        board[i] = new Unit[dimension_];
    }
    fillBoard();
}

SeaBattleModel::~SeaBattleModel(){
    delete[] board;
}
void SeaBattleModel::fillBoard(){
    cout <<"Reading data file..."<< endl;
    Reader* r = Reader::GetInstance("../sea_battle/file.bin");
    bool** mask_arr = r->ReadMatrix(dimension_);
    for(int i = 0; i < dimension_; i++)
        for(int j = 0; j < dimension_; j++){
            board[i][j].setClickability(mask_arr[i][j]);
    }
    delete[] mask_arr;
}

bool SeaBattleModel::click(int index)
{
    ushort row = index / dimension_;
    ushort col = index % dimension_;
    Unit* temp = getUnit(row, col);
    if(temp->isClickable()){
        cout<<"Click: ["<< row << ", " << col << "] " << "Cell is explode\n";
        temp->Explode();
        emit dataChanged(createIndex(row, col), createIndex(row, col));
        return true;
    }else cout <<"(Unclickable)"<< endl; return false;
}
Unit* SeaBattleModel::getUnit(ushort x, ushort y){
    return &board[x][y];
}

ushort SeaBattleModel::dimension() const
{
    return dimension_;
}

QModelIndex SeaBattleModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column, &parent);
}

QModelIndex SeaBattleModel::parent(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return createIndex(0, 0, this);
}

int SeaBattleModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dimension_*10;
}

int SeaBattleModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dimension_;
}

QVariant SeaBattleModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole) return QVariant();
    else return QVariant(board[index.row()][index.column()].metaObject());
}


