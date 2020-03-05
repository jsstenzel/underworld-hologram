#pragma once
/*
	CPhrase.h
	Declaration for individual command phrases.
*/

#ifndef TA_PHRASE_H
#define TA_PHRASE_H

#include "main.h"
#include "CSubject.h"

class CPhrase {
	morpheme m_sAction;								//The action to perform
	morpheme m_sDescriptor;							//Adverb describing the action
	std::pair<morpheme, CSubject> m_vConjugator;	//Article + subject to define the context of the action
	std::list<CSubject> m_vSubjects;				//List of subjects to perform the action on
};

#endif