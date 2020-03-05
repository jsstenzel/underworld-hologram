#pragma once
/*
	CDictionary.h
	Declaration for the vocabulary and dictionary class.
*/

#ifndef TA_DICTIONARY_H
#define TA_DICTIONARY_H

#include "main.h"

class CDictionary {
public:
	std::vector<couple> m_vNouns;
	std::vector<couple> m_vVerbs;
	std::vector<couple> m_vAdjectives;
	std::vector<couple> m_vAdverbs;
	std::vector<couple> m_vConcatenators;
	std::vector<couple> m_vRepeaters;
	std::vector<couple> m_vPrepositions;
	std::vector<couple> m_vArticles;
	std::vector<couple> m_vConfirmations;
	std::vector<couple> m_vDenials;
};

#endif