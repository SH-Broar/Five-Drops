#include<iostream>
#include "Judgment.h"

#include "2017180021_어수혁.h"
#include "2013182044_김구조.h"
#include "OmockDirectionMove.h"
#include "2017180023_우찬희.h"
#include "2017180026_윤설한.h"

using namespace std;



int main()
{
	Judgment judgement;

	judgement.SetYourFunc(AttackBlack_2017180026 /*선공*/, DefenceBlack_2017180026, WhiteAttack_2017180021/*후공*/, WhiteDefence_2017180021);
	//judgement.SetYourFunc(AttackBlack_2017180023 /*선공*/, DefenceBlack_2017180023, WhiteAttack_2017180026/*후공*/, WhiteDefence_2017180026);
	judgement.GamePlay();

}