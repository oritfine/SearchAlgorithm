//
// Created by yana on 21/01/2020.
//

#ifndef EX4_A_STAR_H
#define EX4_A_STAR_H
#include "Point.h"
#include "State.h"
#include "Searchable.h"
#include "Solution.h"
#include "AbstSearcher.h"

class A_star: public AbstSearcher<Searchable<State<Point*>*>*, Solution<State<Point*>*>*, State<Point*>* > {

};


#endif //EX4_A_STAR_H
