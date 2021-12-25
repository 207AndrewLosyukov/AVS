#ifndef Room_class
#define Room_class

#include "Hotel.h"
#include "thread"
#include "chrono"
#include "random"
#include "Lady.h"
#include "Gentleman.h"

class Lady;
class Gentleman;

/*
 * Комната
 */
class Room {
    /*
     * Для одного или для двух
     */
    bool isForOnePerson{};

    /*
     * В зависимости от того, мужская комната или женская, будет заполняться
     * один из массивов.
     */
    Gentleman *gentleman{};
    Lady *ladies{};

    /*
     * Остаток мест в комнате.
     */
    int countFreeInRoom{};

public:

    /*
     * Мужская ли комната.
     */
    bool isForGentleman;
    Room();

    explicit Room(bool isForOnePerson, bool isForGentleman);

    /*
     * Добавление в комнату нового человека.
     */
    bool addPeopleForRoom();
};


#endif
