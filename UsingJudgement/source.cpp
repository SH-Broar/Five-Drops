#include<iostream>
#include "Judgment.h"

#include "2017180021_어수혁.h"
#include "2013182044_김구조.h"
#include "OmockDirectionMove.h"
#include "2017180023_우찬희.h"
using namespace std;



int main()
{
	Judgment judgement;

	//judgement.SetYourFunc(AttackBlack_20171800091 /*선공*/, DefenceBlack_20171800091, WhiteAttack_2017180023/*후공*/, WhiteDefence_2017180023);
	judgement.SetYourFunc(AttackBlack_2017180021 /*선공*/, DefenceBlack_2017180021, WhiteAttack_2017180023/*후공*/, WhiteDefence_2017180023);
	judgement.GamePlay();

}