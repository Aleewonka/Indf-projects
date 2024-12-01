enum eItemBox
{
	ItemBoxIcon,
	ItemBoxMessage[320],
	ItemBoxJumlahMessage[200],
	ItemBoxLoading,
	ItemBoxSize
}
new InfoItemBox[MAX_PLAYERS][7][eItemBox];
new MaxPlayerItemBox[MAX_PLAYERS];
new PlayerText:TextDrawItemBox[MAX_PLAYERS][7*10];
new IndexItemBox[MAX_PLAYERS];
new PlayerText:RP_NatunaTD[MAX_PLAYERS][46]; // Radial Natuna
// Resepsionis menu
new PlayerText:menu_reseptionis[MAX_PLAYERS][9];
new PlayerText:Aksi_1[MAX_PLAYERS];
new PlayerText:Aksi_2[MAX_PLAYERS];
new PlayerText:r_close[MAX_PLAYERS];
new PlayerText: indlfHbe[MAX_PLAYERS][6]; //Hbe
//death
new PlayerText:AsteraDeath[MAX_PLAYERS][5];
// MataTD
new PlayerText:MataTD[MAX_PLAYERS][2];
new PlayerText:MataBtn[MAX_PLAYERS];
new PlayerText:MataaksiBtn[MAX_PLAYERS];
new PlayerText:MataAksi[MAX_PLAYERS];
new PlayerText:MataText[MAX_PLAYERS];

//ox
new PlayerText: oxtarget[MAX_PLAYERS][8];
new PlayerText: oxtarget1[MAX_PLAYERS][5];
new PlayerText: Nexoduswithaufa[MAX_PLAYERS][34];

FUNC::HideItemBox(playerid)
{
	if(!IndexItemBox[playerid]) return 1;
	--IndexItemBox[playerid];
	MaxPlayerItemBox[playerid]--;
	for(new i=-1;++i<10;) PlayerTextDrawDestroy(playerid, TextDrawItemBox[playerid][(IndexItemBox[playerid]*10)+i]);
	return 1;
}

stock ShowItemBox(playerid, string[], total[], model, time)
{
	if(MaxPlayerItemBox[playerid] == 5) return 1;
	MaxPlayerItemBox[playerid]++;
	new validtime = time*1000;
	for(new x=-1; ++x <IndexItemBox[playerid];)
	{
		for(new i=-1;++i<9;) PlayerTextDrawDestroy(playerid, TextDrawItemBox[playerid][(x*10) + i]);
		InfoItemBox[playerid][IndexItemBox[playerid]-x] = InfoItemBox[playerid][(IndexItemBox[playerid]-x)-1];
	}
    PlayerPlaySound(playerid, 1150, 0.0, 0.0, 0.0);
	format(InfoItemBox[playerid][0][ItemBoxMessage], 320, "%s", string);
	format(InfoItemBox[playerid][0][ItemBoxJumlahMessage], 200, "%s", total);
	InfoItemBox[playerid][0][ItemBoxIcon] = model;

	++IndexItemBox[playerid];
	new Float:new_x=0.0;
	for(new x=-1;++x<IndexItemBox[playerid];)
	{
		CreateItemBox(playerid, x, x * 10, new_x);
		new_x += (InfoItemBox[playerid][x][ItemBoxSize]*7.25)+55.0;
	}
	SetTimerEx("HideItemBox", validtime, false, "d", playerid);
	return 1;
}

