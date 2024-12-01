#include <YSI\y_hooks>
// ================================== [RESEPSIONIS] =================================
stock ShowResepsionisMenu(playerid, const string:text1[], const string:text2[])
{
    for(new i = 0; i < 9; i++){
    PlayerTextDrawShow(playerid, menu_reseptionis[playerid][i]);
    }
    PlayerTextDrawSetString(playerid, menu_reseptionis[playerid][6], text1);
    PlayerTextDrawSetString(playerid, menu_reseptionis[playerid][7], text2);
    PlayerTextDrawShow(playerid, Aksi_1[playerid]);
    PlayerTextDrawShow(playerid, Aksi_2[playerid]);
    PlayerTextDrawShow(playerid, r_close[playerid]);
    SelectTextDraw(playerid, -1);
    return 1;
}

stock HideResepsionisMenu(playerid)
{
    for(new i = 0; i < 9; i++)
    {
        PlayerTextDrawHide(playerid, menu_reseptionis[playerid][i]);
        PlayerTextDrawHide(playerid, Aksi_1[playerid]);
        PlayerTextDrawHide(playerid, Aksi_2[playerid]);
        PlayerTextDrawHide(playerid, r_close[playerid]);
        CancelSelectTextDraw(playerid);
    }
    return 1;
}
stock ResepsionisStatment(playerid)
{
    if(IsPlayerInRangeOfPoint(playerid, 1.0, 1804.354125,-1877.937622,13.581678))
    {
        ShowResepsionisMenu(playerid, "Ambil bansos", "Menyewa kendaraan");
    }
}
//  Mata TD Function
enum oxEnum {
    STREAMER_TAG_CP: oxResepsionis,
    STREAMER_TAG_CP: oxBalkot
}
new oxPlayer[MAX_PLAYERS][oxEnum];

Deleteoxtarget(playerid)
{
    if(IsValidDynamicCP(oxPlayer[playerid][oxResepsionis]))
    {
        DestroyDynamicCP(oxPlayer[playerid][oxResepsionis]);
        oxPlayer[playerid][oxResepsionis] = STREAMER_TAG_CP: -1;
    }
    else if(IsValidDynamicCP(oxPlayer[playerid][oxBalkot]))
    {
        DestroyDynamicCP(oxPlayer[playerid][oxBalkot]);
        oxPlayer[playerid][oxBalkot] = STREAMER_TAG_CP: -1;
    }
}

stock Refreshoxtarget(playerid)
{
    Deleteoxtarget(playerid);
    oxPlayer[playerid][oxResepsionis] = CreateDynamicCP(1804.354125,-1877.937622,13.581678, 1.0, -1, -1, playerid, 5.0);
    oxPlayer[playerid][oxBalkot] = CreateDynamicCP(1479.9692,-1802.0327,3158.0298, 1.0, -1, -1, playerid, 5.0);
}

stock oxEnter(playerid, checkpointid)
{
    if(checkpointid == oxPlayer[playerid][oxResepsionis])
    {
        PlayerPlaySound(playerid, 5202, 0,0,0);
        ShowMataTarget(playerid);
    }
    else if(checkpointid == oxPlayer[playerid][oxBalkot])
    {
        PlayerPlaySound(playerid, 5202, 0,0,0);
        ShowMataTarget(playerid);
    }
}

new Float:Resepsicord[][3] = 
{
    {1804.354125, -1877.937622, 13.581678}, //Resepsionis station
    {2749.5659, -2398.2783, 13.6454}, //Ambilsp3
    {1479.9692, -1802.0327, 3158.0298}, //BalaiKota
    {1550.764404, -2173.071289, 13.557748} //Isurance
};

