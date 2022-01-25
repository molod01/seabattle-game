#ifndef UNIT_H
#define UNIT_H

#include <QObject>

class Unit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool clickability READ isClickable)
    Q_PROPERTY(bool exploded READ isExploded)
    bool clickability_;
    bool exploded_ = false;
public:
    explicit Unit(): clickability_(NULL){};
    explicit Unit(bool clickability) : clickability_(clickability){};


    void Explode(){
        setClickability(false);
        setExploded(true);
    }

    bool isClickable() { return clickability_; }
    bool isExploded() { return exploded_; }

    void setClickability(bool clickability){
        clickability_ = clickability;
    }
    void setExploded(bool exploded){
        exploded_ = exploded;
    }
};
#endif // UNIT_H
