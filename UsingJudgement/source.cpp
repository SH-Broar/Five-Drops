#include<iostream>
#include "Judgment.h"

#include "2017180021_�����.h"
#include "2013182044_�豸��.h"
#include "OmockDirectionMove.h"
using namespace std;



int main()
{
	Judgment judgement;

	//judgement.SetYourFunc(AttackBlack_20171800091 /*����*/, DefenceBlack_20171800091, WhiteAttack_2017180021/*�İ�*/, WhiteDefence_2017180021);
	judgement.SetYourFunc(AttackBlack_2017180021 /*����*/, DefenceBlack_2017180021, WhiteAttack_Me/*�İ�*/, WhiteDefence_Me);
	judgement.GamePlay();

}