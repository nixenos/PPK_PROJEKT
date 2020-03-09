//
// Created by nixen on 21.11.2019.
//
/**
 * @headerfile
 */
#ifndef PROJEKT_STRUKTURY_H
#define PROJEKT_STRUKTURY_H


/**
 * Lista trzymająca kolejne wierzchołki wychodzące ze wspólnego ojca.
 */

struct wierzcholek{
    int dane; /**< wierzchołek */
    wierzcholek *nastepny; /**< wskaźnik do następnego wierzchołka */
};

/**
 * Struktura reprezentująca graf.
 * Jest to lista list wierzchołków (synów) wychodzących z danego ojca
 */

struct ojciec{
    int dane;           /**< wierzchołek */
    bool odwiedzony;    /**< czy został odwiedzony */
    wierzcholek *synowie;   /**< wskaźnik na listę synów */
    ojciec *nastepny;       /**< wskaźnik na następnego ojca */
};

#endif //PROJEKT_STRUKTURY_H
