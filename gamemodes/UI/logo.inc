new Text:LogoTD[10]; //Logo

DestroyLogoTD()
{
	for (new i = 0; i < sizeof(LogoTD); i++) {TextDrawDestroy(LogoTD[i]);}
}

CreateTextdrawlogo()
{
//LogoNatuna
	LogoTD[0] = TextDrawCreate(300.000000, 6.000000, "ld_beat:chit");
	TextDrawFont(LogoTD[0], 4);
	TextDrawLetterSize(LogoTD[0], 0.600000, 2.000000);
	TextDrawTextSize(LogoTD[0], 23.000000, 23.000000);
	TextDrawSetOutline(LogoTD[0], 1);
	TextDrawSetShadow(LogoTD[0], 0);
	TextDrawAlignment(LogoTD[0], 2);
	TextDrawColor(LogoTD[0], 852308735);
	TextDrawBackgroundColor(LogoTD[0], 255);
	TextDrawBoxColor(LogoTD[0], 50);
	TextDrawUseBox(LogoTD[0], 1);
	TextDrawSetProportional(LogoTD[0], 1);
	TextDrawSetSelectable(LogoTD[0], 0);

	LogoTD[1] = TextDrawCreate(311.000000, 11.000000, "ld_beat:chit");
	TextDrawFont(LogoTD[1], 4);
	TextDrawLetterSize(LogoTD[1], 0.600000, 2.000000);
	TextDrawTextSize(LogoTD[1], 23.000000, 23.000000);
	TextDrawSetOutline(LogoTD[1], 1);
	TextDrawSetShadow(LogoTD[1], 0);
	TextDrawAlignment(LogoTD[1], 2);
	TextDrawColor(LogoTD[1], 852308735);
	TextDrawBackgroundColor(LogoTD[1], 255);
	TextDrawBoxColor(LogoTD[1], 50);
	TextDrawUseBox(LogoTD[1], 1);
	TextDrawSetProportional(LogoTD[1], 1);
	TextDrawSetSelectable(LogoTD[1], 0);

	LogoTD[2] = TextDrawCreate(313.000000, 9.800000, "ld_bum:blkdot");
	TextDrawFont(LogoTD[2], 4);
	TextDrawLetterSize(LogoTD[2], 0.600000, 2.000000);
	TextDrawTextSize(LogoTD[2], 17.000000, 11.500000);
	TextDrawSetOutline(LogoTD[2], 1);
	TextDrawSetShadow(LogoTD[2], 0);
	TextDrawAlignment(LogoTD[2], 2);
	TextDrawColor(LogoTD[2], 852308735);
	TextDrawBackgroundColor(LogoTD[2], 255);
	TextDrawBoxColor(LogoTD[2], 50);
	TextDrawUseBox(LogoTD[2], 1);
	TextDrawSetProportional(LogoTD[2], 1);
	TextDrawSetSelectable(LogoTD[2], 0);

	LogoTD[3] = TextDrawCreate(304.000000, 18.799999, "ld_bum:blkdot");
	TextDrawFont(LogoTD[3], 4);
	TextDrawLetterSize(LogoTD[3], 0.600000, 2.000000);
	TextDrawTextSize(LogoTD[3], 18.500000, 11.500000);
	TextDrawSetOutline(LogoTD[3], 1);
	TextDrawSetShadow(LogoTD[3], 0);
	TextDrawAlignment(LogoTD[3], 2);
	TextDrawColor(LogoTD[3], 852308735);
	TextDrawBackgroundColor(LogoTD[3], 255);
	TextDrawBoxColor(LogoTD[3], 50);
	TextDrawUseBox(LogoTD[3], 1);
	TextDrawSetProportional(LogoTD[3], 1);
	TextDrawSetSelectable(LogoTD[3], 0);

	LogoTD[4] = TextDrawCreate(313.000000, 9.000000, "I");
	TextDrawFont(LogoTD[4], 1);
	TextDrawLetterSize(LogoTD[4], 0.425000, 2.199999);
	TextDrawTextSize(LogoTD[4], 400.000000, 17.000000);
	TextDrawSetOutline(LogoTD[4], 0);
	TextDrawSetShadow(LogoTD[4], 0);
	TextDrawAlignment(LogoTD[4], 2);
	TextDrawColor(LogoTD[4], -1);
	TextDrawBackgroundColor(LogoTD[4], 255);
	TextDrawBoxColor(LogoTD[4], 50);
	TextDrawUseBox(LogoTD[4], 0);
	TextDrawSetProportional(LogoTD[4], 1);
	TextDrawSetSelectable(LogoTD[4], 0);

	LogoTD[5] = TextDrawCreate(322.000000, 11.000000, "R");
	TextDrawFont(LogoTD[5], 1);
	TextDrawLetterSize(LogoTD[5], 0.574999, 2.199999);
	TextDrawTextSize(LogoTD[5], 400.000000, 17.000000);
	TextDrawSetOutline(LogoTD[5], 0);
	TextDrawSetShadow(LogoTD[5], 0);
	TextDrawAlignment(LogoTD[5], 2);
	TextDrawColor(LogoTD[5], -1);
	TextDrawBackgroundColor(LogoTD[5], 255);
	TextDrawBoxColor(LogoTD[5], 50);
	TextDrawUseBox(LogoTD[5], 0);
	TextDrawSetProportional(LogoTD[5], 1);
	TextDrawSetSelectable(LogoTD[5], 0);

	LogoTD[6] = TextDrawCreate(334.000000, 8.000000, "I");
	TextDrawFont(LogoTD[6], 1);
	TextDrawLetterSize(LogoTD[6], 0.250000, 1.149999);
	TextDrawTextSize(LogoTD[6], 400.000000, 46.000000);
	TextDrawSetOutline(LogoTD[6], 0);
	TextDrawSetShadow(LogoTD[6], 0);
	TextDrawAlignment(LogoTD[6], 2);
	TextDrawColor(LogoTD[6], -1);
	TextDrawBackgroundColor(LogoTD[6], 255);
	TextDrawBoxColor(LogoTD[6], 50);
	TextDrawUseBox(LogoTD[6], 0);
	TextDrawSetProportional(LogoTD[6], 1);
	TextDrawSetSelectable(LogoTD[6], 0);

	LogoTD[7] = TextDrawCreate(334.000000, 18.000000, "R");
	TextDrawFont(LogoTD[7], 1);
	TextDrawLetterSize(LogoTD[7], 0.279166, 1.049999);
	TextDrawTextSize(LogoTD[7], 400.000000, 46.000000);
	TextDrawSetOutline(LogoTD[7], 0);
	TextDrawSetShadow(LogoTD[7], 0);
	TextDrawAlignment(LogoTD[7], 2);
	TextDrawColor(LogoTD[7], -1);
	TextDrawBackgroundColor(LogoTD[7], 255);
	TextDrawBoxColor(LogoTD[7], 50);
	TextDrawUseBox(LogoTD[7], 0);
	TextDrawSetProportional(LogoTD[7], 1);
	TextDrawSetSelectable(LogoTD[7], 0);

	LogoTD[8] = TextDrawCreate(350.000000, 8.000000, "NDOLIFE");
	TextDrawFont(LogoTD[8], 1);
	TextDrawLetterSize(LogoTD[8], 0.250000, 1.149999);
	TextDrawTextSize(LogoTD[8], 400.000000, 46.000000);
	TextDrawSetOutline(LogoTD[8], 0);
	TextDrawSetShadow(LogoTD[8], 0);
	TextDrawAlignment(LogoTD[8], 2);
	TextDrawColor(LogoTD[8], 852308735);
	TextDrawBackgroundColor(LogoTD[8], 255);
	TextDrawBoxColor(LogoTD[8], 50);
	TextDrawUseBox(LogoTD[8], 0);
	TextDrawSetProportional(LogoTD[8], 1);
	TextDrawSetSelectable(LogoTD[8], 0);

	LogoTD[9] = TextDrawCreate(352.000000, 18.000000, "ROLEPLAY");
	TextDrawFont(LogoTD[9], 1);
	TextDrawLetterSize(LogoTD[9], 0.250000, 1.149999);
	TextDrawTextSize(LogoTD[9], 400.000000, 46.000000);
	TextDrawSetOutline(LogoTD[9], 0);
	TextDrawSetShadow(LogoTD[9], 0);
	TextDrawAlignment(LogoTD[9], 2);
	TextDrawColor(LogoTD[9], 852308735);
	TextDrawBackgroundColor(LogoTD[9], 255);
	TextDrawBoxColor(LogoTD[9], 50);
	TextDrawUseBox(LogoTD[9], 0);
	TextDrawSetProportional(LogoTD[9], 1);
	TextDrawSetSelectable(LogoTD[9], 0);
}