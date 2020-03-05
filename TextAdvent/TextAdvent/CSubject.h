#pragma once
/*
	CSubject.h
	Declaration for sentence subjects.
*/

#ifndef TA_SUBJECT_H
#define TA_SUBJECT_H

#include "main.h"

class CSubject {
public:
	morpheme m_sArticle;				//Article to define the plurality of the object (the vs. a)
	morpheme m_sObject;					//The noun of the sentence
	std::list<morpheme> m_vDescriptors;	//Adjectives describing the noun
};

#endif