stock MataTargetClick(playerid, PlayerText:playertextid)
{
    if(playertextid == MataBtn[playerid])
    {
        for(new i; i < sizeof(Resepsicord); i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, 1.5, Resepsicord[i][0], Resepsicord[i][1], Resepsicord[i][2]))
            {
                PlayerPlaySound(playerid, 5202, 0,0,0);
                ShowMataAksi(playerid, "Resepsionis");
            }
        }
        if(IsPlayerInRangeOfPoint(playerid, 1.5, 1807.3911,-1872.2329,13.6462))
        {
            PlayerPlaySound(playerid, 5202, 0,0,0);
            ShowMataAksi(playerid, "Ambil bansos");
        }
    } 
    else if(playertextid == MataaksiBtn[playerid])
    {
        if(IsPlayerInRangeOfPoint(playerid, 2.0, 1804.354125,-1877.937622,13.581678)) //resepsionis stasiun
        {
            HideMataTarget(playerid);
            PlayerPlaySound(playerid, 5202, 0,0,0);
            ResepsionisStatment(playerid); 
        }
        else if(IsPlayerInRangeOfPoint(playerid, 1.5, 1479.9692, -1802.0327, 3158.0298)) //balkot
        {
            HideMataTarget(playerid);
            CancelSelectTextDraw(playerid);
            ShowPlayerDialog(playerid, DIALOG_PEMERINTAH, DIALOG_STYLE_LIST, "{FFFF00}Resepsionis", "\
                Membuat ID Card\nMenjual Rumah\nMenjual Bisnis", "Pilih", "Batal");
        }
    } 
    else if(playertextid == Aksi_1[playerid]) //Resepsionis menu
    {
        HideResepsionisMenu(playerid);
        PlayerPlaySound(playerid, 5202, 0,0,0);
        callcmd::starterpack(playerid);
    }
    else if(playertextid == Aksi_2[playerid])
    {
        HideResepsionisMenu(playerid);

        new str[1024];
        format(str, sizeof(str), "Kendaraan\tHarga\n"WHITE_E"%s\t"LG_E"$50 / one days\n%s\t"LG_E"$200 / one days",
        GetVehicleModelName(481), 
        GetVehicleModelName(462));
        ShowPlayerDialog(playerid, DIALOG_RENT_BIKE, DIALOG_STYLE_TABLIST_HEADERS, "{FFFF00}Penyewaan Kendaraan", str, "Rent", "Close");
    }
    else if(playertextid == r_close[playerid])
    {
        HideResepsionisMenu(playerid);
        PlayerPlaySound(playerid, 5202, 0,0,0);
        CancelSelectTextDraw(playerid);
    }
    return 1;
}


stock ShowMataTarget(playerid)
{
    PlayerTextDrawShow(playerid, MataTD[playerid][0]); 
    PlayerTextDrawShow(playerid, MataBtn[playerid]);
    PlayerTextDrawShow(playerid, MataTD[playerid][1]);
    SelectTextDraw(playerid, COLOR_YELLOW);
}

stock ShowMataAksi(playerid, text[])
{
    PlayerTextDrawShow(playerid, MataaksiBtn[playerid]);
    PlayerTextDrawShow(playerid, MataAksi[playerid]);
    PlayerTextDrawShow(playerid, MataText[playerid]);
    PlayerTextDrawSetString(playerid, MataText[playerid], text);
}

stock HideMataTarget(playerid)
{
    HideMataAksi(playerid);
    for(new i = 0; i < 2; i++){
    PlayerTextDrawHide(playerid, MataTD[playerid][i]);}
    PlayerTextDrawHide(playerid, MataBtn[playerid]);
    return 1;
}

stock HideMataAksi(playerid)
{
    PlayerTextDrawHide(playerid, MataaksiBtn[playerid]);
    PlayerTextDrawHide(playerid, MataAksi[playerid]);
    PlayerTextDrawHide(playerid, MataText[playerid]);
    return 1;
}

stock oxTargetShow(playerid) {
    for(new i = 0; i < 5; i++)
    {
        PlayerTextDrawShow(playerid, oxtarget1[playerid][i]);
        CancelSelectTextDraw(playerid);
    }
}

stock oxTargetHide(playerid) {
    for(new i = 0; i < 5; i++)
    {
        PlayerTextDrawHide(playerid, oxtarget1[playerid][i]);
        CancelSelectTextDraw(playerid);
    }
}

stock oxTargetNew(playerid) {
    oxTargetHide(playerid);
    PlayerTextDrawShow(playerid, oxtarget[playerid][0]);
    PlayerTextDrawShow(playerid, oxtarget[playerid][1]);
    PlayerTextDrawShow(playerid, oxtarget[playerid][2]);
    PlayerTextDrawShow(playerid, oxtarget[playerid][3]);
    PlayerTextDrawShow(playerid, oxtarget[playerid][4]);
    SelectTextDraw(playerid, COLOR_GREY);
}

stock HideAllTarget(playerid) {
    for(new i = 0; i < 8; i++)
    {
        PlayerTextDrawHide(playerid, oxtarget[playerid][i]);
        CancelSelectTextDraw(playerid);
    }
}