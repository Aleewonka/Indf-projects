#include <YSI\y_hooks>

new PlayerText:PonselUi[MAX_PLAYERS][51];
new PlayerText: Jobst[MAX_PLAYERS];
new PlayerText: Spoty[MAX_PLAYERS];
new PlayerText: Maps[MAX_PLAYERS];
new PlayerText: Mbank[MAX_PLAYERS];
new PlayerText: GoJek[MAX_PLAYERS];
new PlayerText: AirDrop[MAX_PLAYERS];
new PlayerText: Invoice[MAX_PLAYERS];
new PlayerText: Twt[MAX_PLAYERS];
new PlayerText: WA[MAX_PLAYERS];
new PlayerText: Telpon[MAX_PLAYERS];
new PlayerText: Kontak[MAX_PLAYERS];
new PlayerText: Camera[MAX_PLAYERS];
new PlayerText: TurnOff[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    CreatePonselTd(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyUiPonsel(playerid);
    return 1;
}

//Menampilkan Td Ponsel
FUNC::ShowUiPonsel(playerid)
{
    for(new i = 0; i < 51; i++)
    {
        if(i == 38)
        {
            break;
        }
        PlayerTextDrawShow(playerid, PonselUi[playerid][i]);
    }
    PlayerTextDrawShow(playerid, Jobst[playerid]);
    PlayerTextDrawShow(playerid, Spoty[playerid]);
    PlayerTextDrawShow(playerid, Maps[playerid]);
    PlayerTextDrawShow(playerid, Mbank[playerid]);
    PlayerTextDrawShow(playerid, GoJek[playerid]);
    PlayerTextDrawShow(playerid, AirDrop[playerid]);
    PlayerTextDrawShow(playerid, Invoice[playerid]);
    PlayerTextDrawShow(playerid, Twt[playerid]);
    PlayerTextDrawShow(playerid, WA[playerid]);
    PlayerTextDrawShow(playerid, Telpon[playerid]);
    PlayerTextDrawShow(playerid, Kontak[playerid]);
    PlayerTextDrawShow(playerid, Camera[playerid]);
    PlayerTextDrawShow(playerid, TurnOff[playerid]);
    for(new i = 38; i < 51; i++)
    {
         PlayerTextDrawShow(playerid, PonselUi[playerid][i]);
    }
    return 1;
}

FUNC::HideUiPonsel(playerid)
{
    for(new i = 0; i < 51; i++)
    {
        PlayerTextDrawHide(playerid, PonselUi[playerid][i]);
    }
    PlayerTextDrawHide(playerid, Jobst[playerid]);
    PlayerTextDrawHide(playerid, Spoty[playerid]);
    PlayerTextDrawHide(playerid, Maps[playerid]);
    PlayerTextDrawHide(playerid, Mbank[playerid]);
    PlayerTextDrawHide(playerid, GoJek[playerid]);
    PlayerTextDrawHide(playerid, AirDrop[playerid]);
    PlayerTextDrawHide(playerid, Invoice[playerid]);
    PlayerTextDrawHide(playerid, Twt[playerid]);
    PlayerTextDrawHide(playerid, WA[playerid]);
    PlayerTextDrawHide(playerid, Telpon[playerid]);
    PlayerTextDrawHide(playerid, Kontak[playerid]);
    PlayerTextDrawHide(playerid, Camera[playerid]);
    PlayerTextDrawHide(playerid, TurnOff[playerid]);
    return 1;
}

FUNC::DestroyUiPonsel(playerid)
{
    for(new i = 0; i < 51; i++)
    {
        PlayerTextDrawDestroy(playerid, PonselUi[playerid][i]);
    }
    PlayerTextDrawDestroy(playerid, Jobst[playerid]);
    PlayerTextDrawDestroy(playerid, Spoty[playerid]);
    PlayerTextDrawDestroy(playerid, Maps[playerid]);
    PlayerTextDrawDestroy(playerid, Mbank[playerid]);
    PlayerTextDrawDestroy(playerid, GoJek[playerid]);
    PlayerTextDrawDestroy(playerid, AirDrop[playerid]);
    PlayerTextDrawDestroy(playerid, Invoice[playerid]);
    PlayerTextDrawDestroy(playerid, Twt[playerid]);
    PlayerTextDrawDestroy(playerid, WA[playerid]);
    PlayerTextDrawDestroy(playerid, Telpon[playerid]);
    PlayerTextDrawDestroy(playerid, Kontak[playerid]);
    PlayerTextDrawDestroy(playerid, Camera[playerid]);
    PlayerTextDrawDestroy(playerid, TurnOff[playerid]);
}

stock CreatePonselTd(playerid)
{
    PonselUi[playerid][0] = CreatePlayerTextDraw(playerid, 426.000, 161.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][0], 35.000, 35.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][0], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][0], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][0], 1);

    PonselUi[playerid][1] = CreatePlayerTextDraw(playerid, 504.000, 161.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][1], 35.000, 35.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][1], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][1], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][1], 1);

    PonselUi[playerid][2] = CreatePlayerTextDraw(playerid, 444.000, 166.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][2], 79.000, 6.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][2], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][2], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][2], 1);

    PonselUi[playerid][3] = CreatePlayerTextDraw(playerid, 426.000, 361.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][3], 35.000, 35.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][3], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][3], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][3], 1);

    PonselUi[playerid][4] = CreatePlayerTextDraw(playerid, 504.000, 361.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][4], 35.000, 35.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][4], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][4], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][4], 1);

    PonselUi[playerid][5] = CreatePlayerTextDraw(playerid, 444.000, 384.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][5], 79.000, 6.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][5], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][5], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][5], 1);

    PonselUi[playerid][6] = CreatePlayerTextDraw(playerid, 444.000, 171.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][6], 79.000, 214.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][6], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][6], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][6], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][6], 1);

    PonselUi[playerid][7] = CreatePlayerTextDraw(playerid, 431.000, 178.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][7], 13.000, 201.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][7], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][7], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][7], 1);

    PonselUi[playerid][8] = CreatePlayerTextDraw(playerid, 521.000, 178.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][8], 13.000, 200.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][8], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][8], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][8], 1);

    PonselUi[playerid][9] = CreatePlayerTextDraw(playerid, 428.000, 163.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][9], 35.000, 35.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][9], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][9], 977225727);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][9], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][9], 1);

    PonselUi[playerid][10] = CreatePlayerTextDraw(playerid, 502.000, 163.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][10], 35.000, 35.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][10], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][10], 977225727);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][10], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][10], 1);

    PonselUi[playerid][11] = CreatePlayerTextDraw(playerid, 444.000, 169.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][11], 77.000, 6.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][11], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][11], 977225727);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][11], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][11], 1);

    PonselUi[playerid][12] = CreatePlayerTextDraw(playerid, 428.000, 359.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][12], 35.000, 35.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][12], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][12], 977225727);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][12], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][12], 1);

    PonselUi[playerid][13] = CreatePlayerTextDraw(playerid, 502.000, 359.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][13], 35.000, 35.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][13], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][13], 977225727);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][13], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][13], 1);

    PonselUi[playerid][14] = CreatePlayerTextDraw(playerid, 444.000, 382.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][14], 77.000, 6.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][14], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][14], 977225727);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][14], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][14], 1);

    PonselUi[playerid][15] = CreatePlayerTextDraw(playerid, 444.000, 173.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][15], 77.000, 210.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][15], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][15], 977225727);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][15], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][15], 1);

    PonselUi[playerid][16] = CreatePlayerTextDraw(playerid, 434.000, 180.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][16], 13.000, 197.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][16], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][16], 977225727);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][16], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][16], 1);

    PonselUi[playerid][17] = CreatePlayerTextDraw(playerid, 518.000, 180.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][17], 13.000, 197.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][17], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][17], 977225727);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][17], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][17], 1);

    PonselUi[playerid][18] = CreatePlayerTextDraw(playerid, 458.000, 169.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][18], 15.000, 15.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][18], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][18], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][18], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][18], 1);

    PonselUi[playerid][19] = CreatePlayerTextDraw(playerid, 494.000, 169.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][19], 15.000, 15.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][19], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][19], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][19], 1);

    PonselUi[playerid][20] = CreatePlayerTextDraw(playerid, 466.000, 171.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][20], 35.000, 4.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][20], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][20], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][20], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][20], 1);

    PonselUi[playerid][21] = CreatePlayerTextDraw(playerid, 466.000, 178.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][21], 35.000, 4.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][21], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][21], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][21], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][21], 1);

    PonselUi[playerid][22] = CreatePlayerTextDraw(playerid, 466.000, 175.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][22], 35.000, 4.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][22], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][22], 255);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][22], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][22], 1);

    PonselUi[playerid][23] = CreatePlayerTextDraw(playerid, 440.000, 172.000, "00:00");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][23], 0.129, 0.999);
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][23], 454.000, -23.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][23], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][23], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][23], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][23], 1);

    PonselUi[playerid][24] = CreatePlayerTextDraw(playerid, 523.000, 174.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][24], 1.000, 7.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][24], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][24], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][24], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][24], 1);

    PonselUi[playerid][25] = CreatePlayerTextDraw(playerid, 519.000, 177.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][25], 1.000, 4.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][25], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][25], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][25], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][25], 1);

    PonselUi[playerid][26] = CreatePlayerTextDraw(playerid, 521.000, 176.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][26], 1.000, 5.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][26], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][26], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][26], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][26], 1);

    PonselUi[playerid][27] = CreatePlayerTextDraw(playerid, 449.000, 227.000, "Jobs");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][27], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][27], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][27], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][27], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][27], 1);

    PonselUi[playerid][28] = CreatePlayerTextDraw(playerid, 474.000, 227.000, "Spotyfy");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][28], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][28], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][28], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][28], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][28], 1);

    PonselUi[playerid][29] = CreatePlayerTextDraw(playerid, 505.000, 227.000, "Maps");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][29], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][29], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][29], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][29], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][29], 1);

    PonselUi[playerid][30] = CreatePlayerTextDraw(playerid, 447.000, 260.000, "Mbank");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][30], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][30], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][30], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][30], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][30], 1);

    PonselUi[playerid][31] = CreatePlayerTextDraw(playerid, 475.000, 260.000, "GoJek");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][31], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][31], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][31], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][31], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][31], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][31], 0);

    PonselUi[playerid][32] = CreatePlayerTextDraw(playerid, 501.000, 260.000, "AirDrop");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][32], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][32], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][32], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][32], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][32], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][32], 0);

    PonselUi[playerid][33] = CreatePlayerTextDraw(playerid, 445.000, 294.000, "Invoice");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][33], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][33], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][33], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][33], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][33], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][33], 0);

    PonselUi[playerid][34] = CreatePlayerTextDraw(playerid, 476.000, 294.000, "Twitt");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][34], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][34], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][34], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][34], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][34], 0);

    PonselUi[playerid][35] = CreatePlayerTextDraw(playerid, 499.000, 294.000, "WhatsApp");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][35], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][35], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][35], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][35], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][35], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][35], 0);

    PonselUi[playerid][36] = CreatePlayerTextDraw(playerid, 445.000, 366.000, "Telpon");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][36], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][36], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][36], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][36], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][36], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][36], 0);

    PonselUi[playerid][37] = CreatePlayerTextDraw(playerid, 474.000, 366.000, "Kontak");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][37], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][37], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][37], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][37], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][37], 0);

    PonselUi[playerid][38] = CreatePlayerTextDraw(playerid, 502.000, 366.000, "Camera");
    PlayerTextDrawLetterSize(playerid, PonselUi[playerid][38], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][38], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][38], -286331137);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][38], 150);
    PlayerTextDrawFont(playerid, PonselUi[playerid][38], 1);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][38], 0);

    PonselUi[playerid][39] = CreatePlayerTextDraw(playerid, 449.000, 211.000, "HUD:radar_bulldozer");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][39], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][39], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][39], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][39], 1);

    PonselUi[playerid][40] = CreatePlayerTextDraw(playerid, 477.000, 211.000, "HUD:radar_dateDisco");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][40], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][40], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][40], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][40], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][40], 1);

    PonselUi[playerid][41] = CreatePlayerTextDraw(playerid, 505.000, 211.000, "HUD:radar_waypoint");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][41], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][41], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][41], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][41], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][41], 1);

    PonselUi[playerid][42] = CreatePlayerTextDraw(playerid, 449.000, 245.000, "HUD:radar_cash");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][42], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][42], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][42], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][42], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][42], 1);

    PonselUi[playerid][43] = CreatePlayerTextDraw(playerid, 477.000, 245.000, "HUD:radar_light");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][43], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][43], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][43], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][43], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][43], 1);

    PonselUi[playerid][44] = CreatePlayerTextDraw(playerid, 505.000, 245.000, "HUD:radar_gangG");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][44], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][44], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][44], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][44], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][44], 1);

    PonselUi[playerid][45] = CreatePlayerTextDraw(playerid, 449.000, 280.000, "HUD:radar_saveGame");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][45], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][45], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][45], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][45], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][45], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][45], 1);

    PonselUi[playerid][46] = CreatePlayerTextDraw(playerid, 477.000, 279.000, "HUD:radar_THETRUTH");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][46], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][46], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][46], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][46], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][46], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][46], 1);

    PonselUi[playerid][47] = CreatePlayerTextDraw(playerid, 507.000, 279.000, "HUD:radar_spray");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][47], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][47], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][47], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][47], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][47], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][47], 1);

    PonselUi[playerid][48] = CreatePlayerTextDraw(playerid, 450.000, 350.000, "HUD:radar_CRASH1");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][48], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][48], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][48], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][48], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][48], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][48], 1);

    PonselUi[playerid][49] = CreatePlayerTextDraw(playerid, 477.000, 349.000, "HUD:radar_CATALINAPINK");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][49], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][49], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][49], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][49], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][49], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][49], 1);

    PonselUi[playerid][50] = CreatePlayerTextDraw(playerid, 505.000, 350.000, "HUD:radar_CJ");
    PlayerTextDrawTextSize(playerid, PonselUi[playerid][50], 10.000, 10.000);
    PlayerTextDrawAlignment(playerid, PonselUi[playerid][50], 1);
    PlayerTextDrawColor(playerid, PonselUi[playerid][50], -1);
    PlayerTextDrawSetShadow(playerid, PonselUi[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, PonselUi[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, PonselUi[playerid][50], 255);
    PlayerTextDrawFont(playerid, PonselUi[playerid][50], 4);
    PlayerTextDrawSetProportional(playerid, PonselUi[playerid][50], 1);
    //######################################################################################
    Jobst[playerid] = CreatePlayerTextDraw(playerid, 445.000, 207.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Jobst[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, Jobst[playerid], 1);
    PlayerTextDrawColor(playerid, Jobst[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, Jobst[playerid], 0);
    PlayerTextDrawSetOutline(playerid, Jobst[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, Jobst[playerid], 255);
    PlayerTextDrawFont(playerid, Jobst[playerid], 4);
    PlayerTextDrawSetProportional(playerid, Jobst[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Jobst[playerid], 1);

    Spoty[playerid] = CreatePlayerTextDraw(playerid, 473.000, 207.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Spoty[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, Spoty[playerid], 1);
    PlayerTextDrawColor(playerid, Spoty[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, Spoty[playerid], 0);
    PlayerTextDrawSetOutline(playerid, Spoty[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, Spoty[playerid], 255);
    PlayerTextDrawFont(playerid, Spoty[playerid], 4);
    PlayerTextDrawSetProportional(playerid, Spoty[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Spoty[playerid], 1);

    Maps[playerid] = CreatePlayerTextDraw(playerid, 501.000, 207.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Maps[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, Maps[playerid], 1);
    PlayerTextDrawColor(playerid, Maps[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, Maps[playerid], 0);
    PlayerTextDrawSetOutline(playerid, Maps[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, Maps[playerid], 255);
    PlayerTextDrawFont(playerid, Maps[playerid], 4);
    PlayerTextDrawSetProportional(playerid, Maps[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Maps[playerid], 1);

    Mbank[playerid] = CreatePlayerTextDraw(playerid, 445.000, 241.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Mbank[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, Mbank[playerid], 1);
    PlayerTextDrawColor(playerid, Mbank[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, Mbank[playerid], 0);
    PlayerTextDrawSetOutline(playerid, Mbank[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, Mbank[playerid], 255);
    PlayerTextDrawFont(playerid, Mbank[playerid], 4);
    PlayerTextDrawSetProportional(playerid, Mbank[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Mbank[playerid], 1);

    GoJek[playerid] = CreatePlayerTextDraw(playerid, 473.000, 241.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, GoJek[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, GoJek[playerid], 1);
    PlayerTextDrawColor(playerid, GoJek[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, GoJek[playerid], 0);
    PlayerTextDrawSetOutline(playerid, GoJek[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, GoJek[playerid], 255);
    PlayerTextDrawFont(playerid, GoJek[playerid], 4);
    PlayerTextDrawSetProportional(playerid, GoJek[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, GoJek[playerid], 1);

    AirDrop[playerid] = CreatePlayerTextDraw(playerid, 501.000, 241.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, AirDrop[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, AirDrop[playerid], 1);
    PlayerTextDrawColor(playerid, AirDrop[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, AirDrop[playerid], 0);
    PlayerTextDrawSetOutline(playerid, AirDrop[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, AirDrop[playerid], 255);
    PlayerTextDrawFont(playerid, AirDrop[playerid], 4);
    PlayerTextDrawSetProportional(playerid, AirDrop[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, AirDrop[playerid], 1);

    Invoice[playerid] = CreatePlayerTextDraw(playerid, 445.000, 275.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Invoice[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, Invoice[playerid], 1);
    PlayerTextDrawColor(playerid, Invoice[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, Invoice[playerid], 0);
    PlayerTextDrawSetOutline(playerid, Invoice[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, Invoice[playerid], 255);
    PlayerTextDrawFont(playerid, Invoice[playerid], 4);
    PlayerTextDrawSetProportional(playerid, Invoice[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Invoice[playerid], 1);

    Twt[playerid] = CreatePlayerTextDraw(playerid, 473.000, 275.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Twt[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, Twt[playerid], 1);
    PlayerTextDrawColor(playerid, Twt[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, Twt[playerid], 0);
    PlayerTextDrawSetOutline(playerid, Twt[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, Twt[playerid], 255);
    PlayerTextDrawFont(playerid, Twt[playerid], 4);
    PlayerTextDrawSetProportional(playerid, Twt[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Twt[playerid], 1);

    WA[playerid] = CreatePlayerTextDraw(playerid, 501.000, 275.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, WA[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, WA[playerid], 1);
    PlayerTextDrawColor(playerid, WA[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, WA[playerid], 0);
    PlayerTextDrawSetOutline(playerid, WA[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, WA[playerid], 255);
    PlayerTextDrawFont(playerid, WA[playerid], 4);
    PlayerTextDrawSetProportional(playerid, WA[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, WA[playerid], 1);

    Telpon[playerid] = CreatePlayerTextDraw(playerid, 445.000, 346.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Telpon[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, Telpon[playerid], 1);
    PlayerTextDrawColor(playerid, Telpon[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, Telpon[playerid], 0);
    PlayerTextDrawSetOutline(playerid, Telpon[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, Telpon[playerid], 255);
    PlayerTextDrawFont(playerid, Telpon[playerid], 4);
    PlayerTextDrawSetProportional(playerid, Telpon[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Telpon[playerid], 1);

    Kontak[playerid] = CreatePlayerTextDraw(playerid, 473.000, 346.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Kontak[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, Kontak[playerid], 1);
    PlayerTextDrawColor(playerid, Kontak[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, Kontak[playerid], 0);
    PlayerTextDrawSetOutline(playerid, Kontak[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, Kontak[playerid], 255);
    PlayerTextDrawFont(playerid, Kontak[playerid], 4);
    PlayerTextDrawSetProportional(playerid, Kontak[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Kontak[playerid], 1);

    Camera[playerid] = CreatePlayerTextDraw(playerid, 501.000, 346.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, Camera[playerid], 19.000, 19.000);
    PlayerTextDrawAlignment(playerid, Camera[playerid], 1);
    PlayerTextDrawColor(playerid, Camera[playerid], 1338811391);
    PlayerTextDrawSetShadow(playerid, Camera[playerid], 0);
    PlayerTextDrawSetOutline(playerid, Camera[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, Camera[playerid], 255);
    PlayerTextDrawFont(playerid, Camera[playerid], 4);
    PlayerTextDrawSetProportional(playerid, Camera[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, Camera[playerid], 1);

    TurnOff[playerid] = CreatePlayerTextDraw(playerid, 446.000, 380.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, TurnOff[playerid], 73.000, 5.000);
    PlayerTextDrawAlignment(playerid, TurnOff[playerid], 1);
    PlayerTextDrawColor(playerid, TurnOff[playerid], -286331137);
    PlayerTextDrawSetShadow(playerid, TurnOff[playerid], 0);
    PlayerTextDrawSetOutline(playerid, TurnOff[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, TurnOff[playerid], 255);
    PlayerTextDrawFont(playerid, TurnOff[playerid], 4);
    PlayerTextDrawSetProportional(playerid, TurnOff[playerid], 1);
    PlayerTextDrawSetSelectable(playerid, TurnOff[playerid], 1);
}

