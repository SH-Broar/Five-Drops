#include<iostream>
#include "Judgment.h"

#include "2017180021_�����.h"
#include "2013182044_�豸��.h"
#include "OmockDirectionMove.h"
#include "2017180023_������.h"
#include "2017180026_������.h"

using namespace std;



int main()
{
	Judgment judgement;

	judgement.SetYourFunc(AttackBlack_2017180026 /*����*/, DefenceBlack_2017180026, WhiteAttack_2017180021/*�İ�*/, WhiteDefence_2017180021);
	//judgement.SetYourFunc(AttackBlack_2017180023 /*����*/, DefenceBlack_2017180023, WhiteAttack_2017180026/*�İ�*/, WhiteDefence_2017180026);
	judgement.GamePlay();

}