stock CreateItemBox(const playerid, index, i, const Float:new_x)
{
	new lines = InfoItemBox[playerid][index][ItemBoxSize];
	new Float:x = (lines * 10) + new_x;
	new Float:posisibaru = x+14.0;

    TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 375.000+posisibaru, 358.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, TextDrawItemBox[playerid][i], 43.000, 59.000);
    PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], 741032191);
    PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 255);
    PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 4);
    PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);

    TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 375.000+posisibaru, 416.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, TextDrawItemBox[playerid][i], 43.000, 1.000);
    PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], 2070474495);
    PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 255);
    PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 4);
    PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);

    TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 378.000+posisibaru, 360.000, InfoItemBox[playerid][index][ItemBoxJumlahMessage]);
    PlayerTextDrawLetterSize(playerid, TextDrawItemBox[playerid][i], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], -1);
    PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 150);
    PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);

    TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 386.000+posisibaru, 405.000, InfoItemBox[playerid][index][ItemBoxMessage]);
    PlayerTextDrawLetterSize(playerid, TextDrawItemBox[playerid][i], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], -1);
    PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 150);
    PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);

    TextDrawItemBox[playerid][++i] = CreatePlayerTextDraw(playerid, 374.000+posisibaru, 364.000, "_");
    PlayerTextDrawTextSize(playerid, TextDrawItemBox[playerid][i], 43.000, 39.000);
    PlayerTextDrawAlignment(playerid, TextDrawItemBox[playerid][i], 1);
    PlayerTextDrawColor(playerid, TextDrawItemBox[playerid][i], -1);
    PlayerTextDrawSetShadow(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawSetOutline(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawBackgroundColor(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawFont(playerid, TextDrawItemBox[playerid][i], 5);
    PlayerTextDrawSetProportional(playerid, TextDrawItemBox[playerid][i], 0);
    PlayerTextDrawSetPreviewModel(playerid, TextDrawItemBox[playerid][i], InfoItemBox[playerid][index][ItemBoxIcon]);
    PlayerTextDrawSetPreviewRot(playerid, TextDrawItemBox[playerid][i], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, TextDrawItemBox[playerid][i], 0, 0);
    PlayerTextDrawShow(playerid, TextDrawItemBox[playerid][i]);
	return true;
}

CreatePlayerTextDrawsId(playerid)
{
	//HBE INDLF
	indlfHbe[playerid][0] = CreatePlayerTextDraw(playerid, 275.000, 412.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, indlfHbe[playerid][0], 30.000, 30.000);
	PlayerTextDrawAlignment(playerid, indlfHbe[playerid][0], 1);
	PlayerTextDrawColor(playerid, indlfHbe[playerid][0], -16777116);
	PlayerTextDrawSetShadow(playerid, indlfHbe[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, indlfHbe[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, indlfHbe[playerid][0], 255);
	PlayerTextDrawFont(playerid, indlfHbe[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, indlfHbe[playerid][0], 1);

	indlfHbe[playerid][1] = CreatePlayerTextDraw(playerid, 300.000, 412.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, indlfHbe[playerid][1], 30.000, 30.000);
	PlayerTextDrawAlignment(playerid, indlfHbe[playerid][1], 1);
	PlayerTextDrawColor(playerid, indlfHbe[playerid][1], 1097458175);
	PlayerTextDrawSetShadow(playerid, indlfHbe[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, indlfHbe[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, indlfHbe[playerid][1], 255);
	PlayerTextDrawFont(playerid, indlfHbe[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, indlfHbe[playerid][1], 1);

	indlfHbe[playerid][2] = CreatePlayerTextDraw(playerid, 324.000, 412.000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, indlfHbe[playerid][2], 30.000, 30.000);
	PlayerTextDrawAlignment(playerid, indlfHbe[playerid][2], 1);
	PlayerTextDrawColor(playerid, indlfHbe[playerid][2], -12254977);
	PlayerTextDrawSetShadow(playerid, indlfHbe[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, indlfHbe[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, indlfHbe[playerid][2], 255);
	PlayerTextDrawFont(playerid, indlfHbe[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, indlfHbe[playerid][2], 1);

	indlfHbe[playerid][3] = CreatePlayerTextDraw(playerid, 285.000, 421.000, "HUD:radar_burgerShot");
	PlayerTextDrawTextSize(playerid, indlfHbe[playerid][3], 10.000, 10.000);
	PlayerTextDrawAlignment(playerid, indlfHbe[playerid][3], 1);
	PlayerTextDrawColor(playerid, indlfHbe[playerid][3], -145);
	PlayerTextDrawSetShadow(playerid, indlfHbe[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, indlfHbe[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, indlfHbe[playerid][3], 255);
	PlayerTextDrawFont(playerid, indlfHbe[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, indlfHbe[playerid][3], 1);

	indlfHbe[playerid][4] = CreatePlayerTextDraw(playerid, 310.000, 421.000, "HUD:radar_dateDrink");
	PlayerTextDrawTextSize(playerid, indlfHbe[playerid][4], 10.000, 10.000);
	PlayerTextDrawAlignment(playerid, indlfHbe[playerid][4], 1);
	PlayerTextDrawColor(playerid, indlfHbe[playerid][4], -138);
	PlayerTextDrawSetShadow(playerid, indlfHbe[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, indlfHbe[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, indlfHbe[playerid][4], 255);
	PlayerTextDrawFont(playerid, indlfHbe[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, indlfHbe[playerid][4], 1);

	indlfHbe[playerid][5] = CreatePlayerTextDraw(playerid, 335.000, 421.000, "HUD:radar_centre");
	PlayerTextDrawTextSize(playerid, indlfHbe[playerid][5], 10.000, 10.000);
	PlayerTextDrawAlignment(playerid, indlfHbe[playerid][5], 1);
	PlayerTextDrawColor(playerid, indlfHbe[playerid][5], -144);
	PlayerTextDrawSetShadow(playerid, indlfHbe[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, indlfHbe[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, indlfHbe[playerid][5], 255);
	PlayerTextDrawFont(playerid, indlfHbe[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, indlfHbe[playerid][5], 1);

	//RadialPlayerNatuna
	RP_NatunaTD[playerid][0] = CreatePlayerTextDraw(playerid, 122.000000, 199.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][0], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][0], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][0], 25.000000, 28.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][0], 852308680);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][0], 0);

	RP_NatunaTD[playerid][1] = CreatePlayerTextDraw(playerid, 152.000000, 199.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][1], 25.000000, 28.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][1], 852308680);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][1], 0);

	RP_NatunaTD[playerid][2] = CreatePlayerTextDraw(playerid, 181.000000, 199.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][2], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][2], 25.000000, 28.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][2], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][2], 852308680);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][2], 0);

	RP_NatunaTD[playerid][3] = CreatePlayerTextDraw(playerid, 211.000000, 199.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][3], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][3], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][3], 25.000000, 28.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][3], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][3], 852308680);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][3], 0);

	RP_NatunaTD[playerid][4] = CreatePlayerTextDraw(playerid, 137.000000, 233.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][4], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][4], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][4], 25.000000, 28.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][4], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][4], 852308680);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][4], 0);

	RP_NatunaTD[playerid][5] = CreatePlayerTextDraw(playerid, 167.000000, 233.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][5], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][5], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][5], 25.000000, 28.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][5], 852308680);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][5], 0);

	RP_NatunaTD[playerid][6] = CreatePlayerTextDraw(playerid, 197.000000, 233.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][6], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][6], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][6], 25.000000, 28.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][6], 852308680);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][6], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][6], 0);

	RP_NatunaTD[playerid][7] = CreatePlayerTextDraw(playerid, 123.000000, 200.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][7], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][7], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][7], 23.000000, 20.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][7], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][7], 9109704);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][7], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][7], 1);

	RP_NatunaTD[playerid][8] = CreatePlayerTextDraw(playerid, 153.000000, 200.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][8], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][8], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][8], 23.000000, 20.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][8], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][8], 9109704);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][8], 1);

	RP_NatunaTD[playerid][9] = CreatePlayerTextDraw(playerid, 182.000000, 200.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][9], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][9], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][9], 23.000000, 20.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][9], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][9], 9109704);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][9], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][9], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][9], 1);

	RP_NatunaTD[playerid][10] = CreatePlayerTextDraw(playerid, 212.000000, 200.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][10], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][10], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][10], 23.000000, 20.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][10], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][10], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][10], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][10], 9109704);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][10], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][10], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][10], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][10], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][10], 1);

	RP_NatunaTD[playerid][11] = CreatePlayerTextDraw(playerid, 138.000000, 234.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][11], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][11], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][11], 23.000000, 20.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][11], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][11], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][11], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][11], 9109704);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][11], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][11], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][11], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][11], 1);

	RP_NatunaTD[playerid][12] = CreatePlayerTextDraw(playerid, 168.000000, 234.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][12], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][12], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][12], 23.000000, 20.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][12], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][12], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][12], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][12], 9109704);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][12], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][12], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][12], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][12], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][12], 1);

	RP_NatunaTD[playerid][13] = CreatePlayerTextDraw(playerid, 198.000000, 234.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][13], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][13], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][13], 23.000000, 20.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][13], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][13], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][13], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][13], 9109704);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][13], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][13], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][13], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][13], 1);

	RP_NatunaTD[playerid][14] = CreatePlayerTextDraw(playerid, 124.000000, 197.000000, "Preview_Model");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][14], 5);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][14], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][14], 20.500000, 26.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][14], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][14], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][14], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][14], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][14], 0);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][14], 255);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][14], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][14], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][14], 0);
	PlayerTextDrawSetPreviewModel(playerid, RP_NatunaTD[playerid][14], 1581);
	PlayerTextDrawSetPreviewRot(playerid, RP_NatunaTD[playerid][14], -4.000000, 0.000000, 0.000000, 1.000000);
	PlayerTextDrawSetPreviewVehCol(playerid, RP_NatunaTD[playerid][14], 1, 1);

	RP_NatunaTD[playerid][15] = CreatePlayerTextDraw(playerid, 158.000000, 200.000000, "/");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][15], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][15], 0.237500, 1.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][15], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][15], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][15], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][15], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][15], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][15], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][15], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][15], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][15], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][15], 0);

	RP_NatunaTD[playerid][16] = CreatePlayerTextDraw(playerid, 164.000000, 197.000000, "-");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][16], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][16], 1.066666, 1.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][16], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][16], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][16], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][16], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][16], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][16], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][16], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][16], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][16], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][16], 0);

	RP_NatunaTD[playerid][17] = CreatePlayerTextDraw(playerid, 170.000000, 200.000000, "\\");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][17], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][17], 0.237500, 1.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][17], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][17], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][17], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][17], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][17], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][17], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][17], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][17], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][17], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][17], 0);

	RP_NatunaTD[playerid][18] = CreatePlayerTextDraw(playerid, 156.000000, 207.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][18], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][18], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][18], 16.000000, 8.500000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][18], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][18], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][18], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][18], -741092353);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][18], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][18], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][18], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][18], 0);

	RP_NatunaTD[playerid][19] = CreatePlayerTextDraw(playerid, 155.000000, 214.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][19], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][19], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][19], 3.500000, 6.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][19], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][19], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][19], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][19], -741092353);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][19], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][19], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][19], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][19], 0);

	RP_NatunaTD[playerid][20] = CreatePlayerTextDraw(playerid, 169.000000, 214.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][20], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][20], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][20], 3.500000, 6.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][20], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][20], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][20], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][20], -741092353);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][20], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][20], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][20], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][20], 0);

	RP_NatunaTD[playerid][21] = CreatePlayerTextDraw(playerid, 185.000000, 207.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][21], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][21], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][21], 16.000000, 8.500000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][21], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][21], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][21], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][21], -741092353);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][21], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][21], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][21], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][21], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][21], 0);

	RP_NatunaTD[playerid][22] = CreatePlayerTextDraw(playerid, 187.000000, 200.000000, "/");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][22], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][22], 0.237500, 1.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][22], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][22], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][22], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][22], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][22], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][22], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][22], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][22], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][22], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][22], 0);

	RP_NatunaTD[playerid][23] = CreatePlayerTextDraw(playerid, 193.000000, 197.000000, "-");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][23], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][23], 1.066666, 1.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][23], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][23], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][23], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][23], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][23], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][23], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][23], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][23], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][23], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][23], 0);

	RP_NatunaTD[playerid][24] = CreatePlayerTextDraw(playerid, 199.000000, 200.000000, "\\");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][24], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][24], 0.237500, 1.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][24], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][24], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][24], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][24], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][24], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][24], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][24], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][24], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][24], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][24], 0);

	RP_NatunaTD[playerid][25] = CreatePlayerTextDraw(playerid, 193.000000, 207.000000, "I");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][25], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][25], 0.300000, 1.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][25], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][25], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][25], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][25], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][25], 9109759);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][25], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][25], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][25], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][25], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][25], 0);

	RP_NatunaTD[playerid][26] = CreatePlayerTextDraw(playerid, 217.000000, 203.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][26], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][26], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][26], 12.500000, 14.500000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][26], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][26], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][26], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][26], -741092353);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][26], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][26], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][26], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][26], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][26], 0);

	RP_NatunaTD[playerid][27] = CreatePlayerTextDraw(playerid, 218.000000, 204.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][27], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][27], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][27], 10.500000, 12.500000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][27], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][27], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][27], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][27], 9109759);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][27], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][27], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][27], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][27], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][27], 0);

	RP_NatunaTD[playerid][28] = CreatePlayerTextDraw(playerid, 221.000000, 212.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][28], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][28], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][28], 3.500000, 4.500000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][28], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][28], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][28], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][28], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][28], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][28], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][28], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][28], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][28], 0);

	RP_NatunaTD[playerid][29] = CreatePlayerTextDraw(playerid, 141.000000, 248.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][29], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][29], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][29], 16.000000, 2.500000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][29], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][29], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][29], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][29], -741092353);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][29], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][29], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][29], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][29], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][29], 0);

	RP_NatunaTD[playerid][30] = CreatePlayerTextDraw(playerid, 149.000000, 234.000000, "$");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][30], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][30], 0.433333, 1.500002);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][30], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][30], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][30], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][30], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][30], -741092353);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][30], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][30], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][30], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][30], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][30], 0);

	RP_NatunaTD[playerid][31] = CreatePlayerTextDraw(playerid, 173.000000, 235.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][31], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][31], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][31], 12.000000, 12.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][31], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][31], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][31], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][31], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][31], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][31], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][31], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][31], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][31], 0);

	RP_NatunaTD[playerid][32] = CreatePlayerTextDraw(playerid, 171.500000, 245.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][32], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][32], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][32], 15.000000, 9.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][32], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][32], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][32], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][32], -1);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][32], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][32], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][32], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][32], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][32], 0);

	RP_NatunaTD[playerid][33] = CreatePlayerTextDraw(playerid, 204.000000, 238.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][33], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][33], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][33], 10.500000, 13.500000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][33], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][33], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][33], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][33], -741092353);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][33], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][33], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][33], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][33], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][33], 0);

	RP_NatunaTD[playerid][34] = CreatePlayerTextDraw(playerid, 200.000000, 238.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][34], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][34], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][34], 18.500000, 5.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][34], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][34], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][34], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][34], -741092353);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][34], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][34], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][34], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][34], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][34], 0);

	RP_NatunaTD[playerid][35] = CreatePlayerTextDraw(playerid, 209.000000, 232.000000, "v");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][35], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][35], 0.433333, 1.500002);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][35], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][35], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][35], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][35], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][35], 9109759);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][35], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][35], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][35], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][35], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][35], 0);

	RP_NatunaTD[playerid][36] = CreatePlayerTextDraw(playerid, 134.000000, 218.000000, "document");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][36], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][36], 0.133333, 1.000003);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][36], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][36], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][36], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][36], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][36], 1433087999);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][36], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][36], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][36], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][36], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][36], 0);

	RP_NatunaTD[playerid][37] = CreatePlayerTextDraw(playerid, 164.000000, 218.000000, "kendaraan");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][37], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][37], 0.133333, 1.000003);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][37], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][37], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][37], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][37], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][37], 1433087999);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][37], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][37], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][37], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][37], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][37], 0);

	RP_NatunaTD[playerid][38] = CreatePlayerTextDraw(playerid, 193.000000, 218.000000, "Inventory");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][38], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][38], 0.133333, 1.000003);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][38], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][38], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][38], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][38], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][38], 1433087999);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][38], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][38], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][38], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][38], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][38], 0);

	RP_NatunaTD[playerid][39] = CreatePlayerTextDraw(playerid, 224.000000, 218.000000, "Phonsel");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][39], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][39], 0.133333, 1.000003);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][39], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][39], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][39], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][39], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][39], 1433087999);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][39], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][39], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][39], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][39], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][39], 0);

	RP_NatunaTD[playerid][40] = CreatePlayerTextDraw(playerid, 149.000000, 252.000000, "Payment");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][40], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][40], 0.133333, 1.000003);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][40], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][40], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][40], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][40], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][40], 1433087999);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][40], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][40], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][40], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][40], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][40], 0);

	RP_NatunaTD[playerid][41] = CreatePlayerTextDraw(playerid, 179.000000, 252.000000, "Action");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][41], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][41], 0.133333, 1.000003);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][41], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][41], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][41], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][41], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][41], 1433087999);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][41], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][41], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][41], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][41], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][41], 0);

	RP_NatunaTD[playerid][42] = CreatePlayerTextDraw(playerid, 209.000000, 252.000000, "Pakaian");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][42], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][42], 0.133333, 1.000003);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][42], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][42], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][42], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][42], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][42], 1433087999);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][42], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][42], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][42], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][42], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][42], 0);

	RP_NatunaTD[playerid][43] = CreatePlayerTextDraw(playerid, 162.000000, 270.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][43], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][43], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][43], 35.000000, 14.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][43], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][43], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][43], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][43], 852308680);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][43], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][43], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][43], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][43], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][43], 0);

	RP_NatunaTD[playerid][44] = CreatePlayerTextDraw(playerid, 163.000000, 271.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][44], 4);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][44], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][44], 33.000000, 12.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][44], 1);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][44], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][44], 1);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][44], 9109704);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][44], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][44], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][44], 1);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][44], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][44], 1);

	RP_NatunaTD[playerid][45] = CreatePlayerTextDraw(playerid, 179.000000, 270.000000, "Close");
	PlayerTextDrawFont(playerid, RP_NatunaTD[playerid][45], 1);
	PlayerTextDrawLetterSize(playerid, RP_NatunaTD[playerid][45], 0.150000, 1.450002);
	PlayerTextDrawTextSize(playerid, RP_NatunaTD[playerid][45], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, RP_NatunaTD[playerid][45], 0);
	PlayerTextDrawSetShadow(playerid, RP_NatunaTD[playerid][45], 0);
	PlayerTextDrawAlignment(playerid, RP_NatunaTD[playerid][45], 2);
	PlayerTextDrawColor(playerid, RP_NatunaTD[playerid][45], -1094795521);
	PlayerTextDrawBackgroundColor(playerid, RP_NatunaTD[playerid][45], 255);
	PlayerTextDrawBoxColor(playerid, RP_NatunaTD[playerid][45], 50);
	PlayerTextDrawUseBox(playerid, RP_NatunaTD[playerid][45], 0);
	PlayerTextDrawSetProportional(playerid, RP_NatunaTD[playerid][45], 1);
	PlayerTextDrawSetSelectable(playerid, RP_NatunaTD[playerid][45], 0);

	//Playerresepsionismenu
	menu_reseptionis[playerid][0] = CreatePlayerTextDraw(playerid, 379.000000, 196.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, menu_reseptionis[playerid][0], 4);
	PlayerTextDrawLetterSize(playerid, menu_reseptionis[playerid][0], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, menu_reseptionis[playerid][0], 83.500000, 15.500000);
	PlayerTextDrawSetOutline(playerid, menu_reseptionis[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, menu_reseptionis[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, menu_reseptionis[playerid][0], 1);
	PlayerTextDrawColor(playerid, menu_reseptionis[playerid][0], -1061109505);
	PlayerTextDrawBackgroundColor(playerid, menu_reseptionis[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, menu_reseptionis[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, menu_reseptionis[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, menu_reseptionis[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, menu_reseptionis[playerid][0], 0);

	menu_reseptionis[playerid][1] = CreatePlayerTextDraw(playerid, 379.000000, 214.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, menu_reseptionis[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, menu_reseptionis[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, menu_reseptionis[playerid][1], 83.500000, 15.500000);
	PlayerTextDrawSetOutline(playerid, menu_reseptionis[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, menu_reseptionis[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, menu_reseptionis[playerid][1], 1);
	PlayerTextDrawColor(playerid, menu_reseptionis[playerid][1], -1061109505);
	PlayerTextDrawBackgroundColor(playerid, menu_reseptionis[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, menu_reseptionis[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, menu_reseptionis[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, menu_reseptionis[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, menu_reseptionis[playerid][1], 0);

	menu_reseptionis[playerid][2] = CreatePlayerTextDraw(playerid, 379.000000, 232.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, menu_reseptionis[playerid][2], 4);
	PlayerTextDrawLetterSize(playerid, menu_reseptionis[playerid][2], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, menu_reseptionis[playerid][2], 83.500000, 15.500000);
	PlayerTextDrawSetOutline(playerid, menu_reseptionis[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, menu_reseptionis[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, menu_reseptionis[playerid][2], 1);
	PlayerTextDrawColor(playerid, menu_reseptionis[playerid][2], -1061109505);
	PlayerTextDrawBackgroundColor(playerid, menu_reseptionis[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, menu_reseptionis[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, menu_reseptionis[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, menu_reseptionis[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, menu_reseptionis[playerid][2], 0);

	menu_reseptionis[playerid][3] = CreatePlayerTextDraw(playerid, 379.000000, 250.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, menu_reseptionis[playerid][3], 4);
	PlayerTextDrawLetterSize(playerid, menu_reseptionis[playerid][3], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, menu_reseptionis[playerid][3], 83.500000, 15.500000);
	PlayerTextDrawSetOutline(playerid, menu_reseptionis[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, menu_reseptionis[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, menu_reseptionis[playerid][3], 1);
	PlayerTextDrawColor(playerid, menu_reseptionis[playerid][3], -1061109505);
	PlayerTextDrawBackgroundColor(playerid, menu_reseptionis[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, menu_reseptionis[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, menu_reseptionis[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, menu_reseptionis[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, menu_reseptionis[playerid][3], 0);

	menu_reseptionis[playerid][4] = CreatePlayerTextDraw(playerid, 379.000000, 196.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, menu_reseptionis[playerid][4], 4);
	PlayerTextDrawLetterSize(playerid, menu_reseptionis[playerid][4], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, menu_reseptionis[playerid][4], 83.500000, 15.500000);
	PlayerTextDrawSetOutline(playerid, menu_reseptionis[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, menu_reseptionis[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, menu_reseptionis[playerid][4], 1);
	PlayerTextDrawColor(playerid, menu_reseptionis[playerid][4], 852308700);
	PlayerTextDrawBackgroundColor(playerid, menu_reseptionis[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, menu_reseptionis[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, menu_reseptionis[playerid][4], 1);
	PlayerTextDrawSetProportional(playerid, menu_reseptionis[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, menu_reseptionis[playerid][4], 0);

	Aksi_1[playerid] = CreatePlayerTextDraw(playerid, 382.000000, 214.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, Aksi_1[playerid], 4);
	PlayerTextDrawLetterSize(playerid, Aksi_1[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Aksi_1[playerid], 77.500000, 15.500000);
	PlayerTextDrawSetOutline(playerid, Aksi_1[playerid], 1);
	PlayerTextDrawSetShadow(playerid, Aksi_1[playerid], 0);
	PlayerTextDrawAlignment(playerid, Aksi_1[playerid], 1);
	PlayerTextDrawColor(playerid, Aksi_1[playerid], 852308700);
	PlayerTextDrawBackgroundColor(playerid, Aksi_1[playerid], 255);
	PlayerTextDrawBoxColor(playerid, Aksi_1[playerid], 50);
	PlayerTextDrawUseBox(playerid, Aksi_1[playerid], 1);
	PlayerTextDrawSetProportional(playerid, Aksi_1[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Aksi_1[playerid], 1);

	Aksi_2[playerid] = CreatePlayerTextDraw(playerid, 382.000000, 232.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, Aksi_2[playerid], 4);
	PlayerTextDrawLetterSize(playerid, Aksi_2[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, Aksi_2[playerid], 77.500000, 15.500000);
	PlayerTextDrawSetOutline(playerid, Aksi_2[playerid], 1);
	PlayerTextDrawSetShadow(playerid, Aksi_2[playerid], 0);
	PlayerTextDrawAlignment(playerid, Aksi_2[playerid], 1);
	PlayerTextDrawColor(playerid, Aksi_2[playerid], 852308700);
	PlayerTextDrawBackgroundColor(playerid, Aksi_2[playerid], 255);
	PlayerTextDrawBoxColor(playerid, Aksi_2[playerid], 50);
	PlayerTextDrawUseBox(playerid, Aksi_2[playerid], 1);
	PlayerTextDrawSetProportional(playerid, Aksi_2[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, Aksi_2[playerid], 1);

	r_close[playerid] = CreatePlayerTextDraw(playerid, 379.000000, 250.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, r_close[playerid], 4);
	PlayerTextDrawLetterSize(playerid, r_close[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, r_close[playerid], 84.000000, 15.500000);
	PlayerTextDrawSetOutline(playerid, r_close[playerid], 1);
	PlayerTextDrawSetShadow(playerid, r_close[playerid], 0);
	PlayerTextDrawAlignment(playerid, r_close[playerid], 1);
	PlayerTextDrawColor(playerid, r_close[playerid], 852308700);
	PlayerTextDrawBackgroundColor(playerid, r_close[playerid], 255);
	PlayerTextDrawBoxColor(playerid, r_close[playerid], 50);
	PlayerTextDrawUseBox(playerid, r_close[playerid], 1);
	PlayerTextDrawSetProportional(playerid, r_close[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, r_close[playerid], 1);

	menu_reseptionis[playerid][5] = CreatePlayerTextDraw(playerid, 420.000000, 197.000000, "Resepsionis");
	PlayerTextDrawFont(playerid, menu_reseptionis[playerid][5], 1);
	PlayerTextDrawLetterSize(playerid, menu_reseptionis[playerid][5], 0.220833, 1.350000);
	PlayerTextDrawTextSize(playerid, menu_reseptionis[playerid][5], 404.500000, 80.500000);
	PlayerTextDrawSetOutline(playerid, menu_reseptionis[playerid][5], 0);
	PlayerTextDrawSetShadow(playerid, menu_reseptionis[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, menu_reseptionis[playerid][5], 2);
	PlayerTextDrawColor(playerid, menu_reseptionis[playerid][5], -46);
	PlayerTextDrawBackgroundColor(playerid, menu_reseptionis[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, menu_reseptionis[playerid][5], 50);
	PlayerTextDrawUseBox(playerid, menu_reseptionis[playerid][5], 0);
	PlayerTextDrawSetProportional(playerid, menu_reseptionis[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, menu_reseptionis[playerid][5], 0);

	menu_reseptionis[playerid][6] = CreatePlayerTextDraw(playerid, 420.000000, 215.000000, "Ambil Bansos");
	PlayerTextDrawFont(playerid, menu_reseptionis[playerid][6], 1);
	PlayerTextDrawLetterSize(playerid, menu_reseptionis[playerid][6], 0.166666, 1.200000);
	PlayerTextDrawTextSize(playerid, menu_reseptionis[playerid][6], 404.500000, 80.500000);
	PlayerTextDrawSetOutline(playerid, menu_reseptionis[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, menu_reseptionis[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, menu_reseptionis[playerid][6], 2);
	PlayerTextDrawColor(playerid, menu_reseptionis[playerid][6], -741092353);
	PlayerTextDrawBackgroundColor(playerid, menu_reseptionis[playerid][6], 255);
	PlayerTextDrawBoxColor(playerid, menu_reseptionis[playerid][6], 50);
	PlayerTextDrawUseBox(playerid, menu_reseptionis[playerid][6], 0);
	PlayerTextDrawSetProportional(playerid, menu_reseptionis[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, menu_reseptionis[playerid][6], 0);

	menu_reseptionis[playerid][7] = CreatePlayerTextDraw(playerid, 420.000000, 233.000000, "Menyewa kendaraan");
	PlayerTextDrawFont(playerid, menu_reseptionis[playerid][7], 1);
	PlayerTextDrawLetterSize(playerid, menu_reseptionis[playerid][7], 0.166666, 1.200000);
	PlayerTextDrawTextSize(playerid, menu_reseptionis[playerid][7], 404.500000, 80.500000);
	PlayerTextDrawSetOutline(playerid, menu_reseptionis[playerid][7], 0);
	PlayerTextDrawSetShadow(playerid, menu_reseptionis[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, menu_reseptionis[playerid][7], 2);
	PlayerTextDrawColor(playerid, menu_reseptionis[playerid][7], -741092353);
	PlayerTextDrawBackgroundColor(playerid, menu_reseptionis[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, menu_reseptionis[playerid][7], 50);
	PlayerTextDrawUseBox(playerid, menu_reseptionis[playerid][7], 0);
	PlayerTextDrawSetProportional(playerid, menu_reseptionis[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, menu_reseptionis[playerid][7], 0);

	menu_reseptionis[playerid][8] = CreatePlayerTextDraw(playerid, 420.000000, 250.000000, "Close");
	PlayerTextDrawFont(playerid, menu_reseptionis[playerid][8], 1);
	PlayerTextDrawLetterSize(playerid, menu_reseptionis[playerid][8], 0.220833, 1.350000);
	PlayerTextDrawTextSize(playerid, menu_reseptionis[playerid][8], 404.500000, 80.500000);
	PlayerTextDrawSetOutline(playerid, menu_reseptionis[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, menu_reseptionis[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, menu_reseptionis[playerid][8], 2);
	PlayerTextDrawColor(playerid, menu_reseptionis[playerid][8], -46);
	PlayerTextDrawBackgroundColor(playerid, menu_reseptionis[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, menu_reseptionis[playerid][8], 50);
	PlayerTextDrawUseBox(playerid, menu_reseptionis[playerid][8], 0);
	PlayerTextDrawSetProportional(playerid, menu_reseptionis[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, menu_reseptionis[playerid][8], 0);
	// MataTD
	MataTD[playerid][0] = CreatePlayerTextDraw(playerid, 310.000000, 207.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, MataTD[playerid][0], 4);
	PlayerTextDrawLetterSize(playerid, MataTD[playerid][0], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, MataTD[playerid][0], 17.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, MataTD[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, MataTD[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, MataTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, MataTD[playerid][0], 852308735);
	PlayerTextDrawBackgroundColor(playerid, MataTD[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, MataTD[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, MataTD[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, MataTD[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, MataTD[playerid][0], 0);

	MataBtn[playerid] = CreatePlayerTextDraw(playerid, 306.000000, 209.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, MataBtn[playerid], 4);
	PlayerTextDrawLetterSize(playerid, MataBtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, MataBtn[playerid], 25.000000, 13.500000);
	PlayerTextDrawSetOutline(playerid, MataBtn[playerid], 1);
	PlayerTextDrawSetShadow(playerid, MataBtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, MataBtn[playerid], 1);
	PlayerTextDrawColor(playerid, MataBtn[playerid], 852308735);
	PlayerTextDrawBackgroundColor(playerid, MataBtn[playerid], -16776961);
	PlayerTextDrawBoxColor(playerid, MataBtn[playerid], 50);
	PlayerTextDrawUseBox(playerid, MataBtn[playerid], 1);
	PlayerTextDrawSetProportional(playerid, MataBtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MataBtn[playerid], 1);

	MataTD[playerid][1] = CreatePlayerTextDraw(playerid, 313.000000, 210.000000, "ld_beat:chit");
	PlayerTextDrawFont(playerid, MataTD[playerid][1], 4);
	PlayerTextDrawLetterSize(playerid, MataTD[playerid][1], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, MataTD[playerid][1], 11.500000, 11.500000);
	PlayerTextDrawSetOutline(playerid, MataTD[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, MataTD[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, MataTD[playerid][1], 1);
	PlayerTextDrawColor(playerid, MataTD[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, MataTD[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, MataTD[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, MataTD[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, MataTD[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, MataTD[playerid][1], 0);

	MataaksiBtn[playerid] = CreatePlayerTextDraw(playerid, 332.000000, 210.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, MataaksiBtn[playerid], 4);
	PlayerTextDrawLetterSize(playerid, MataaksiBtn[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, MataaksiBtn[playerid], 62.000000, 13.000000);
	PlayerTextDrawSetOutline(playerid, MataaksiBtn[playerid], 1);
	PlayerTextDrawSetShadow(playerid, MataaksiBtn[playerid], 0);
	PlayerTextDrawAlignment(playerid, MataaksiBtn[playerid], 1);
	PlayerTextDrawColor(playerid, MataaksiBtn[playerid], 852308735);
	PlayerTextDrawBackgroundColor(playerid, MataaksiBtn[playerid], -16776961);
	PlayerTextDrawBoxColor(playerid, MataaksiBtn[playerid], 50);
	PlayerTextDrawUseBox(playerid, MataaksiBtn[playerid], 1);
	PlayerTextDrawSetProportional(playerid, MataaksiBtn[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MataaksiBtn[playerid], 1);

	MataAksi[playerid] = CreatePlayerTextDraw(playerid, 332.000000, 210.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, MataAksi[playerid], 4);
	PlayerTextDrawLetterSize(playerid, MataAksi[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, MataAksi[playerid], 1.500000, 13.000000);
	PlayerTextDrawSetOutline(playerid, MataAksi[playerid], 1);
	PlayerTextDrawSetShadow(playerid, MataAksi[playerid], 0);
	PlayerTextDrawAlignment(playerid, MataAksi[playerid], 1);
	PlayerTextDrawColor(playerid, MataAksi[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MataAksi[playerid], 255);
	PlayerTextDrawBoxColor(playerid, MataAksi[playerid], 50);
	PlayerTextDrawUseBox(playerid, MataAksi[playerid], 1);
	PlayerTextDrawSetProportional(playerid, MataAksi[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MataAksi[playerid], 0);

	MataText[playerid] = CreatePlayerTextDraw(playerid, 336.000000, 210.000000, "Resepsionis");
	PlayerTextDrawFont(playerid, MataText[playerid], 1);
	PlayerTextDrawLetterSize(playerid, MataText[playerid], 0.225000, 1.150000);
	PlayerTextDrawTextSize(playerid, MataText[playerid], 400.000000, 17.000000);
	PlayerTextDrawSetOutline(playerid, MataText[playerid], 0);
	PlayerTextDrawSetShadow(playerid, MataText[playerid], 0);
	PlayerTextDrawAlignment(playerid, MataText[playerid], 1);
	PlayerTextDrawColor(playerid, MataText[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, MataText[playerid], 255);
	PlayerTextDrawBoxColor(playerid, MataText[playerid], 50);
	PlayerTextDrawUseBox(playerid, MataText[playerid], 0);
	PlayerTextDrawSetProportional(playerid, MataText[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, MataText[playerid], 0);

	oxtarget1[playerid][0] = CreatePlayerTextDraw(playerid, 310.000, 179.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget1[playerid][0], 18.000, 16.000);
    PlayerTextDrawAlignment(playerid, oxtarget1[playerid][0], 1);
    PlayerTextDrawColor(playerid, oxtarget1[playerid][0], 1768516095);
    PlayerTextDrawSetShadow(playerid, oxtarget1[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget1[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget1[playerid][0], 255);
    PlayerTextDrawFont(playerid, oxtarget1[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget1[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, oxtarget1[playerid][0], 1);

    oxtarget1[playerid][1] = CreatePlayerTextDraw(playerid, 316.000, 182.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget1[playerid][1], 13.000, 10.000);
    PlayerTextDrawAlignment(playerid, oxtarget1[playerid][1], 1);
    PlayerTextDrawColor(playerid, oxtarget1[playerid][1], 1768516095);
    PlayerTextDrawSetShadow(playerid, oxtarget1[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget1[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget1[playerid][1], 255);
    PlayerTextDrawFont(playerid, oxtarget1[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget1[playerid][1], 1);

    oxtarget1[playerid][2] = CreatePlayerTextDraw(playerid, 309.000, 182.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget1[playerid][2], 13.000, 10.000);
    PlayerTextDrawAlignment(playerid, oxtarget1[playerid][2], 1);
    PlayerTextDrawColor(playerid, oxtarget1[playerid][2], 1768516095);
    PlayerTextDrawSetShadow(playerid, oxtarget1[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget1[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget1[playerid][2], 255);
    PlayerTextDrawFont(playerid, oxtarget1[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget1[playerid][2], 1);

    oxtarget1[playerid][3] = CreatePlayerTextDraw(playerid, 314.000, 182.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget1[playerid][3], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, oxtarget1[playerid][3], 1);
    PlayerTextDrawColor(playerid, oxtarget1[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, oxtarget1[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget1[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget1[playerid][3], 255);
    PlayerTextDrawFont(playerid, oxtarget1[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget1[playerid][3], 1);

    oxtarget1[playerid][4] = CreatePlayerTextDraw(playerid, 316.000, 184.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget1[playerid][4], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, oxtarget1[playerid][4], 1);
    PlayerTextDrawColor(playerid, oxtarget1[playerid][4], 1768516095);
    PlayerTextDrawSetShadow(playerid, oxtarget1[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget1[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget1[playerid][4], 255);
    PlayerTextDrawFont(playerid, oxtarget1[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget1[playerid][4], 1);

    //ox target
    oxtarget[playerid][0] = CreatePlayerTextDraw(playerid, 310.000, 179.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget[playerid][0], 18.000, 16.000);
    PlayerTextDrawAlignment(playerid, oxtarget[playerid][0], 1);
    PlayerTextDrawColor(playerid, oxtarget[playerid][0], -1811885057);
    PlayerTextDrawSetShadow(playerid, oxtarget[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget[playerid][0], 255);
    PlayerTextDrawFont(playerid, oxtarget[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, oxtarget[playerid][0], 1);

    oxtarget[playerid][1] = CreatePlayerTextDraw(playerid, 316.000, 182.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget[playerid][1], 13.000, 10.000);
    PlayerTextDrawAlignment(playerid, oxtarget[playerid][1], 1);
    PlayerTextDrawColor(playerid, oxtarget[playerid][1], -1811885057);
    PlayerTextDrawSetShadow(playerid, oxtarget[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget[playerid][1], 255);
    PlayerTextDrawFont(playerid, oxtarget[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget[playerid][1], 1);

    oxtarget[playerid][2] = CreatePlayerTextDraw(playerid, 309.000, 182.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget[playerid][2], 13.000, 10.000);
    PlayerTextDrawAlignment(playerid, oxtarget[playerid][2], 1);
    PlayerTextDrawColor(playerid, oxtarget[playerid][2], -1811885057);
    PlayerTextDrawSetShadow(playerid, oxtarget[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget[playerid][2], 255);
    PlayerTextDrawFont(playerid, oxtarget[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget[playerid][2], 1);

    oxtarget[playerid][3] = CreatePlayerTextDraw(playerid, 314.000, 182.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget[playerid][3], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, oxtarget[playerid][3], 1);
    PlayerTextDrawColor(playerid, oxtarget[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, oxtarget[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget[playerid][3], 255);
    PlayerTextDrawFont(playerid, oxtarget[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget[playerid][3], 1);

    oxtarget[playerid][4] = CreatePlayerTextDraw(playerid, 316.000, 184.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, oxtarget[playerid][4], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, oxtarget[playerid][4], 1);
    PlayerTextDrawColor(playerid, oxtarget[playerid][4], -1724723969);
    PlayerTextDrawSetShadow(playerid, oxtarget[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget[playerid][4], 255);
    PlayerTextDrawFont(playerid, oxtarget[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget[playerid][4], 1);

    oxtarget[playerid][5] = CreatePlayerTextDraw(playerid, 329.000, 181.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, oxtarget[playerid][5], 2.000, 13.000);
    PlayerTextDrawAlignment(playerid, oxtarget[playerid][5], 1);
    PlayerTextDrawColor(playerid, oxtarget[playerid][5], -1724723969);
    PlayerTextDrawSetShadow(playerid, oxtarget[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget[playerid][5], 255);
    PlayerTextDrawFont(playerid, oxtarget[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget[playerid][5], 1);

    oxtarget[playerid][6] = CreatePlayerTextDraw(playerid, 331.000, 181.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, oxtarget[playerid][6], 36.000, 13.000);
    PlayerTextDrawAlignment(playerid, oxtarget[playerid][6], 1);
    PlayerTextDrawColor(playerid, oxtarget[playerid][6], -2139062017);
    PlayerTextDrawSetShadow(playerid, oxtarget[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, oxtarget[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, oxtarget[playerid][6], 255);
    PlayerTextDrawFont(playerid, oxtarget[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, oxtarget[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, oxtarget[playerid][6], 1);

    oxtarget[playerid][7] = CreatePlayerTextDraw(playerid, 333.000, 183.000, "Aksi");
    PlayerTextDrawLetterSize(playerid, oxtarget[playerid][7], 0.200, 0.799);
    PlayerTextDrawAlignment(playerid, oxtarget[playerid][7], 1);
    PlayerTextDrawColor(playerid, oxtarget[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, oxtarget[playerid][7], 1);
    PlayerTextDrawSetOutline(playerid, oxtarget[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, oxtarget[playerid][7], -2139062017);
    PlayerTextDrawFont(playerid, oxtarget[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, oxtarget[playerid][7], 1);

    Nexoduswithaufa[playerid][0] = CreatePlayerTextDraw(playerid, 250.000, 412.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][0], 28.000, 30.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][0], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][0], -566747393);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][0], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][0], 1);

    Nexoduswithaufa[playerid][1] = CreatePlayerTextDraw(playerid, 280.000, 412.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][1], 28.000, 30.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][1], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][1], 204068863);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][1], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][1], 1);

    Nexoduswithaufa[playerid][2] = CreatePlayerTextDraw(playerid, 310.000, 412.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][2], 28.000, 30.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][2], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][2], -412154881);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][2], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][2], 1);

    Nexoduswithaufa[playerid][3] = CreatePlayerTextDraw(playerid, 340.000, 412.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][3], 28.000, 30.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][3], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][3], 10878463);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][3], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][3], 1);

    Nexoduswithaufa[playerid][4] = CreatePlayerTextDraw(playerid, 370.000, 412.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][4], 28.000, 30.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][4], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][4], -1255260417);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][4], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][4], 1);

    Nexoduswithaufa[playerid][5] = CreatePlayerTextDraw(playerid, 251.000, 441.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][5], 26.000, -28.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][5], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][5], -8772609);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][5], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][5], 1);

    Nexoduswithaufa[playerid][6] = CreatePlayerTextDraw(playerid, 281.000, 441.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][6], 26.000, -28.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][6], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][6], 153745919);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][6], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][6], 1);

    Nexoduswithaufa[playerid][7] = CreatePlayerTextDraw(playerid, 311.000, 441.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][7], 26.000, -28.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][7], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][7], -6553345);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][7], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][7], 1);

    Nexoduswithaufa[playerid][8] = CreatePlayerTextDraw(playerid, 341.000, 441.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][8], 26.000, -28.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][8], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][8], 13828095);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][8], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][8], 1);

    Nexoduswithaufa[playerid][9] = CreatePlayerTextDraw(playerid, 371.000, 441.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][9], 26.000, -28.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][9], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][9], -298567169);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][9], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][9], 1);

    Nexoduswithaufa[playerid][10] = CreatePlayerTextDraw(playerid, 256.000, 416.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][10], 9.000, 9.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][10], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][10], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][10], 1);

    Nexoduswithaufa[playerid][11] = CreatePlayerTextDraw(playerid, 263.000, 416.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][11], 9.000, 9.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][11], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][11], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][11], 1);

    Nexoduswithaufa[playerid][12] = CreatePlayerTextDraw(playerid, 259.000, 419.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][12], 9.000, 9.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][12], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][12], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][12], 1);

    Nexoduswithaufa[playerid][13] = CreatePlayerTextDraw(playerid, 264.000, 418.000, "/");
    PlayerTextDrawLetterSize(playerid, Nexoduswithaufa[playerid][13], 0.398, 1.498);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][13], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][13], 1);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][13], 1);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][13], -1);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][13], 1);

    Nexoduswithaufa[playerid][14] = CreatePlayerTextDraw(playerid, 264.000, 418.000, "/");
    PlayerTextDrawLetterSize(playerid, Nexoduswithaufa[playerid][14], -0.428, 1.500);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][14], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][14], 1);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][14], 1);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][14], -1);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][14], 1);

    Nexoduswithaufa[playerid][15] = CreatePlayerTextDraw(playerid, 260.000, 429.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][15], 8.000, 8.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][15], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][15], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][15], 1);

    Nexoduswithaufa[playerid][16] = CreatePlayerTextDraw(playerid, 260.000, 424.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][16], 9.000, 9.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][16], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][16], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][16], 1);

    Nexoduswithaufa[playerid][17] = CreatePlayerTextDraw(playerid, 287.000, 418.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][17], 14.000, 8.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][17], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][17], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][17], 1);

    Nexoduswithaufa[playerid][18] = CreatePlayerTextDraw(playerid, 280.000, 421.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][18], 28.000, 20.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][18], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][18], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][18], 1);

    Nexoduswithaufa[playerid][19] = CreatePlayerTextDraw(playerid, 285.000, 426.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][19], 18.000, 5.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][19], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][19], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][19], 1);

    Nexoduswithaufa[playerid][20] = CreatePlayerTextDraw(playerid, 312.000, 415.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][20], 24.000, 10.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][20], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][20], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][20], 1);

    Nexoduswithaufa[playerid][21] = CreatePlayerTextDraw(playerid, 316.000, 420.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][21], 16.000, 4.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][21], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][21], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][21], 1);

    Nexoduswithaufa[playerid][22] = CreatePlayerTextDraw(playerid, 316.000, 425.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][22], 16.000, 3.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][22], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][22], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][22], 1);

    Nexoduswithaufa[playerid][23] = CreatePlayerTextDraw(playerid, 316.000, 429.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][23], 16.000, 3.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][23], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][23], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][23], 1);

    Nexoduswithaufa[playerid][24] = CreatePlayerTextDraw(playerid, 312.000, 427.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][24], 24.000, 11.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][24], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][24], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][24], 1);

    Nexoduswithaufa[playerid][25] = CreatePlayerTextDraw(playerid, 318.000, 418.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][25], 3.000, 5.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][25], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][25], -21741569);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][25], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][25], 1);

    Nexoduswithaufa[playerid][26] = CreatePlayerTextDraw(playerid, 323.000, 419.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][26], 3.000, 5.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][26], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][26], -21741569);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][26], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][26], 1);

    Nexoduswithaufa[playerid][27] = CreatePlayerTextDraw(playerid, 327.000, 417.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][27], 3.000, 5.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][27], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][27], -21741569);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][27], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][27], 1);

    Nexoduswithaufa[playerid][28] = CreatePlayerTextDraw(playerid, 351.000, 416.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][28], 6.000, 14.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][28], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][28], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][28], 1);

    Nexoduswithaufa[playerid][29] = CreatePlayerTextDraw(playerid, 349.000, 425.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][29], 10.000, 13.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][29], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][29], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][29], 1);

    Nexoduswithaufa[playerid][30] = CreatePlayerTextDraw(playerid, 348.000, 419.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][30], 12.000, 22.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][30], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][30], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][30], 1);

    Nexoduswithaufa[playerid][31] = CreatePlayerTextDraw(playerid, 377.000, 415.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][31], 7.000, 22.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][31], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][31], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][31], 1);

    Nexoduswithaufa[playerid][32] = CreatePlayerTextDraw(playerid, 382.000, 415.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][32], 7.000, 22.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][32], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][32], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][32], 1);

    Nexoduswithaufa[playerid][33] = CreatePlayerTextDraw(playerid, 381.000, 426.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Nexoduswithaufa[playerid][33], 6.000, -2.000);
    PlayerTextDrawAlignment(playerid, Nexoduswithaufa[playerid][33], 1);
    PlayerTextDrawColor(playerid, Nexoduswithaufa[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, Nexoduswithaufa[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, Nexoduswithaufa[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, Nexoduswithaufa[playerid][33], 255);
    PlayerTextDrawFont(playerid, Nexoduswithaufa[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, Nexoduswithaufa[playerid][33], 1);

    //death
	AsteraDeath[playerid][0] = CreatePlayerTextDraw(playerid, 320.000000, -8.000000, "_");
	PlayerTextDrawFont(playerid, AsteraDeath[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, AsteraDeath[playerid][0], 1.891666, 54.849994);
	PlayerTextDrawTextSize(playerid, AsteraDeath[playerid][0], 298.500000, 916.500000);
	PlayerTextDrawSetOutline(playerid, AsteraDeath[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, AsteraDeath[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, AsteraDeath[playerid][0], 2);
	PlayerTextDrawColor(playerid, AsteraDeath[playerid][0], 255);
	PlayerTextDrawBackgroundColor(playerid, AsteraDeath[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, AsteraDeath[playerid][0], 10);
	PlayerTextDrawUseBox(playerid, AsteraDeath[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, AsteraDeath[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, AsteraDeath[playerid][0], 0);

	AsteraDeath[playerid][1] = CreatePlayerTextDraw(playerid, 320.000000, 306.000000, "Kamu Sedang Injury Dimohon Jangan Menggunakan ~b~/b~w~ Secara Berlebihan");
	PlayerTextDrawFont(playerid, AsteraDeath[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, AsteraDeath[playerid][1], 0.195833, 1.149999);
	PlayerTextDrawTextSize(playerid, AsteraDeath[playerid][1], 400.000000, 332.000000);
	PlayerTextDrawSetOutline(playerid, AsteraDeath[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, AsteraDeath[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, AsteraDeath[playerid][1], 2);
	PlayerTextDrawColor(playerid, AsteraDeath[playerid][1], -1);
	PlayerTextDrawBackgroundColor(playerid, AsteraDeath[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, AsteraDeath[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, AsteraDeath[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, AsteraDeath[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, AsteraDeath[playerid][1], 0);

	AsteraDeath[playerid][2] = CreatePlayerTextDraw(playerid, 320.000000, 318.000000, "Gunakan ~b~/teriak~w~ Agar Memberi SInyal Ke SAMD");
	PlayerTextDrawFont(playerid, AsteraDeath[playerid][2], 1);
	PlayerTextDrawLetterSize(playerid, AsteraDeath[playerid][2], 0.195833, 1.149999);
	PlayerTextDrawTextSize(playerid, AsteraDeath[playerid][2], 400.000000, 237.000000);
	PlayerTextDrawSetOutline(playerid, AsteraDeath[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, AsteraDeath[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, AsteraDeath[playerid][2], 2);
	PlayerTextDrawColor(playerid, AsteraDeath[playerid][2], -1);
	PlayerTextDrawBackgroundColor(playerid, AsteraDeath[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, AsteraDeath[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, AsteraDeath[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, AsteraDeath[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, AsteraDeath[playerid][2], 0);

	AsteraDeath[playerid][3] = CreatePlayerTextDraw(playerid, 320.000000, 330.000000, "Kamu Akan Kehabisan Darah Dalam Waktu");
	PlayerTextDrawFont(playerid, AsteraDeath[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, AsteraDeath[playerid][3], 0.195833, 1.149999);
	PlayerTextDrawTextSize(playerid, AsteraDeath[playerid][3], 400.000000, 237.000000);
	PlayerTextDrawSetOutline(playerid, AsteraDeath[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, AsteraDeath[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, AsteraDeath[playerid][3], 2);
	PlayerTextDrawColor(playerid, AsteraDeath[playerid][3], -1);
	PlayerTextDrawBackgroundColor(playerid, AsteraDeath[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, AsteraDeath[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, AsteraDeath[playerid][3], 0);
	PlayerTextDrawSetProportional(playerid, AsteraDeath[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, AsteraDeath[playerid][3], 0);

	AsteraDeath[playerid][4] = CreatePlayerTextDraw(playerid, 320.000000, 342.000000, "~r~300~w~ Detik");
	PlayerTextDrawFont(playerid, AsteraDeath[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, AsteraDeath[playerid][4], 0.250000, 1.399999);
	PlayerTextDrawTextSize(playerid, AsteraDeath[playerid][4], 400.000000, 237.000000);
	PlayerTextDrawSetOutline(playerid, AsteraDeath[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, AsteraDeath[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, AsteraDeath[playerid][4], 2);
	PlayerTextDrawColor(playerid, AsteraDeath[playerid][4], -1);
	PlayerTextDrawBackgroundColor(playerid, AsteraDeath[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, AsteraDeath[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, AsteraDeath[playerid][4], 0);
	PlayerTextDrawSetProportional(playerid, AsteraDeath[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, AsteraDeath[playerid][4], 0);

}