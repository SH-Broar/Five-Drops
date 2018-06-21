#include<iostream>
#include "Judgment.h"

#include "2017180021_어수혁.h"
#include "2013182044_김구조.h"
using namespace std;



int main()
{
	Judgment judgement;

	judgement.SetYourFunc(AttackBlack_20171800091 /*선공*/, DefenceBlack_20171800091, WhiteAttack_2017180021/*후공*/, WhiteDefence_2017180021);
	//judgement.SetYourFunc(AttackBlack_2017180021 /*선공*/, DefenceBlack_2017180021, WhiteAttack_20171800091/*후공*/, WhiteDefence_20171800091);
	judgement.GamePlay();

}