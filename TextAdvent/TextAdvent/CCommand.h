#pragma once
/*
	CCommand.h
	Declaration for user input command object.
*/

#ifndef TA_COMMAND_H
#define TA_COMMAND_H

#include "main.h"
#include "CPhrase.h"

class CCommand {
private:
	std::list<morpheme> m_vExpression;		//The plaintext command, tokenized
	std::list<CPhrase> m_vPhrases;			//Every separate action to perform in the command
	std::list<morpheme> m_vConcatenators;	//The words separating phrases
};

#endif